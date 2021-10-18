using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using Console;
using Message;

abstract class InteractiveObject : MonoBehaviour
{
    public string actionName;
    public string color;

    abstract public void ExecuteAction();
    abstract public void OnMouseOver();

    protected string GetConsoleText()
    {
        return actionName + " <color=" + color + "><b>" + gameObject.name + "</b></color>";
    }

    private void OnMouseExit()
    {
        Console.Console.Clear();
    }

    private void OnMouseDown()
    {
        ExecuteAction();
    }
}