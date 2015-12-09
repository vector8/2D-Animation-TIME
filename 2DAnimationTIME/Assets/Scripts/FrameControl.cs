using UnityEngine;
using System.Collections;

public class FrameControl : MonoBehaviour
{
    public int frameID = 0;
    public AnimationEditScreen animEditScreen;

    public void durationChanged(string durationString)
    {
        if(animEditScreen == null)
        {
            return;
        }

        float duration;
        
        if(durationString.Length == 0)
        {
            duration = 0;
        }
        else
        {
            duration = float.Parse(durationString);
        }
        animEditScreen.frameDurationChanged(frameID, duration);
    }

    public void clickHandler()
    {
        animEditScreen.frameClicked(frameID);
    }
}
