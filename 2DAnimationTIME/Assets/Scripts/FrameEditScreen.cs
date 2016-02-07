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
    public InputField durationField;
    public bool batchEditMode = false;

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
        durationField.text = currentAnim.frames[currentFrameID].duration.ToString();
    }

    public void setCurrentFrame(Texture2D tex, bool addNext = true)
    {
        TIME.Frame frame = currentAnim.frames[currentFrameID];
        frame.texture = tex;
        currentAnim.frames[currentFrameID] = frame;
        framePreview.texture = tex;

        if(batchEditMode && addNext)
        {
            StartCoroutine(DatabaseManager.getInstance().createFrame(currentAnim, currentFrameID));
            previousFrameOnionSkin.enabled = true;
            previousFrameOnionSkin.texture = currentAnim.frames[currentFrameID].texture;
            TIME.Frame newFrame = new TIME.Frame();
            newFrame.duration = frame.duration;
            currentFrameID = currentAnim.frames.Count;
            currentAnim.frames.Add(newFrame);
            framePreview.texture = currentAnim.frames[currentFrameID].texture;
            durationField.text = currentAnim.frames[currentFrameID].duration.ToString();
        }
    }

    public void done()
    {
        if(currentAnim.frames[currentFrameID].id == -1)
        {
            StartCoroutine(DatabaseManager.getInstance().createFrame(currentAnim, currentFrameID));
        }
        else
        {
            StartCoroutine(DatabaseManager.getInstance().updateFrame(currentAnim, currentFrameID));
        }

        ScreenManager.getInstance().goToAnimationEditScreen(currentAnim);
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
        ScreenManager.getInstance().goToAnimationEditScreen(currentAnim);
    }
}
