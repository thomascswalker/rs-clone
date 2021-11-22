using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UserInterface;

public class ActionHandler : MonoBehaviour
{
    protected Interactive m_Parent;
    public Interactive parent {
        get {
            return m_Parent;
        }
        set {
            m_Parent = value;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        m_Parent = gameObject.GetComponent<Interactive>();
    }
}
