using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class CameraController : MonoBehaviour
{
    [Header("Target")]
    public Transform target;

    [Header("Distance")]
    public float distance;
    public float fov = 90f;
    public float minFov = 10f;
    public float maxFov = 120f;
    public Vector3 offset;
    
    [Header("Speed")]
    public float cameraSpeed = 25.0f;
    public float scrollSpeed = 5.0f;

    private Ray ray;
    private RaycastHit hit;

    void Start()
    {

    }

    void Update()
    {
        if (!target)
        {
            return;
        }

        HandleZoom();
        HandleInput();
    }

    void HandleInput()
    {
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

    void HandleZoom()
    {
        // If we're clicking on the UI, we want to return so we don't click-through
        if (EventSystem.current.IsPointerOverGameObject())
        {
            return;
        }

        // Handle zoom
        fov -= Input.GetAxis("Mouse ScrollWheel") * scrollSpeed;
        fov = Mathf.Clamp(fov, minFov, maxFov);
        GetComponent<Camera>().fieldOfView = fov;
    }
}
