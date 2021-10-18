using System.Collections;
using System.Collections.Generic;
using UnityEngine.AI;
using UnityEngine;

using Pathfinding;

public class PlayerController : MonoBehaviour
{
    private AIPath ai;

    void Awake()
    {
        ai = GetComponent<AIPath>();
    }

    void Start()
    {

    }

    void Update()
    {
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit hit;

        if (Input.GetButtonDown("Fire1"))
        {
            if (Physics.Raycast(ray, out hit))
            {
                ai.destination = hit.point;
            }
        }
    }
}
