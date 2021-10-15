using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

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

    private Text console;

    private Ray ray;
    private RaycastHit hit;

    void Start()
    {
        console = GameObject.FindWithTag("UIConsole").GetComponent<Text>();
    }

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
            if (transform.localRotation.x < 0.5)
            {
                transform.RotateAround(target.transform.position, transform.right, cameraSpeed * Time.deltaTime);
            }
        }
        if (Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow))
        {
            if (transform.localRotation.x > 0.2)
            {
                transform.RotateAround(target.transform.position, transform.right, -cameraSpeed * Time.deltaTime);
            }
        }
        if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow))
        {
            transform.RotateAround(target.transform.position, Vector3.up, cameraSpeed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow))
        {
            transform.RotateAround(target.transform.position, Vector3.up, -cameraSpeed * Time.deltaTime);
        }


        console.text = "";
        Log(transform.localRotation.ToString());

        ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        if (Physics.Raycast(ray, out hit))
        {
            GameObject obj = hit.collider.gameObject;
            if (IsInteractive(obj))
            {
                Log("Interact with: " + hit.collider.name);
            }

            if (IsWalkable(obj))
            {
                Log("Walk to: " + hit.collider.name);
            }
        }
    }

    void Log(string text)
    {
        console.text += text + "\n";
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
