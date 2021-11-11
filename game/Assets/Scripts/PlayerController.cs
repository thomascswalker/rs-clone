using System.Collections;
using System.Collections.Generic;
using UnityEngine.AI;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    Pathfinding pathfinding;
    private Animator animator;
    public GameObject model;
    private Coroutine movingCoroutine;
    public float speed = 5.0f;

    void Awake()
    {
        GameObject obj = GameObject.FindWithTag("Pathing");
        pathfinding = obj.GetComponent<Pathfinding>();
        animator = GetComponentInChildren<Animator>();
        Debug.Log(pathfinding);
        Idle();
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
                if (pathfinding.isMoving)
                {
                    StopCoroutine(movingCoroutine);
                }
                pathfinding.FindPath(transform.position, hit.point);
                Run();
            }
        }

        if (!pathfinding.isMoving)
        {
            Idle();
        }
    }

    private void Idle()
    {
        animator.SetFloat("speed", 0);
    }

    private void Run()
    {

        movingCoroutine = StartCoroutine(pathfinding.FollowPath(this));
        animator.SetFloat("speed", 1.0f);
    }
}
