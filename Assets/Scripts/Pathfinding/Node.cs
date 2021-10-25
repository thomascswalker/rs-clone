using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Node
{
    public bool mWalkable;
    public Vector3 mPosition;

    public Node(bool walkable, Vector3 position)
    {
        mWalkable = walkable;
        mPosition = position;
    }
}
