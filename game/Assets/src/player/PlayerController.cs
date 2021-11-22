using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

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

    private GameObject queuedGameObject;
    private Interactive queuedInteractiveObject;

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
        if (Input.GetMouseButtonDown(0))
        {
            // If we're clicking on the UI, we want to return so we don't click-through
            if (EventSystem.current.IsPointerOverGameObject())
            {
                return;
            }

            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            // Otherwise we'll do a raycast to see where we clicked in the game
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

    private void StoreClickedObject(GameObject obj)
    {
        queuedGameObject = obj;
        queuedInteractiveObject = queuedGameObject.GetComponent<Interactive>();

        if (queuedInteractiveObject == null)
        {
            queuedGameObject = null;
        }
    }

    private float DistanceToQueuedGameObject()
    {
        float distance = Vector3.Distance(queuedGameObject.transform.position, transform.position);
        return distance;
    }

    private bool CanMove()
    {
        if (queuedGameObject == null)
        {
            return true;
        }

        float distance = DistanceToQueuedGameObject();
        return distance > 1.0f ? true : false;
    }

    private bool CanInteract()
    {
        return queuedInteractiveObject != null ? true : false;
    }

    private void OnLeftMouseClicked(RaycastHit hit)
    {
        // If we clicked on an interactive object, we'll store it here
        StoreClickedObject(hit.transform.gameObject);

        // Find the path to the click point
        pathfinding.FindPath(transform.position, hit.point);

        // If we're moving, we'll stop moving in order to create a new path to follow
        if (isMoving)
        {
            StopAll();
        }

        // We'll start moving now
        if (CanMove())
        {
            moving = StartCoroutine(pathfinding.FollowPath(this));
        }
        // We'll also queue the action, if we've actually clicked something
        if (CanInteract())
        {
            action = StartCoroutine(Action());
        }

        // Play the run animation
        Run();
    }

    private void StopAll()
    {
        if (moving != null)
        {
            StopCoroutine(moving);
        }
        
        if (action != null)
        {
            StopCoroutine(action);
        }
    }

    private IEnumerator Action()
    {
        // We'll wait until we're not moving to do the action
        yield return new WaitUntil(() => isMoving == false);

        // Execute the action from the clicked object
        Debug.Log(queuedInteractiveObject);
        if (queuedInteractiveObject.GetType().GetMethod("ExecuteAction") != null)
        {
            queuedInteractiveObject.ExecuteAction();
        }
        else
        {
            Debug.Log("No action found!");
        }
        
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
