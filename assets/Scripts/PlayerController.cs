using System.Collections;
using System.Collections.Generic;
using UnityEngine.AI;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    Pathfinding pathfinding;

    void Awake()
    {
        GameObject obj = GameObject.FindWithTag("Pathing");
        pathfinding = obj.GetComponent<Pathfinding>();
        Debug.Log(pathfinding);
    }

    // On every frame
    void Update()
    {
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit hit;

        if (Physics.Raycast(ray, out hit))
        {
            // If we're clicking
            if (Input.GetMouseButtonDown(0))
            {
                Debug.Log("Mouse clicked!");
                pathfinding.FindPath(transform.position, hit.point);
                StartCoroutine(pathfinding.NavigatePath(this));
            }
        }
    }
}
