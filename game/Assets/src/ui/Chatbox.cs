using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

namespace UserInterface
{
    public class Chatbox : MonoBehaviour
    {
        public static Chatbox Instance {get; private set;}

        [SerializeField]
        private Font m_Font;

        private RectTransform m_Content;
        private List<GameObject> m_Items;

        // Start is called before the first frame update
        void Start()
        {
            Instance = this;

            ScrollRect scrollRect = this.GetComponent<ScrollRect>();
            m_Content = scrollRect.content;

            m_Items = new List<GameObject>();
        }

        public void Log(string message, Color? color = null)
        {
            // Create the new message object
            GameObject newMessage = new GameObject();
            newMessage.transform.SetParent(m_Content.transform);
            newMessage.SetActive(true);

            // Control the size of the object
            RectTransform rectTransform = newMessage.AddComponent<RectTransform>();
            rectTransform.sizeDelta = new Vector2(720, 32);

            // Add a canvas renderer so we can see the message
            newMessage.AddComponent<CanvasRenderer>();

            // Modify the text
            Text messageText = newMessage.AddComponent<Text>();
            string time = DateTime.Now.ToString("h:mm:ss tt");
            messageText.text = "[" + time + "] " + message;
            messageText.font = m_Font;
            messageText.fontSize = 24;
            messageText.color = color ?? Color.white;
        }
    }
}

