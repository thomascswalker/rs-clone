using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

namespace Console
{
    public class Console
    {
        static private Text console;

        static Console()
        {
            console = GameObject.FindWithTag("UIConsole").GetComponent<Text>();
        }

        public static void Clear()
        {
            console.text = "";
        }

        public static void Print(string text)
        {
            console.text = text;
        }
    }
}

