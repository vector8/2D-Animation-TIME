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
            byte[] result = new byte[colors.Length * 4];

            for (int i = 0; i < colors.Length; i++)
            {
                result[i * 4] = colors[i].r;
                result[i * 4 + 1] = colors[i].g;
                result[i * 4 + 2] = colors[i].b;
                result[i * 4 + 3] = colors[i].a;
            }

            return result;
        }

        public void setBytes(byte[] bytes)
        {
            Color32[] colors = new Color32[bytes.Length / 4];

            int length = (int) Mathf.Sqrt(colors.Length);
            texture = new Texture2D(length, length, TextureFormat.ARGB32, false);
            texture.filterMode = FilterMode.Point;

            for (int i = 0; i < colors.Length; i++)
            {
                colors[i].r = bytes[i * 4];
                colors[i].g = bytes[i * 4 + 1];
                colors[i].b = bytes[i * 4 + 2];
                colors[i].a = bytes[i * 4 + 3];
            }

            texture.SetPixels32(colors);
            texture.Apply();
        }
    }
}