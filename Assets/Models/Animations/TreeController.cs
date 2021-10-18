using System.Collections;
using System.Collections.Generic;
using UnityEngine;

class TreeController : InteractiveObject
{
    public override void ExecuteAction()
    {
        Debug.Log("Executing action");
    }

    public override void OnMouseOver()
    {
        Console.Console.Print(GetConsoleText());
    }
}
