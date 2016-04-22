using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class FrameEditScreen : MonoBehaviour
{
    public RawImage previousFrameOnionSkin;
    public RawImage framePreview;
    public RawImageAnimator animPreview;
    public TIME.Animation currentAnim;
    public int currentFrameIndex;
    public bool batchEditMode = false;

    public void initialize(TIME.Animation anim, int frameID)
    {
        currentAnim = anim;
        currentFrameIndex = frameID;

        if (anim.frames.Count > 1)
        {
            previousFrameOnionSkin.enabled = true;
            int prevFrameID = (currentFrameIndex - 1);
            if (prevFrameID < 0)
            {
                prevFrameID += currentAnim.frames.Count;
            }
            previousFrameOnionSkin.texture = currentAnim.frames[prevFrameID].texture;
        }
        else
        {
            previousFrameOnionSkin.enabled = false;
        }

        framePreview.texture = currentAnim.frames[currentFrameIndex].texture;
        animPreview.anim = currentAnim;
    }

    public void setCurrentFrame(Texture2D tex, bool addNext = true)
    {
        TIME.Frame frame = currentAnim.frames[currentFrameIndex];
        frame.texture = tex;
        currentAnim.frames[currentFrameIndex] = frame;
        framePreview.texture = tex;

        if (batchEditMode && addNext)
        {
            StartCoroutine(DatabaseManager.getInstance().createFrame(currentAnim, currentFrameIndex));
            TIME.Frame newFrame = new TIME.Frame();
            DatabaseManager.getInstance().createdFrame = newFrame;
            previousFrameOnionSkin.enabled = true;
            previousFrameOnionSkin.texture = currentAnim.frames[currentFrameIndex].texture;
            newFrame.duration = frame.duration;
            currentFrameIndex = currentAnim.frames.Count;
            currentAnim.frames.Add(newFrame);
            framePreview.texture = currentAnim.frames[currentFrameIndex].texture;
        }
    }

    public void done()
    {
        if (currentAnim.frames[currentFrameIndex].id == -1)
        {
            DatabaseManager.getInstance().createdFrame = currentAnim.frames[currentFrameIndex];
            StartCoroutine(DatabaseManager.getInstance().createFrame(currentAnim, currentFrameIndex));
        }
        else
        {
            StartCoroutine(DatabaseManager.getInstance().updateFrame(currentAnim, currentFrameIndex));
        }

        ScreenManager.getInstance().goToAnimationEditScreen(currentAnim);
    }

    public void durationChanged(string durationString)
    {
        TIME.Frame frame = currentAnim.frames[currentFrameIndex];

        if (durationString.Length == 0)
        {
            frame.duration = 0;
        }
        else
        {
            frame.duration = float.Parse(durationString);
        }
        currentAnim.frames[currentFrameIndex] = frame;
    }

    public void deleteFrame()
    {
        StartCoroutine(DatabaseManager.getInstance().deleteFrame(currentAnim.frames[currentFrameIndex]));
        currentAnim.frames.RemoveAt(currentFrameIndex);
        ScreenManager.getInstance().goToAnimationEditScreen(currentAnim);
    }
}
