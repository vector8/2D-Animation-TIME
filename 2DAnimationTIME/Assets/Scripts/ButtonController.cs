using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ButtonController : MonoBehaviour
{
    public Button grabCutButton;

    public SproutPluginWrapper sproutWrapper;
    public GrabCutPluginWrapper grabCutWrapper;

    private string outputFilePath;

    public void getImageFromSprout()
    {
        outputFilePath = sproutWrapper.captureSproutImage();
        grabCutButton.interactable = true;
    }

    public void runGrabCut()
    {
        grabCutWrapper.runGrabCut(outputFilePath);
    }
}
