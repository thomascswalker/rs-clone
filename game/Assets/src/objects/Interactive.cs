using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UserInterface;

[System.Serializable]
public class Interactive : MonoBehaviour
{
    public enum Types {Object, Resource, Npc, Enemy}

    
    public Types type;
    public string displayName;

    [SerializeField]
    private List<Action> m_Actions = new List<Action>();
    public List<Action> actions {
        get {
            return m_Actions;
        }
    }
    protected ActionHandler actionHandler;

    private Color color;
    protected Outline outline;
    protected Text status;

    public void Start()
    {
        outline = gameObject.AddComponent<Outline>();
        outline.enabled = false;
        outline.OutlineWidth = 4;

        actionHandler = gameObject.GetComponent<ActionHandler>();
        actionHandler.parent = this;
        foreach (Action action in m_Actions)
        {
            action.SetHandler(actionHandler);
        }

        status = GameObject.Find("Status").GetComponent<Text>();

        switch (type)
        {
            case Types.Object:
                // Cyan
                color = new Color(38f/255f, 198f/255f, 218f/255f);
                break;
            case Types.Resource:
                // Orange
                color = new Color(251f/255f, 140f/255f, 0f/255f);
                break;
            case Types.Npc:
                // Yellow
                color = new Color(255f/255f, 255f/255f, 0f/255f);
                break;
            case Types.Enemy:
                // Red
                color = new Color(255f/255f, 23f/255f, 68f/255f);
                break;
            default:
                break;
        }

        // Set the outline color to the object type color
        outline.OutlineColor = color;
    }
    
    public void OnMouseEnter()
    {
        outline.enabled = true;
        status.text = GetConsoleText();
    }

    public void OnMouseExit()
    {
        outline.enabled = false;
        status.text = "";
    }

    /// <summary>
    /// Executes the given action (by index) from the list of actions.
    /// </summary>
    /// <param name="index">The index to execute. Defaults to 0.</param>
    public virtual void ExecuteAction(int index = 0)
    {
        if (m_Actions.Count < index)
        {
            string message = $"Index {index} not found in actions list.";
            throw new IndexOutOfRangeException(message);
        }

        Action action = m_Actions[index];
        action.Execute();
    }

    public void SetActionName(string name, int index)
    {
        if (m_Actions.Count < index)
        {
            throw new ArgumentOutOfRangeException("Out of range!");
        }

        m_Actions[index].m_ActionName = name;
    }

    protected string GetConsoleText()
    {
        return m_Actions[0].m_ActionName +
                " <color=#" +
                ColorUtility.ToHtmlStringRGB(color) +
                "><b>" + displayName +
                "</b></color>";
    }
}