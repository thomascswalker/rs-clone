using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ExecuteInEditMode]
public class Pathfinding : MonoBehaviour
{
    PathGrid mGrid;
    public Transform seeker;

    void Awake()
    {
        mGrid = GetComponent<PathGrid>();
    }
    
    void Update()
    {
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit hit;

        if (Physics.Raycast(ray, out hit))
        {
            FindPath(seeker.position, hit.point);
        }
    }

    void FindPath(Vector3 startPos, Vector3 targetPos)
    {
        Tile startTile = mGrid.TileFromWorldPoint(startPos);
        Tile targetTile = mGrid.TileFromWorldPoint(targetPos);

        List<Tile> openSet = new List<Tile>();
        HashSet<Tile> closedSet = new HashSet<Tile>();

        openSet.Add(startTile);

        while (openSet.Count > 0)
        {
            Tile currentTile = openSet[0];
            for (int i = 1; i < openSet.Count; i++)
            {
                if (openSet[i].fCost() < currentTile.fCost() || openSet[i].fCost() == currentTile.fCost() && openSet[i].hCost < currentTile.hCost)
                {
                    currentTile = openSet[i];
                }
            }

            openSet.Remove(currentTile);
            closedSet.Add(currentTile);

            // If we're on the current tile, we need to retrace our path
            if (currentTile == targetTile)
            {
                RetracePath(startTile, targetTile);
                return;
            }

            /* Get the current walls tile
                    _____________
                    | - | 0 | - |
                    _____________
                    | 1 | - | 3 |
                    _____________
                    | - | 2 | - |
                    _____________

                    0 = [0, 1]
                    1 = [-1, 0]
                    2 = [0, -1]
                    3 = [1, 0]
            */

            // Wall wall;
            // if (mGrid.mWallGrid != null)
            // {
            //     wall = mGrid.mWallGrid[currentTile.gridX, currentTile.gridY];
            // }

            // For each neighboring tile
            foreach (Tile neighbor in mGrid.GetNeighbors(currentTile))
            {
                if (!neighbor.mWalkable || closedSet.Contains(neighbor))
                {
                    continue;
                }

                if (!neighbor.ortho)
                {
                    continue;
                }

                int x = neighbor.relativeX;
                int y = neighbor.relativeY;

                int newMovementCostToNeighbor = currentTile.gCost + GetDistance(currentTile, neighbor);
                if (newMovementCostToNeighbor < neighbor.gCost || !openSet.Contains(neighbor))
                {
                    neighbor.gCost = newMovementCostToNeighbor;
                    neighbor.hCost = GetDistance(neighbor, targetTile);
                    neighbor.parent = currentTile;

                    if (!openSet.Contains(neighbor))
                    {
                        openSet.Add(neighbor);
                    }
                }
            }
        }
    }

    void RetracePath(Tile startTile, Tile endTile)
    {
        List<Tile> path = new List<Tile>();
        Tile currentTile = endTile;

        while (currentTile != startTile)
        {
            path.Add(currentTile);
            currentTile = currentTile.parent;
        }

        path.Reverse();

        mGrid.mPath = path;
    }

    int GetDistance(Tile tileA, Tile tileB)
    {
        int distanceX = Mathf.Abs(tileA.gridX - tileB.gridX);
        int distanceY = Mathf.Abs(tileA.gridY - tileB.gridY);

        if (distanceX > distanceY)
        {
            return (14 * distanceY) + 10 * (distanceX - distanceY);
        }

        return (14 * distanceX) + 10 * (distanceY - distanceX);
    }
}
