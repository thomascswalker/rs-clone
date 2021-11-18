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
        [SerializeField]
        private Font mFont;

        private RectTransform mContent;
        private List<GameObject> mMessageItems;

        // Start is called before the first frame update
        void Start()
        {
            ScrollRect scrollRect = this.GetComponent<ScrollRect>();
            mContent = scrollRect.content;

            mMessageItems = new List<GameObject>();
        }

        void Update()
        {

        }

        public void Log(string message)
        {
            // Create the new message object
            GameObject newMessage = new GameObject();
            newMessage.transform.SetParent(mContent.transform);
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
            messageText.font = mFont;
            messageText.fontSize = 24;
            messageText.color = Color.white;
        }
    }
}

