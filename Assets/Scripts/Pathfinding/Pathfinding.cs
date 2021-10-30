using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ExecuteInEditMode]
public class Pathfinding : MonoBehaviour
{
    public PathGrid grid;
    int targetIndex;
    public float speed = 20;

    // Execute prior to game launch
    void Awake()
    {
        grid = GetComponent<PathGrid>(); // Get the grid object itself
    }

    /// <summary>
    /// Finds a valid path given the start and target positions.
    /// </summary>
    /// <param name="startPos">The start point of the path.</param>
    /// <param name="targetPos">The end point of the path.</param>
    public void FindPath(Vector3 startPos, Vector3 targetPos)
    {
        // Get the start and target tiles from the start and target positions
        Tile startTile = grid.TileFromWorldPoint(startPos);
        Tile targetTile = grid.TileFromWorldPoint(targetPos);

        // If there is no valid target tile, then we don't need to do any pathfinding
        // and we can just exit.
        if (targetTile == null)
        {
            return;
        }

        // Create two sets: an open and a closed set
        List<Tile> openSet = new List<Tile>();
        HashSet<Tile> closedSet = new HashSet<Tile>();

        // Add the starting tile to the open set
        openSet.Add(startTile);

        // While there are still tiles in the open set...
        while (openSet.Count > 0)
        {
            // Set the current tile to be the first tile in the open set
            Tile currentTile = openSet[0];
            for (int i = 1; i < openSet.Count; i++)
            {
                if (openSet[i].f < currentTile.f || openSet[i].f == currentTile.f && openSet[i].h < currentTile.h)
                {
                    currentTile = openSet[i];
                }
            }

            // Remove the current tile from the open set and add it to the closed set
            openSet.Remove(currentTile);
            closedSet.Add(currentTile);

            // If we're on the current tile, we need to retrace our path
            if (currentTile == targetTile)
            {
                RetracePath(startTile, targetTile);
                return;
            }

            // For each neighboring tile
            foreach (Tile neighbor in grid.GetNeighbors(currentTile))
            {
                // Skip if:
                // The neighbor is not walkable
                // The closed set already contains the neighbor
                // The neighbor is not an orthogonal tile
                if (!neighbor.walkable || closedSet.Contains(neighbor) || !neighbor.ortho)
                {
                    continue;
                }

                // Get the cost of moving to this neighboring tile
                int cost = currentTile.g + GetDistance(currentTile, neighbor);

                // If the cost to move is lower than the base incremental cost,
                // or the open set doesn't contain the neighbor yet
                if (cost < neighbor.g || !openSet.Contains(neighbor))
                {
                    // Set the base cost of this neighbor to the calculated cost
                    neighbor.g = cost;

                    // Set the heuristic to the distance from the neighbor
                    // to the target tile
                    neighbor.h = GetDistance(neighbor, targetTile);

                    // Set the parent of the neighbor to this tile
                    neighbor.parent = currentTile;

                    // If the open set doesn't contain the neighbor, then we'll add it.
                    if (!openSet.Contains(neighbor))
                    {
                        openSet.Add(neighbor);
                    }
                }
            }
        }
    }

    /// <summary>
    /// Retraces the path from the end tile back to the start tile
    /// </summary>
    /// <param name="startTile"></param>
    /// <param name="endTile"></param>
    void RetracePath(Tile startTile, Tile endTile)
    {
        List<Tile> path = new List<Tile>();
        Tile currentTile = endTile;

        // If we're not back at the starting tile
        while (currentTile != startTile)
        {
            path.Add(currentTile);
            currentTile = currentTile.parent;
        }

        // Reverse the path so it goes start to end
        path.Reverse();

        // Set the grid's path to the path we just got
        grid.path = path;
    }

    public void NavigatePath(PlayerController unit)
    {
        Tile currentWaypoint = grid.path[0];
        while (true)
        {
            Tile currentTile = grid.TileFromWorldPoint(unit.transform.position);
            if (currentTile == currentWaypoint)
            {
                targetIndex++;
                if (targetIndex >= grid.path.Count)
                {
                    return;
                }
                currentWaypoint = grid.path[targetIndex];
            }
            unit.transform.position = Vector3.MoveTowards(unit.transform.position, currentWaypoint.position, speed * Time.deltaTime);
            return;
        }
    }

    /// <summary>
    /// Gets the distance cost from one tile to another
    /// </summary>
    /// <param name="tileA">The first tile.</param>
    /// <param name="tileB">The second tile.</param>
    /// <returns>The distance cost.</returns>
    int GetDistance(Tile tileA, Tile tileB)
    {
        // Get the absolute distance from the first tile to the second
        int distanceX = Mathf.Abs(tileA.x - tileB.x);
        int distanceY = Mathf.Abs(tileA.y - tileB.y);

        // Calculate the distance cost
        if (distanceX > distanceY)
        {
            return (14 * distanceY) + 10 * (distanceX - distanceY);
        }

        int distance = (14 * distanceX) + 10 * (distanceY - distanceX);
        return distance;
    }
}
