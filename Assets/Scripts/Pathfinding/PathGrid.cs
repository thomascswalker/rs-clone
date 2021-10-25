using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(PathGrid))]
public class PathGridEditor : Editor
{
    public override void OnInspectorGUI()
    {
        DrawDefaultInspector();

        PathGrid script = (PathGrid)target;
        if (GUILayout.Button("Test"))
        {
            script.CreateGrid();
        }
    }
}

[ExecuteInEditMode]
public class PathGrid : MonoBehaviour
{
    public Transform player;
    public LayerMask mUnwalkableMask;
    public LayerMask mWallMask;
    public LayerMask mPillarMask;
    public Vector2 mGridWorldSize = new Vector2(20f, 20f);
    public float mNodeRadius = 0.5f;
    public float mHeight = 0.1f;
    public float mOpacity = 0.75f;
    private Node[,] mGrid;

    float mNodeDiameter;
    int mGridSizeX, mGridSizeY;

    void Start()
    {
        mNodeDiameter = mNodeRadius * 2;

        mGridSizeX = Mathf.RoundToInt(mGridWorldSize.x / mNodeDiameter);
        mGridSizeY = Mathf.RoundToInt(mGridWorldSize.y / mNodeDiameter);

        CreateGrid();
    }

    public void CreateGrid()
    {
        mGrid = new Node[mGridSizeX, mGridSizeY];
        Vector3 worldBottomLeft = transform.position - Vector3.right * mGridWorldSize.x / 2 - Vector3.forward * mGridWorldSize.y / 2;
        worldBottomLeft -= new Vector3(1, 0, 1);
        for (int x = 0; x < mGridSizeX; x++)
        {
            for (int y = 0; y < mGridSizeY; y++)
            {
                Vector3 xOffset = Vector3.right * (x + mNodeDiameter + mNodeRadius);
                Vector3 yOffset = Vector3.forward * (y + mNodeDiameter + mNodeRadius);
                Vector3 worldPoint = worldBottomLeft + xOffset + yOffset;
                bool walkable = !(Physics.CheckSphere(worldPoint, mNodeRadius, mUnwalkableMask));

                mGrid[x, y] = new Node(walkable, worldPoint);
            }
        }
    }

    public Node NodeFromWorldPoint(Vector3 worldPosition)
    {
        float percentX = (worldPosition.x + mGridWorldSize.x / 2) / mGridWorldSize.x;
        float percentY = (worldPosition.z + mGridWorldSize.y / 2) / mGridWorldSize.y;

        percentX = Mathf.Clamp01(percentX);
        percentY = Mathf.Clamp01(percentY);

        int x = Mathf.RoundToInt((mGridSizeX - 1) * percentX);
        int y = Mathf.RoundToInt((mGridSizeY - 1) * percentY);

        return mGrid[x, y];
    }

    Mesh CreateTile()
    {
        Mesh tile = new Mesh();

        float size = .95f;
        Vector3 offset = new Vector3(0.5f, 0, 0.5f);
        Vector3[] vertices = {
            new Vector3 (0, 0, 0) - offset,
            new Vector3 (size, 0, 0) - offset,
            new Vector3 (size, mHeight, 0) - offset,
            new Vector3 (0, mHeight, 0) - offset,
            new Vector3 (0, mHeight, size) - offset,
            new Vector3 (size, mHeight, size) - offset,
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
        tile.RecalculateNormals ();

        return tile;
    }

    public void OnDrawGizmos()
    {
        CreateGrid();
        Gizmos.DrawWireCube(transform.position, new Vector3(mGridWorldSize.x, 1, mGridWorldSize.y));

        Mesh tile = CreateTile();

        if (mGrid != null)
        {
            // Draw the main tile grid
            Node playerNode = NodeFromWorldPoint(player.position);
            foreach (Node n in mGrid)
            {
                Color nodeColor = n.mWalkable ? Color.green : Color.red;
                if (playerNode == n)
                {
                    nodeColor = Color.cyan;
                }
                nodeColor.a = mOpacity;
                Vector3 nodePosition = n.mPosition;
                Gizmos.color = nodeColor;
                Gizmos.DrawMesh(tile, n.mPosition, Quaternion.identity, Vector3.one);
            }

            // Draw the wall grid

            // Draw the pillar grid
        }
    }
}
