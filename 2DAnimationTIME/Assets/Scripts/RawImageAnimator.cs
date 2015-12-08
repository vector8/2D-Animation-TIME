using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using System.Collections.Generic;

[RequireComponent(typeof(RawImage))]
public class RawImageAnimator : MonoBehaviour
{
    private RawImage rawImage;
    private int currentFrameIndex = 0;
    private float timer = 0f;

    public TIME.Animation anim;

    void Start()
    {
        rawImage = GetComponent<RawImage>();
    }

    void Update()
    {
        if(anim == null || anim.frames.Count == 0)
        {
            rawImage.texture = null;
            return;
        }

        timer += Time.deltaTime;

        while(timer > anim.frames[currentFrameIndex].duration)
        {
            timer -= anim.frames[currentFrameIndex].duration;
            currentFrameIndex = (currentFrameIndex + 1) % anim.frames.Count;
        }

        rawImage.texture = anim.frames[currentFrameIndex].texture;
    }

    public void addNewFrame(Texture2D texture, float duration)
    {
        TIME.Frame newFrame;
        newFrame.texture = texture;
        newFrame.duration = duration;
        anim.frames.Add(newFrame);
    }

    public void updateFrame(int index, Texture2D texture, float duration)
    {
        if(index >= anim.frames.Count)
        {
            return;
        }

        TIME.Frame f = anim.frames[index];
        f.texture = texture;
        f.duration = duration;
        anim.frames[index] = f;
    }

    public void updateLatestFrame(Texture2D texture, float duration)
    {
        if(anim.frames.Count == 0)
        {
            return;
        }

        updateFrame(anim.frames.Count - 1, texture, duration);
    }
}
