using UnityEngine;
using System.Collections;

public class ScreenManager : MonoBehaviour
{
    public enum ScreenStates
    {
        PLACE_RFID,
        ANIMATION_LIST,
        ANIMATION_EDIT,
        FRAME_EDIT,
        NUMBER_SCREENS
    }

    public GameObject placeRfidScreenTop, animationListScreenTop, animationPreviewScreenTop;
    public GameObject animationListScreenBottom, animationEditScreenBottom, frameEditScreenBottom;
    public ScreenStates currentState = ScreenStates.PLACE_RFID;

    public TIME.Figurine currentFigurine;
    public Texture2D testTexture, testTexture2;

    private static ScreenManager screenManager = null;

    public static ScreenManager getScreenManager()
    {
        if(screenManager == null)
        {
            screenManager = GameObject.Find("ScreenManager").GetComponent<ScreenManager>();
        }

        return screenManager;
    }

    void Start()
    {
        currentFigurine = TIME.Figurine.getOrCreateByKey("testFigurine");
        TIME.Animation anim = new TIME.Animation("idle");
        TIME.Frame frame, frame2;
        frame.texture = testTexture;
        frame.duration = 0.5f;
        frame2.texture = testTexture2;
        frame2.duration = 0.5f;
        anim.frames.Add(frame);
        anim.frames.Add(frame2);
        currentFigurine.animations.Add(anim);
    }

    public void changeState(ScreenStates newState)
    {
        currentState = newState;
        disableAllScreens();
        enableScreen(currentState);
    }

    private void disableAllScreens()
    {
        placeRfidScreenTop.SetActive(false);
        animationListScreenTop.SetActive(false);
        animationPreviewScreenTop.SetActive(false);
        animationListScreenBottom.SetActive(false);
        animationEditScreenBottom.SetActive(false);
        frameEditScreenBottom.SetActive(false);
    }

    private void enableScreen(ScreenStates newState)
    {
        switch (newState)
        {
            case ScreenStates.PLACE_RFID:
                placeRfidScreenTop.SetActive(true);
                break;
            case ScreenStates.ANIMATION_LIST:
                animationListScreenTop.SetActive(true);
                animationListScreenBottom.SetActive(true);
                AnimationListScreen als = animationListScreenTop.GetComponent<AnimationListScreen>();
                als.populateAnimations(currentFigurine);
                break;
            case ScreenStates.ANIMATION_EDIT:
                animationPreviewScreenTop.SetActive(true);
                animationEditScreenBottom.SetActive(true);
                break;
            case ScreenStates.FRAME_EDIT:
                animationPreviewScreenTop.SetActive(true);
                frameEditScreenBottom.SetActive(true);
                break;
            default:
                break;
        }
    }
}
