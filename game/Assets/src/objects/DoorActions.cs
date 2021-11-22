using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UserInterface;

public class DoorActions : ActionHandler
{
    private Animator animator;
    private bool open = false;

    void Start()
    {
        animator = gameObject.GetComponent<Animator>();
    }

    public void Close()
    {
        // If the door is open...
        if (open)
        {
            // Play the closing door animation
            animator.Play("DoorClose", 0, 0.0f);

            // Set the open state to false
            open = false;

            // Flavor text
            Chatbox.Instance.Log("You close the door.", color: Color.red);

            // Swap the first action with Open
            parent.SetActionName("Open", 0);
        }
    }

    public void Open()
    {
        // If the door is closed...
        if (!open)
        {
            // Play the opening door animation
            animator.Play("DoorOpen", 0, 0.0f);

            // Set the open state to true
            open = true;

            // Flavor text
            Chatbox.Instance.Log("You open the door.");

            // Swap the first action with Close
            parent.SetActionName("Close", 0);
        }
    }
}
