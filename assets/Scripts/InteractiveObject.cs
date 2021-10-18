using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using Console;
using Message;

abstract class InteractiveObject : MonoBehaviour
{
    public string actionName;

    abstract public void ExecuteAction();
    abstract public void OnMouseOver();

    private void OnMouseExit()
    {
        Console.Console.Clear();
    }

    private void OnMouseDown()
    {
        ExecuteAction();
    }
}