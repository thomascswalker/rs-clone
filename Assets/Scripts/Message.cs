using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

namespace Message
{
    public class Message
    {
        static private Text message;

        static Message()
        {
            message = GameObject.FindWithTag("UIMessage").GetComponent<Text>();
        }

        public static void Clear()
        {
            message.text = "";
        }

        public static void Print(string text)
        {
            message.text += text + "\n";
        }
    }
}

