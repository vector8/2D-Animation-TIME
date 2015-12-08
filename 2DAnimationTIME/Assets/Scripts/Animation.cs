using UnityEngine;
using System.Collections;
using System.Collections.Generic;

namespace TIME
{
    public class Animation
    {
        public List<TIME.Frame> frames;
        public string name;

        public Animation()
        {
            name = "";
            frames = new List<TIME.Frame>();
        }

        public Animation(string name)
        {
            frames = new List<TIME.Frame>();
            this.name = name;
        }
    }

    public struct Frame
    {
        public Texture2D texture;
        public float duration;
    }
}