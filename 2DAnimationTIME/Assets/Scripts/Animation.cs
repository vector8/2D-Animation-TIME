using UnityEngine;
using System.Collections;
using System.Collections.Generic;

namespace TIME
{
    public class Animation
    {
        public int id = -1;
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

    public class Frame
    {
        public int id = -1;
        public Texture2D texture;
        public float duration;

        public int durationMillis()
        {
            return (int)(duration * 1000);
        }

        public byte[] getBytes()
        {
            Color32[] colors = texture.GetPixels32();
            byte[] result = new byte[colors.Length * 3];

            for (int i = 0; i < colors.Length; i++)
            {
                result[i * 3] = colors[i].r;
                result[i * 3 + 1] = colors[i].g;
                result[i * 3 + 2] = colors[i].b;
            }

            return result;
        }
    }
}