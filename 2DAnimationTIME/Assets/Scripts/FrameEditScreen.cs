using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class FrameEditScreen : MonoBehaviour
{
    private bool animationUpdated = false;

    public RawImage previousFrameOnionSkin;
    public RawImage framePreview;
    public TIME.Animation currentAnim;
    public int currentFrameID;

    public void initialize(TIME.Animation anim, int frameID)
    {
        currentAnim = anim;
        currentFrameID = frameID;

        if (currentFrameID > 0)
        {
            previousFrameOnionSkin.enabled = true;
            previousFrameOnionSkin.texture = currentAnim.frames[currentFrameID - 1].texture;
        }
        else
        {
            previousFrameOnionSkin.enabled = false;
        }

        framePreview.texture = currentAnim.frames[currentFrameID].texture;
    }

    public void setCurrentFrame(Texture2D tex)
    {
        TIME.Frame frame = currentAnim.frames[currentFrameID];
        frame.texture = tex;
        currentAnim.frames[currentFrameID] = frame;
        framePreview.texture = currentAnim.frames[currentFrameID].texture;
    }
}
