using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class NewFrameScreen : MonoBehaviour
{
    private Texture2D previousFrame;
    private Texture2D currentFrame;
    private bool animationUpdated = false;

    public RawImage previousFrameOnionSkin;
    public RawImage framePreview;
    public RawImageAnimator animationPreview;

    public void Initialize(Texture2D prevFrame, Texture2D frameToEdit = null)
    {
        previousFrame = prevFrame;
        currentFrame = frameToEdit;

        previousFrameOnionSkin.texture = previousFrame;
        framePreview.texture = currentFrame;

        animationUpdated = (currentFrame != null);
        framePreview.enabled = animationUpdated;
    }

    public void setCurrentFrame(Texture2D frame)
    {
        currentFrame = frame;

        if(!animationUpdated)
        {
            animationPreview.addNewFrame(frame, 0.5f);
        }
        else
        {
            //animationPreview.
        }
    }
}
