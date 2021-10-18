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
            Message.Message.Print("Opening door.");
            door.Play("DoorOpen", 0, 0.0f);
            // gameObject.SetActive(false);
            open = true;
            actionName = "Close";
        }
        else
        {
            Message.Message.Print("Closing door.");
            door.Play("DoorClose", 0, 0.0f);
            // gameObject.SetActive(false);
            open = false;
            actionName = "Open";
        }
    }

    public override void OnMouseOver()
    {
        string text = actionName + " <color=cyan><b>" + gameObject.name + "</b></color>";
        Console.Console.Print(text);
    }
}
