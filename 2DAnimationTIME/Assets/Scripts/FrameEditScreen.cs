using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class FrameEditScreen : MonoBehaviour
{
    public RawImage previousFrameOnionSkin;
    public RawImage framePreview;
    public RawImageAnimator animPreview;
    public TIME.Animation currentAnim;
    public int currentFrameID;

    public void initialize(TIME.Animation anim, int frameID)
    {
        currentAnim = anim;
        currentFrameID = frameID;

        if (anim.frames.Count > 1)
        {
            previousFrameOnionSkin.enabled = true;
            int prevFrameID = (currentFrameID - 1);
            if(prevFrameID < 0)
            {
                prevFrameID += currentAnim.frames.Count;
            }
            previousFrameOnionSkin.texture = currentAnim.frames[prevFrameID].texture;
        }
        else
        {
            previousFrameOnionSkin.enabled = false;
        }

        framePreview.texture = currentAnim.frames[currentFrameID].texture;
        animPreview.anim = currentAnim;
    }

    public void setCurrentFrame(Texture2D tex)
    {
        TIME.Frame frame = currentAnim.frames[currentFrameID];
        frame.texture = tex;
        currentAnim.frames[currentFrameID] = frame;
        framePreview.texture = tex;
    }

    public void done()
    {
        ScreenManager.getScreenManager().goToAnimationEditScreen(currentAnim);
    }

    public void durationChanged(string durationString)
    {
        TIME.Frame frame = currentAnim.frames[currentFrameID];

        if (durationString.Length == 0)
        {
            frame.duration = 0;
        }
        else
        {
            frame.duration = float.Parse(durationString);
        }
        currentAnim.frames[currentFrameID] = frame;
    }

    public void deleteFrame()
    {
        currentAnim.frames.RemoveAt(currentFrameID);
        ScreenManager.getScreenManager().goToAnimationEditScreen(currentAnim);
    }
}
