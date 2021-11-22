using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using UnityEngine;

[System.Serializable]
public class Action
{
    public string m_ActionName;
    private ActionHandler m_Handler;

    public void SetHandler(ActionHandler handler)
    {
        m_Handler = handler;
    }

    public void Execute()
    {
        if (m_Handler != null)
        {
            MethodInfo info = m_Handler.GetType().GetMethod(m_ActionName);
            if (info != null)
            {
                info.Invoke(m_Handler, null);
            }
        }
    }
}
