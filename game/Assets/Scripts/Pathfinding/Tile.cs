using UnityEngine;

/// <summary>Each tile in the navigation grid.</summary>
public class Tile
{
    /// <value>Whether the entire tile is walkable or not.</value>
    public bool walkable;
    /// <value>The world position of the tile.</value>
    public Vector3 position;
    /// <value>The X grid coordinate of the tile.</value>
    public int x;
    /// <value>The Y grid coordinate of the tile.</value>
    public int y;

    /// <value>The base score of the tile. The incremental cost of moving from the start tile to this tile.</value>
    public int g;
    /// <value>The heuristic. An estimate of the distance between each node and the goal.</value>
    public int h;

    /// <value>The parent tile which is being moved from.</value>
    public Tile parent;

    /// <value>The walls in relation to this tile.</value>
    public bool[] walls = new bool[4];
    /// <value>The pillars in relation to this tile.</value>
    public bool[] pillars = new bool[4];

    /// <summary>
    /// A Tile can have one of two states:
    /// <list type="bullet">
    /// <item><description>A non-blocking, or free, tile is a tile that allows free movement from all directions, given
    /// that the adjacent tiles do not have any blockage that prevents this. It is a tile that does not have any
    /// objects, walls or pillars and can be stood on.</description></item>
    /// <item><description>A full-blocking tile is one that completely disallows movement from all directions.
    /// These tiles are usually occupied by an object and cannot be reached by normal means.</description></item>
    /// </list>
    /// A Tile can also have other properties such as:
    /// <list type="bullet">
    /// <item><description>Walls occupy the borders of a tile. They block movement from the same direction as their
    /// location on the tile. Despite blocking movement, walls do not fully occupy the tile. It is possible to stand
    /// on a tile that has one or more walls on its borders.</description></item>
    /// <item><description>Pillars occupy the corners of a tile. They normally block movement from the diagonal
    /// direction just like walls do for cardinal directions. However, pillars are rarely added on all four adjacent
    /// tiles, often making it possible to walk through them in one or more directions, typically south-west to
    /// north-east and vice-versa. It is possible to stand on a tile that has one or more pillars on its
    /// corners.</description></item>
    /// </list>
    /// </summary>
    /// <param name="_walkable">Whether the entire tile is walkable or not.</param>
    /// <param name="_position">The world position of the tile.</param>
    /// <param name="_x">The X grid coordinate of the tile.</param>
    /// <param name="_y">The Y grid coordinate of the tile.</param>
    public Tile(bool _walkable, Vector3 _position, int _x, int _y)
    {
        walkable = _walkable;
        position = _position;
        x = _x;
        y = _y;
    }

    /// <summary>
    /// Returns the F Cost of the tile. This represents our current best guess as to how short a path from start to
    /// finish can be.
    /// </summary>
    public int f
    {
        get {return g + h;}
    }

    /// <summary>
    /// Creates a tile gizmo mesh.
    /// </summary>
    /// <returns>The mesh.</returns>
    public static Mesh GetMesh(float size, float height)
    {
        // Create a new empty mesh
        Mesh tile = new Mesh();

        // Start the tile mesh at the bottom left corner
        Vector3 offset = new Vector3(size / 2, 0, size / 2);

        // Create the vertex list
        Vector3[] vertices = {
            new Vector3 (0, 0, 0) - offset,
            new Vector3 (size, 0, 0) - offset,
            new Vector3 (size, height, 0) - offset,
            new Vector3 (0, height, 0) - offset,
            new Vector3 (0, height, size) - offset,
            new Vector3 (size, height, size) - offset,
            new Vector3 (size, 0, size) - offset,
            new Vector3 (0, 0, size) - offset,
        };
        tile.vertices = vertices;

        // Create the triangle indexes
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

        // Optimize the mesh and generate normals
        tile.Optimize();
        tile.RecalculateNormals();

        // Return the tile mesh which was created
        return tile;
    }
}