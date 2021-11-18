using System.Collections;
using System.Collections.Generic;
using UnityEngine;

class DoorController : InteractiveObject
{
    [SerializeField] private Animator door = null;
    [SerializeField] private bool open = false;

    public override void ExecuteAction()
    {
        if (!open)
        {
            door.Play("DoorOpen", 0, 0.0f);
            open = true;
            actionName = "Close";
            chatbox.Log("You open the door.");
        }
        else 
        {
            door.Play("DoorClose", 0, 0.0f);
            open = false;
            actionName = "Open";
            chatbox.Log("You close the door.");
        }
    }
}
