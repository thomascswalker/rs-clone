using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ExecuteInEditMode]
public class Pathfinding : MonoBehaviour
{
    PathGrid mGrid;
    public Transform seeker, target;

    void Awake()
    {
        mGrid = GetComponent<PathGrid>();
    }
    
    void Update()
    {
        FindPath(seeker.position, target.position);
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

            if (currentTile == targetTile)
            {
                RetracePath(startTile, targetTile);
                return;
            }

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
