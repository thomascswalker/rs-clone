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

    private Coroutine moving;
    private Coroutine action;

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

        // If we're not moving, we'll set our speed to zero to play the idle animation
        if (!isMoving)
        {
            Idle();
        }
    }

    private void OnLeftMouseClicked(RaycastHit hit)
    {
        // If we clicked on an interactive object, we'll store it here
        queuedObject = hit.transform.gameObject.GetComponent<InteractiveObject>();

        // Find the path to the click point
        pathfinding.FindPath(transform.position, hit.point);

        // If we're moving, we'll stop moving in order to create a new path to follow
        if (isMoving)
        {
            StopCoroutine(moving);
            StopCoroutine(action);
        }

        // We'll start moving now
        moving = StartCoroutine(pathfinding.FollowPath(this));
        // We'll also queue the action, if we've actually clicked something
        if (queuedObject != null)
        {
            action = StartCoroutine(Action());
        }

        // Play the run animation
        Run();
    }

    private IEnumerator Action()
    {
        // We'll wait until we're not moving to do the action
        yield return new WaitUntil(() => isMoving == false);

        // Execute the action from the clicked object
        queuedObject.ExecuteAction();
        yield break;
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
