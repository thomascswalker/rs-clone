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
            Message.Message.Print("You open the door.");
            door.Play("DoorOpen", 0, 0.0f);
            // gameObject.SetActive(false);
            open = true;
            actionName = "Close";
        }
        else 
        {
            Message.Message.Print("You close the door.");
            door.Play("DoorClose", 0, 0.0f);
            // gameObject.SetActive(false);
            open = false;
            actionName = "Open";
        }
    }
}
