using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using UnityEditor;

[ExecuteInEditMode]
public class PathGrid : MonoBehaviour
{
    public LayerMask unwalkableLayer;
    public LayerMask wallLayer;
    public LayerMask pillarLayer;

    public Vector2 worldSize = new Vector2(20f, 20f);
    float tileDiameter;
    public float tileRadius = 0.5f;
    public float tileHeight = 0.1f;

    public bool showWalkable = true;
    public bool showBlocked = true;

    public Tile[,] grid;

    public List<Tile> path;
    public Color pathColor = Color.green;

    int sizeX, sizeY;

    void Start()
    {
        tileDiameter = tileRadius * 2;

        sizeX = Mathf.RoundToInt(worldSize.x / tileDiameter);
        sizeY = Mathf.RoundToInt(worldSize.y / tileDiameter);

        CreateTileGrid();
    }

    /// <summary>
    /// This generates the tile grid.
    /// </summary>
    public void CreateTileGrid()
    {
        // Create a new blank tile grid
        grid = new Tile[sizeX, sizeY];

        // Get the bottom left coordinate of our grid
        Vector3 bottom = Vector3.right * worldSize.x / 2;
        Vector3 left = Vector3.forward * worldSize.y / 2;
        Vector3 offset = new Vector3(tileDiameter, 0, tileDiameter);
        Vector3 worldBottomLeft = transform.position - bottom - left - offset;

        // For each tile in our grid...
        for (int x = 0; x < sizeX; x++)
        {
            for (int y = 0; y < sizeY; y++)
            {
                // Get the X and Y coordinates of the current tile
                Vector3 xCoord = Vector3.right * (x + tileDiameter + tileRadius);
                Vector3 yCoord = Vector3.forward * (y + tileDiameter + tileRadius);

                // Get the world position of this tile
                Vector3 worldPoint = worldBottomLeft + xCoord + yCoord;

                // Do a physics check to see if this tile is walkable.
                bool walkable = !(Physics.CheckSphere(worldPoint, tileRadius, unwalkableLayer));

                // Create a new tile at this point, set whether it's walkable or not
                // and set the current tile in our loop to this new tile we just
                // created.
                grid[x, y] = new Tile(walkable, worldPoint, x, y);
            }
        }
    }

    // public void CreateWallGrid()
    // {
    //     mWallGrid = new Wall[sizeX, sizeY];
    //     Vector3 worldBottomLeft = transform.position - Vector3.right * worldSize.x / 2 - Vector3.forward * worldSize.y / 2;
    //     worldBottomLeft -= new Vector3(tileDiameter, 0, tileDiameter);
    //     for (int x = 0; x < sizeX; x++)
    //     {
    //         for (int y = 0; y < sizeY; y++)
    //         {
    //             Vector3 xOffset = Vector3.right * (x + tileDiameter + tileRadius);
    //             Vector3 yOffset = Vector3.forward * (y + tileDiameter + tileRadius);
    //             Vector3 worldPoint = worldBottomLeft + xOffset + yOffset;

    //             bool[] walkable = new bool[4];

    //             Vector3 northPoint = worldPoint + new Vector3(tileDiameter, 0, tileRadius);
    //             Vector3 westPoint = worldPoint + new Vector3(tileRadius, 0, 0);
    //             Vector3 eastPoint = worldPoint + new Vector3(tileRadius, 0, tileDiameter);
    //             Vector3 southPoint = worldPoint + new Vector3(0, 0, tileRadius);
    //             Vector3[] bounds = new Vector3[] {northPoint, westPoint, eastPoint, southPoint};

    //             walkable[0] = !(Physics.CheckSphere(northPoint, mWallRadius, wallLayer));
    //             walkable[1] = !(Physics.CheckSphere(westPoint, mWallRadius, wallLayer));
    //             walkable[2] = !(Physics.CheckSphere(eastPoint, mWallRadius, wallLayer));
    //             walkable[3] = !(Physics.CheckSphere(southPoint, mWallRadius, wallLayer));

