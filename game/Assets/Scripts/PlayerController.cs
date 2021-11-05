using System.Collections;
using System.Collections.Generic;
using UnityEngine.AI;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    Pathfinding pathfinding;
    [SerializeField] private Animator animator = null;

    void Awake()
    {
        GameObject obj = GameObject.FindWithTag("Pathing");
        pathfinding = obj.GetComponent<Pathfinding>();
        Debug.Log(pathfinding);
        animator.SetBool("isIdle", true);
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
                pathfinding.FindPath(transform.position, hit.point);
                StartCoroutine(pathfinding.FollowPath(this));
                animator.SetBool("isIdle", false);
            }
        }
    }
}
