using UnityEngine;
using System.Collections;
using System.Collections.Generic;

namespace TIME
{
    public class Figurine
    {
        public List<TIME.Animation> animations;
        public string key;

        private static Dictionary<string, Figurine> figurines = new Dictionary<string, Figurine>();

        public Figurine(string key)
        {
            this.key = key;
            animations = new List<TIME.Animation>();
        }

        public static Figurine getOrCreateByKey(string key)
        {
            Figurine f;
            if(!figurines.TryGetValue(key, out f))
            {
                f = new Figurine(key);
                figurines.Add(key, f);
            }

            return f;
        }
    }
}
