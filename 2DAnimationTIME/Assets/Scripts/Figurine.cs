using UnityEngine;
using System;
using System.Collections.Generic;

namespace TIME
{
    public class Figurine
    {
        public List<TIME.Animation> animations;
        public string key;

        public Figurine(string key)
        {
            this.key = key;
            animations = new List<TIME.Animation>();
        }
    }
}
