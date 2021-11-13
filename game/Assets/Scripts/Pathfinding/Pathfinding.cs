using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Threading;

[ExecuteInEditMode]
public class Pathfinding : MonoBehaviour
{
    public PathGrid grid;
    public float rotationSpeed = 10f;
    public bool isMoving = false;

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
                if (!neighbor.walkable || closedSet.Contains(neighbor))
                {
                    continue;
                }

                // If the tile has a thin wall between, then we'll skip too
                if (HasWallBetween(currentTile, neighbor))
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

    /// <summary>
    /// Moves the unit along the current path.
    /// </summary>
    /// <param name="unit">The unit to move.</param>
    /// <returns></returns>
    public IEnumerator FollowPath(PlayerController unit)
    {
        isMoving = true;
        GameObject model = unit.model;

        // For each tile in the path
        foreach(Tile tile in grid.path)
        {
            Vector3 target = tile.position;

            // While we're further than 1/10000 units away from the target tile
            while (Vector3.Distance(unit.transform.position, tile.position) > .0001)
            {
                // Update rotation
                Vector3 direction = target - unit.transform.position;
                if (direction != Vector3.zero)
                {
                    direction = direction.normalized;
                    Quaternion rotation = Quaternion.LookRotation(direction);
                    model.transform.rotation = Quaternion.Slerp(model.transform.rotation, rotation, rotationSpeed * Time.deltaTime);
                }

                // Update position
                Vector3 current = unit.transform.position;
                float step = unit.speed * Time.deltaTime;
                unit.transform.position = Vector3.MoveTowards(current, target, step);

                yield return null;
            }
        }

        isMoving = false;
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

    enum Direction
    {
        North,
        NorthEast,
        East,
        SouthEast,
        South,
        SouthWest,
        West,
        NorthWest
    }

    Direction GetDirection(Tile tileA, Tile tileB)
    {
        int x = tileB.x - tileA.x;
        int y = tileB.y - tileA.y;

        switch (x, y)
        {
            case (0, 1):
                return Direction.North;
            case (1, 1):
                return Direction.NorthEast;
            case (1, 0):
                return Direction.East;
            case (1, -1):
                return Direction.SouthEast;
            case (0, -1):
                return Direction.South;
            case (-1, -1):
                return Direction.SouthWest;
            case (-1, 0):
                return Direction.West;
            case (-1, 1):
                return Direction.NorthWest;
            default:
                throw new ArgumentOutOfRangeException("Coordinates are out of range");
        }
    }

    Tile[] GetAdjacentTiles(Tile tileA, Tile tileB)
    {
        Tile[] adjacentTiles = new Tile[2];

        Tile north = grid.grid[tileA.x, tileA.y + 1]; // North
        Tile east = grid.grid[tileA.x + 1, tileA.y]; // North
        Tile south = grid.grid[tileA.x, tileA.y - 1]; // North
        Tile west = grid.grid[tileA.x - 1, tileA.y]; // North

        Direction direction = GetDirection(tileA, tileB);

        switch (direction)
        {
            case Direction.NorthEast:
                adjacentTiles[0] = north;
                adjacentTiles[1] = east;
                break;
            case Direction.SouthEast:
                adjacentTiles[0] = south;
                adjacentTiles[1] = east;
                break;
            case Direction.SouthWest:
                adjacentTiles[0] = south;
                adjacentTiles[1] = west;
                break;
            case Direction.NorthWest:
                adjacentTiles[0] = north;
                adjacentTiles[1] = west;
                break;
            default:
                throw new ArgumentException("Something went wrong");
        }

        return adjacentTiles;
    }
    
    bool HasWallBetween(Tile tileA, Tile tileB)
    {
        Direction direction = GetDirection(tileA, tileB);
        Vector3 start = (tileA.position + tileB.position) / 2f;
        Vector3 end = start + new Vector3(0, 1f, 0);
        float radius = 0.5f;

        if (direction == Direction.North || direction == Direction.East || direction == Direction.South || direction == Direction.West) // For orthogonal tiles
        {
            
            bool blocked = Physics.CheckCapsule(start, end, radius, grid.wallLayer);
            return blocked;
        }
        else // For diagonal tiles
        {
            Tile[] adjacentTiles = GetAdjacentTiles(tileA, tileB);
            foreach (Tile tile in adjacentTiles)
            {
                Vector3 midpoint = (tileA.position + tile.position) / 2f;
                bool blocked = Physics.CheckCapsule(start, end, radius, grid.wallLayer);
                if (blocked)
                {
                    Debug.Log("Diagonal move!");
                    return true;
                }
            }
        }

        return false;
    }
}
