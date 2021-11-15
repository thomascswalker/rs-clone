using System.Collections;
using System.Collections.Generic;
using UnityEngine.AI;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    Pathfinding pathfinding;
    private Animator animator;
    public GameObject model;
    
    public LayerMask clickable;

    private Coroutine movingCoroutine;
    private Coroutine actionCoroutine;
    public bool isMoving = false;
    public float movementSpeed = 5.0f;
    public float rotationSpeed = 10f;

    private InteractiveObject queuedObject;

    void Awake()
    {
        GameObject obj = GameObject.FindWithTag("Pathing");
        pathfinding = obj.GetComponent<Pathfinding>();
        animator = GetComponentInChildren<Animator>();
        clickable = LayerMask.GetMask("Walkable");

        Idle();
    }

    // On every frame
    void Update()
    {
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit hit;

        if (Input.GetMouseButtonDown(0))
        {
            if (Physics.Raycast(ray, out hit, clickable))
            {
                OnLeftMouseClicked(hit);
            }
        }

        if (!isMoving)
        {
            Idle();
        }
    }

    private void OnLeftMouseClicked(RaycastHit hit)
    {
        queuedObject = hit.transform.gameObject.GetComponent<InteractiveObject>();
        if (queuedObject != null)
        {
            Debug.Log(hit.transform.gameObject.name);
        }

        pathfinding.FindPath(transform.position, hit.point);

        if (isMoving)
        {
            StopCoroutine(movingCoroutine);
            StopCoroutine(actionCoroutine);
        }

        movingCoroutine = StartCoroutine(pathfinding.FollowPath(this));
        actionCoroutine = StartCoroutine(Action());
        Run();
    }

    private IEnumerator Action()
    {
        while (isMoving)
        {
            yield return null;
        }
        queuedObject.ExecuteAction();
        StopCoroutine(actionCoroutine);
    }

    private void Idle()
    {
        animator.SetFloat("speed", 0);
    }

    private void Run()
    {
        animator.SetFloat("speed", 1.0f);
    }
}
