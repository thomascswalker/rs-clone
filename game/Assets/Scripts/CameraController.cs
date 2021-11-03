using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

using Console;

public class CameraController : MonoBehaviour
{
    [Header("Target")]
    public Transform target;

    [Header("Distance")]
    public float distance;
    public float minDistance;
    public float maxDistance;
    public Vector3 offset;
    
    [Header("Speed")]
    public float cameraSpeed = 25.0f;
    public float scrollSpeed = 5.0f;

    private Ray ray;
    private RaycastHit hit;

    void Update()
    {
        if (!target)
        {
            Debug.Log("NO TARGET SET FOR THE CAMERA");
            return;
        }

        HandleMouse();
        HandleInput();
    }

    void HandleInput()
    {
        // Handle zoom
        distance -= Input.GetAxis("Mouse ScrollWheel") * scrollSpeed;
        distance = Mathf.Clamp(distance, minDistance, maxDistance);

        // Follow target
        Vector3 pos = target.position + offset;
        pos -= transform.forward * distance;

        // Move the camera to the correct distance
        transform.position = Vector3.Lerp(transform.position, pos, cameraSpeed * Time.deltaTime);

        // Handle rotation
        if (Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.UpArrow))
        {
            transform.RotateAround(target.transform.position, transform.right, cameraSpeed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow))
        {
            transform.RotateAround(target.transform.position, transform.right, -cameraSpeed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow))
        {
            transform.RotateAround(target.transform.position, Vector3.up, cameraSpeed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow))
        {
            transform.RotateAround(target.transform.position, Vector3.up, -cameraSpeed * Time.deltaTime);
        }
    }

    bool IsWalkable(GameObject obj)
    {
        if (obj.tag == "Walkable")
        {
            return true;
        }

        return false; 
    }

    bool IsInteractive(GameObject obj)
    {
        if (obj.tag == "Interactive")
        {
            return true;
        }

        return false;
    }

    void HandleMouse()
    {

    }
}
