using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UserInterface;

[ExecuteInEditMode]
abstract class InteractiveObject : MonoBehaviour
{
    public enum Types {Object, Resource, Npc, Enemy}

    public Types type = Types.Object;
    public string actionName;
    public bool rescan = false;
    private Outline outline;
    private Color color;
    public Chatbox chatbox;

    public void Start()
    {
        outline = gameObject.GetComponent<Outline>();
        outline.enabled = false;

        chatbox = GameObject.Find("Chatbox").GetComponent<Chatbox>();

        switch (type)
        {
            case Types.Object:
                color = new Color(38f/255f, 198f/255f, 218f/255f);
                break;
            case Types.Resource:
                color = new Color(251f/255f, 140f/255f, 0f/255f);
                break;
            case Types.Npc:
                color = new Color(255f/255f, 255f/255f, 0f/255f);
                break;
            case Types.Enemy:
                color = new Color(255f/255f, 23f/255f, 68f/255f);
                break;
            default:
                break;
        }

        outline.OutlineColor = color;
    }

    abstract public void ExecuteAction();

    protected string GetConsoleText()
    {
        return actionName + " <color=#" + ColorUtility.ToHtmlStringRGB(color) + "><b>" + gameObject.name + "</b></color>";
    }

    public void OnMouseOver()
    {
        outline.enabled = true;
    }

    private void OnMouseExit()
    {
        outline.enabled = false;
    }
}