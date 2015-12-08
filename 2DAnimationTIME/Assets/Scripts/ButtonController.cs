using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ButtonController : MonoBehaviour
{
    public Button removeBackgroundBtn;
    public RawImage framePreview;
    public GameObject loadingTxt, buttonGroup;
    public FrameEditScreen frameEditScreen;

    /// Test variables ///
    public bool usingSprout = true;
    public Texture2D testTexture = null;

    public void getImageFromSprout()
    {
        setLoadingState(true);
        Debug.Log("starting coroutine");
        StartCoroutine(getFrameFromSprout());
        Debug.Log("coroutine started");
    }

    public void removeBackground()
    {
    }

    public void done()
    {
        // Return image to 'edit animation' screen.

        // animationEditScreen.addNewFrame(framePreview);
        // someScreenManager.popScreen(); / .setScreen(ANIMATION_EDIT);
    }

    private void setLoadingState(bool loading)
    {
        loadingTxt.SetActive(loading);
        buttonGroup.SetActive(!loading);
        framePreview.enabled = !loading;
    }

    private IEnumerator getFrameFromSprout()
    {
        yield return new WaitForSeconds(0.5f);
        Texture2D texture;
        if (usingSprout)
        {
            texture = SproutExtension.captureFrame();
        }
        else
        {
            texture = testTexture;
        }
        setLoadingState(false);
        Debug.Log("coroutine finished");
        frameEditScreen.setCurrentFrame(texture);
        yield return null;
    }
}
