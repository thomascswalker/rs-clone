using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEditor;

public class Tile
{
    public bool mWalkable;
    public Vector3 mPosition;

    public int gCost;
    public int hCost;

    public int gridX;
    public int gridY;

    public Tile parent;

    public Tile(bool walkable, Vector3 position, int x, int y)
    {
        mWalkable = walkable;
        mPosition = position;
        gridX = x;
        gridY = y;
    }

    public int fCost()
    {
        return gCost + hCost;
    }
}

public class Wall
{
    public Vector3 mPosition;
    public bool[] mWalkable = new bool[4];
    public Vector3[] mBounds = new Vector3[4];

    public int gridX;
    public int gridY;

    public Wall(bool[] walkable, Vector3[] bounds, Vector3 position, int x, int y)
    {
        mWalkable = walkable;
        mBounds = bounds;
        mPosition = position;
        gridX = x;
        gridY = y;
    }
}


[CustomEditor(typeof(PathGrid))]
public class PathGridEditor : Editor
{
    public override void OnInspectorGUI()
    {
        DrawDefaultInspector();

        PathGrid script = (PathGrid)target;
        if (GUILayout.Button("Test"))
        {
            script.CreateTileGrid();
        }
    }
}

[ExecuteInEditMode]
public class PathGrid : MonoBehaviour
{
    public LayerMask mUnwalkableMask;
    public LayerMask mWallMask;
    public LayerMask mPillarMask;
    public Vector2 mGridWorldSize = new Vector2(20f, 20f);
    public float mNodeRadius = 0.5f;
    public float mWallRadius = 0.1f;
    public float mTileHeight = 0.1f;
    public float mWallHeight = 0.1f;
    public float mOpacity = 0.75f;

    public bool highlightPlayerTile = true;
    public bool showWalkable = true;
    public bool showBlocked = true;
    public bool showWalls = true;

    private Tile[,] mTileGrid;
    private Wall[,] mWallGrid;

    public List<Tile> path;

    float mNodeDiameter;
    int mGridSizeX, mGridSizeY;

    void Start()
    {
        mNodeDiameter = mNodeRadius * 2;

        mGridSizeX = Mathf.RoundToInt(mGridWorldSize.x / mNodeDiameter);
        mGridSizeY = Mathf.RoundToInt(mGridWorldSize.y / mNodeDiameter);

        CreateTileGrid();
        CreateWallGrid();
    }

    public void CreateTileGrid()
    {
        mTileGrid = new Tile[mGridSizeX, mGridSizeY];
        Vector3 worldBottomLeft = transform.position - Vector3.right * mGridWorldSize.x / 2 - Vector3.forward * mGridWorldSize.y / 2;
        worldBottomLeft -= new Vector3(mNodeDiameter, 0, mNodeDiameter);
        for (int x = 0; x < mGridSizeX; x++)
        {
            for (int y = 0; y < mGridSizeY; y++)
            {
                Vector3 xOffset = Vector3.right * (x + mNodeDiameter + mNodeRadius);
                Vector3 yOffset = Vector3.forward * (y + mNodeDiameter + mNodeRadius);
                Vector3 worldPoint = worldBottomLeft + xOffset + yOffset;
                bool walkable = !(Physics.CheckSphere(worldPoint, mNodeRadius, mUnwalkableMask));

                mTileGrid[x, y] = new Tile(walkable, worldPoint, x, y);
            }
        }
    }

    public void CreateWallGrid()
    {
        mWallGrid = new Wall[mGridSizeX, mGridSizeY];
        Vector3 worldBottomLeft = transform.position - Vector3.right * mGridWorldSize.x / 2 - Vector3.forward * mGridWorldSize.y / 2;
        worldBottomLeft -= new Vector3(mNodeDiameter, 0, mNodeDiameter);
        for (int x = 0; x < mGridSizeX; x++)
        {
            for (int y = 0; y < mGridSizeY; y++)
            {
                Vector3 xOffset = Vector3.right * (x + mNodeDiameter + mNodeRadius);
                Vector3 yOffset = Vector3.forward * (y + mNodeDiameter + mNodeRadius);
                Vector3 worldPoint = worldBottomLeft + xOffset + yOffset;

                bool[] walkable = new bool[4];

                Vector3 northPoint = worldPoint + new Vector3(mNodeDiameter, 0, mNodeRadius);
                Vector3 westPoint = worldPoint + new Vector3(mNodeRadius, 0, 0);
                Vector3 eastPoint = worldPoint + new Vector3(mNodeRadius, 0, mNodeDiameter);
                Vector3 southPoint = worldPoint + new Vector3(0, 0, mNodeRadius);
                Vector3[] bounds = new Vector3[] {northPoint, westPoint, eastPoint, southPoint};

                walkable[0] = !(Physics.CheckSphere(northPoint, mWallRadius, mWallMask));
                walkable[1] = !(Physics.CheckSphere(westPoint, mWallRadius, mWallMask));
                walkable[2] = !(Physics.CheckSphere(eastPoint, mWallRadius, mWallMask));
                walkable[3] = !(Physics.CheckSphere(southPoint, mWallRadius, mWallMask));

                mWallGrid[x, y] = new Wall(walkable, bounds, worldPoint, x, y);
            }
        }
    }

