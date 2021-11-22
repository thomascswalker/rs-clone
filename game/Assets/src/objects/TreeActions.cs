using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UserInterface;

public class TreeActions : ActionHandler
{
    public void Chop()
    {
        Chatbox.Instance.Log("You begin chopping the tree...", color: Color.green);
    }
}
