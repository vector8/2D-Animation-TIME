using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ButtonController : MonoBehaviour
{
    public RawImage framePreview;
    public GameObject loadingTxt, buttonGroup;
    public FrameEditScreen frameEditScreen;

    /// Test variables ///
    public bool usingSprout = true;
    public Texture2D testTexture = null;

    public void getImageFromSprout()
    {
        setLoadingState(true);
        StartCoroutine(getFrameFromSprout());
    }

    public void getImageFromSproutAndReturn()
    {
        setLoadingState(true);
        StartCoroutine(getFrameFromSprout(true));
    }

    private void setLoadingState(bool loading)
    {
        loadingTxt.SetActive(loading);
        //buttonGroup.SetActive(!loading);
        framePreview.enabled = !loading;
    }

    private IEnumerator getFrameFromSprout(bool goBackToAnimEditScreen = false)
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
        frameEditScreen.setCurrentFrame(texture, !goBackToAnimEditScreen);
        if(goBackToAnimEditScreen)
        {
            frameEditScreen.done();
        }
        yield return null;
    }
}