    public List<Tile> GetNeighbors(Tile tile)
    {
        List<Tile> neighbors = new List<Tile>();

        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                // If the coordinate is 0,0 then we're on the current tile
                if (x == 0 && y == 0)
                {
                    continue;
                }

                int checkX = tile.gridX + x;
                int checkY = tile.gridY + y;

                if (checkX >= 0 && checkX < mGridSizeX && checkY >= 0 && checkY < mGridSizeY)
                {
                    neighbors.Add(mTileGrid[checkX, checkY]);
                }
            }
        }

        return neighbors;
    }

    public Tile TileFromWorldPoint(Vector3 worldPosition)
    {
        float percentX = (worldPosition.x + mGridWorldSize.x / 2) / mGridWorldSize.x;
        float percentY = (worldPosition.z + mGridWorldSize.y / 2) / mGridWorldSize.y;

        percentX = Mathf.Clamp01(percentX);
        percentY = Mathf.Clamp01(percentY);

        int x = Mathf.RoundToInt((mGridSizeX - 1) * percentX);
        int y = Mathf.RoundToInt((mGridSizeY - 1) * percentY);

        return mTileGrid[x, y];
    }

    Mesh InvertNormals(Mesh mesh)
    {
        mesh.triangles = mesh.triangles.Reverse().ToArray();
        return mesh;
    }

    Mesh CreateTile()
    {
        Mesh tile = new Mesh();

        float size = 1.0f;
        Vector3 offset = new Vector3(0.5f, 0, 0.5f);
        Vector3[] vertices = {
            new Vector3 (0, 0, 0) - offset,
            new Vector3 (size, 0, 0) - offset,
            new Vector3 (size, mTileHeight, 0) - offset,
            new Vector3 (0, mTileHeight, 0) - offset,
            new Vector3 (0, mTileHeight, size) - offset,
            new Vector3 (size, mTileHeight, size) - offset,
            new Vector3 (size, 0, size) - offset,
            new Vector3 (0, 0, size) - offset,
        };
        tile.vertices = vertices;

		int[] triangles = {
			0, 2, 1, //face front
			0, 3, 2,
			2, 3, 4, //face top
			2, 4, 5,
			1, 2, 5, //face right
			1, 5, 6,
			0, 7, 4, //face left
			0, 4, 3,
			5, 4, 7, //face back
			5, 7, 6,
			0, 6, 7, //face bottom
			0, 1, 6
		};
        tile.triangles = triangles;

        tile.Optimize();
        tile.RecalculateNormals();

        return tile;
    }

    Mesh CreateWall()
    {
        Mesh wall = new Mesh();

        float size = 1.0f;
        float depth = 1;
        Vector3 offset = new Vector3(0.5f, 0, 0.5f);
        Vector3[] vertices = {
            new Vector3 (0, 0, 0) - offset,
            new Vector3 (size / depth, 0, 0) - offset,
            new Vector3 (size / depth, mWallHeight, 0) - offset,
            new Vector3 (0, mWallHeight, 0) - offset,
            new Vector3 (0, mWallHeight, size) - offset,
            new Vector3 (size / depth, mWallHeight, size) - offset,
            new Vector3 (size / depth, 0, size) - offset,
            new Vector3 (0, 0, size) - offset,
        };
        wall.vertices = vertices;

		int[] triangles = {
			0, 2, 1, //face front
			0, 3, 2,
			2, 3, 4, //face top
			2, 4, 5,
			1, 2, 5, //face right
			1, 5, 6,
			0, 7, 4, //face left
			0, 4, 3,
			5, 4, 7, //face back
			5, 7, 6,
			0, 6, 7, //face bottom
			0, 1, 6
		};
        wall.triangles = triangles;

        wall.Optimize();
        wall.RecalculateNormals();

        return wall;
    }

    public void OnDrawGizmos()
    {
        CreateTileGrid();
        CreateWallGrid();
        Gizmos.DrawWireCube(transform.position, new Vector3(mGridWorldSize.x, 1, mGridWorldSize.y));

        Mesh tileMesh = CreateTile();
        Mesh wallMesh = CreateWall();

        if (mTileGrid != null)
        {
            // Draw the main tile grid
            Transform seeker = GetComponent<Pathfinding>().seeker;
            Tile playerTile = TileFromWorldPoint(seeker.position);
            foreach (Tile tile in mTileGrid)
            {
                Color tileColor = tile.mWalkable ? Color.green : Color.red;
                if (playerTile == tile && highlightPlayerTile == true)
                {
                    tileColor = Color.cyan;
                }
                tileColor.a = mOpacity;
                Gizmos.color = tileColor;

                // Blocked tiles
                if (!tile.mWalkable)
                {
                    if (showBlocked == false)
                    {
                        continue;
                    }
                    Gizmos.DrawWireMesh(wallMesh, tile.mPosition, Quaternion.identity, Vector3.one);
                }
                // Walkable tiles
                else
                {
                    if (showWalkable == false)
                    {
                        continue;
                    }
                    if (path != null)
                    {
                        if (path.Contains(tile))
                        {
                            Gizmos.color = Color.yellow;
                        }
                    }
                    Gizmos.DrawWireMesh(tileMesh, tile.mPosition, Quaternion.identity, Vector3.one);
                }
            }

            // Draw the wall grid
            foreach (Wall wall in mWallGrid)
            {
                Color wallColor = Color.red;
                wallColor.a = mOpacity;
                Gizmos.color = wallColor;

                for (int i = 0; i < wall.mBounds.Length; i++)
                {
                    bool walkable = wall.mWalkable[i];
                    Vector3 bound = wall.mBounds[i];
                    if (!walkable)
                    {
                        if (showWalls == false)
                        {
                            continue;
                        }
                        Gizmos.DrawWireMesh(wallMesh, bound, Quaternion.identity, Vector3.one);
                    }
                }
            }
        }
    }
}