    //             mWallGrid[x, y] = new Wall(walkable, bounds, worldPoint, x, y);
    //         }
    //     }
    // }

    /// <summary>
    /// Given a tile, get its neighboring tiles. Indexed in the order of: 2, 4, 7, 1, -, 6, 0, 3, 5
    /// </summary>
    /// <param name="tile">The tile to get neighbors from.</param>
    /// <returns>Returns the list of neighboring tiles.</returns>
    public List<Tile> GetNeighbors(Tile tile)
    {
        // Create a new empty tile list
        List<Tile> neighbors = new List<Tile>();

        // Loop through and get the initial viable tiles
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                // If the coordinate is 0,0 then we're on the current tile
                if (x == 0 && y == 0)
                {
                    continue;
                }

                // The grid coordinates of the tile we're currently checking
                int checkX = tile.x + x;
                int checkY = tile.y + y;

                // If the tile we're checking is not out of bounds of the grid (greater or less than the size)
                if (checkX >= 0 && checkX < sizeX && checkY >= 0 && checkY < sizeY)
                {
                    // Get the tile object we're currently checking
                    Tile neighbor = grid[checkX, checkY];

                    // Determine if the check tile is orthogonal relative to the current tile
                    if (Mathf.Abs(x) == 0 && Mathf.Abs(y) == 1 || Mathf.Abs(x) == 1 && Mathf.Abs(y) == 0)
                    {
                        neighbor.ortho = true;
                    }

                    // Set the relative coordinate of this tile to the current x, y.
                    neighbor.rx = x;
                    neighbor.ry = y;

                    // Add this tile to the list of neighbors
                    neighbors.Add(neighbor);
                }
            }
        }

        return neighbors;
    }

    /// <summary>
    /// Returns the tile found from a given world position.
    /// </summary>
    /// <param name="worldPosition">The world position to try to find a tile at.</param>
    /// <returns>The tile, if it's found.</returns>
    public Tile TileFromWorldPoint(Vector3 worldPosition)
    {
        // Get the percentage across and up on the grid
        float percentX = (worldPosition.x + worldSize.x / 2) / worldSize.x;
        float percentY = (worldPosition.z + worldSize.y / 2) / worldSize.y;

        // Clamp the percentage values
        percentX = Mathf.Clamp01(percentX);
        percentY = Mathf.Clamp01(percentY);

        // Get the corresponding x, y coordinates
        int x = Mathf.RoundToInt((sizeX - 1) * percentX);
        int y = Mathf.RoundToInt((sizeY - 1) * percentY);

        // Return the tile in the tile array based on the coordinates
        return grid[x, y];
    }

    public void OnDrawGizmos()
    {
        Gizmos.DrawWireCube(transform.position, new Vector3(worldSize.x, 1, worldSize.y));
        CreateTileGrid();
        Mesh tileMesh = Tile.GetMesh(tileDiameter, tileHeight);

        // Draw the tile grid
        if (grid != null)
        {
            // For each tile in the grid
            foreach (Tile tile in grid)
            {
                // Determine the tile color
                Color tileColor = tile.walkable ? Color.green : Color.red;
                Gizmos.color = tileColor;

                // Blocked tiles
                if (!tile.walkable && showBlocked)
                {
                    Gizmos.DrawMesh(tileMesh, tile.position, Quaternion.identity, Vector3.one);
                }

                // Walkable tiles
                if (tile.walkable && showWalkable)
                {
                    Gizmos.DrawMesh(tileMesh, tile.position, Quaternion.identity, Vector3.one);
                }
            }
        }

        // Draw the movement path
        if (path != null)
        {
            foreach (Tile tile in path)
            {
                Gizmos.color = pathColor;
                Gizmos.DrawSphere(tile.position, 0.25f);
            }
        }
    }
}
