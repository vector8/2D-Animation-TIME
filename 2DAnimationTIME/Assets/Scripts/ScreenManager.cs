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

    public GameObject placeRfidScreenTop, animationListScreenTop, animationPreviewScreenTop, frameAnimationPreviewScreenTop, createNewAnimationScreenTop;
    public GameObject animationListScreenBottom, animationEditScreenBottom, frameEditScreenBottom, createNewAnimationScreenBottom;
    public ScreenStates currentState = ScreenStates.PLACE_RFID;

    public TIME.Figurine currentFigurine;
    public Texture2D testTexture, testTexture2, testTexture3;

    private static ScreenManager screenManager = null;

    public static ScreenManager getInstance()
    {
        if(screenManager == null)
        {
            screenManager = GameObject.Find("ScreenManager").GetComponent<ScreenManager>();
        }

        return screenManager;
    }

    void Start()
    {
        // The following is all test data.
        currentFigurine = new TIME.Figurine("680088977f");
        StartCoroutine(DatabaseManager.getInstance().getAnimations(currentFigurine));
        //TIME.Animation anim = new TIME.Animation("idle");
        //TIME.Frame frame = new TIME.Frame(), frame2 = new TIME.Frame(), frame3 = new TIME.Frame();
        //frame.texture = testTexture;
        //frame.duration = 0.5f;
        //frame2.texture = testTexture2;
        //frame2.duration = 0.5f;
        //frame3.texture = testTexture3;
        //frame3.duration = 0.5f;
        //anim.frames.Add(frame);
        //anim.frames.Add(frame2);
        //anim.frames.Add(frame3);
        //currentFigurine.animations.Add(anim);
    }

    //public void changeState(ScreenStates newState)
    //{
    //    currentState = newState;
    //    disableAllScreens();
    //    enableScreen(currentState);
    //}

    //private void disableAllScreens()
    //{
    //    placeRfidScreenTop.SetActive(false);
    //    animationListScreenTop.SetActive(false);
    //    animationPreviewScreenTop.SetActive(false);
    //    animationListScreenBottom.SetActive(false);
    //    animationEditScreenBottom.SetActive(false);
    //    frameEditScreenBottom.SetActive(false);
    //}

    public void goToHomeScreen()
    {
        animationListScreenTop.SetActive(false);
        animationPreviewScreenTop.SetActive(false);
        frameAnimationPreviewScreenTop.SetActive(false);
        createNewAnimationScreenTop.SetActive(false);
        animationListScreenBottom.SetActive(false);
        animationEditScreenBottom.SetActive(false);
        frameEditScreenBottom.SetActive(false);
        createNewAnimationScreenBottom.SetActive(false);

        placeRfidScreenTop.SetActive(true);
    }

    public void goToAnimationListScreen()
    {
        placeRfidScreenTop.SetActive(false);
        animationPreviewScreenTop.SetActive(false);
        frameAnimationPreviewScreenTop.SetActive(false);
        createNewAnimationScreenTop.SetActive(false);
        animationEditScreenBottom.SetActive(false);
        frameEditScreenBottom.SetActive(false);
        createNewAnimationScreenBottom.SetActive(false);

        animationListScreenTop.SetActive(true);
        animationListScreenBottom.SetActive(true);

        AnimationListScreen als = animationListScreenTop.GetComponent<AnimationListScreen>();
        als.populateAnimations();
    }

    public void createNewAnimation()
    {
        TIME.Animation anim = new TIME.Animation();
        DatabaseManager.getInstance().createdAnimation = anim;
        StartCoroutine(DatabaseManager.getInstance().createAnimation(currentFigurine.key));
        TIME.Frame frame = new TIME.Frame();
        frame.duration = 1f;
        DatabaseManager.getInstance().createdFrame = frame;
        anim.frames.Add(frame);
        currentFigurine.animations.Add(anim);
        goToFrameEditScreenBulk(anim, 0);
    }
    
    public void goToAnimationEditScreen(TIME.Animation anim)
    {
        placeRfidScreenTop.SetActive(false);
        animationListScreenTop.SetActive(false);
        frameAnimationPreviewScreenTop.SetActive(false);
        createNewAnimationScreenTop.SetActive(false);
        animationListScreenBottom.SetActive(false);
        frameEditScreenBottom.SetActive(false);
        createNewAnimationScreenBottom.SetActive(false);

        animationPreviewScreenTop.SetActive(true);
        animationEditScreenBottom.SetActive(true);

        AnimationEditScreen aes = animationEditScreenBottom.GetComponent<AnimationEditScreen>();
        aes.populateFrames(anim);
    }

    public void goToFrameEditScreen(TIME.Animation anim, int frameID)
    {
        placeRfidScreenTop.SetActive(false);
        animationListScreenTop.SetActive(false);
        animationPreviewScreenTop.SetActive(false);
        createNewAnimationScreenTop.SetActive(false);
        animationListScreenBottom.SetActive(false);
        animationEditScreenBottom.SetActive(false);
        createNewAnimationScreenBottom.SetActive(false);

        frameAnimationPreviewScreenTop.SetActive(true);
        frameEditScreenBottom.SetActive(true);

        FrameEditScreen fes = frameEditScreenBottom.GetComponent<FrameEditScreen>();
        fes.batchEditMode = false;
        fes.initialize(anim, frameID);
    }

    public void goToFrameEditScreenBulk(TIME.Animation anim, int frameID)
    {
        placeRfidScreenTop.SetActive(false);
        animationListScreenTop.SetActive(false);
        animationPreviewScreenTop.SetActive(false);
        frameAnimationPreviewScreenTop.SetActive(false);
        animationListScreenBottom.SetActive(false);
        animationEditScreenBottom.SetActive(false);
        frameEditScreenBottom.SetActive(false);

        createNewAnimationScreenTop.SetActive(true);
        createNewAnimationScreenBottom.SetActive(true);

        FrameEditScreen fes = createNewAnimationScreenBottom.GetComponent<FrameEditScreen>();
        fes.batchEditMode = true;
        fes.initialize(anim, frameID);
    }

    //private void enableScreen(ScreenStates newState)
    //{
    //    switch (newState)
    //    {
    //        case ScreenStates.PLACE_RFID:
    //            placeRfidScreenTop.SetActive(true);
    //            break;
    //        case ScreenStates.ANIMATION_LIST:
    //            animationListScreenTop.SetActive(true);
    //            animationListScreenBottom.SetActive(true);
    //            AnimationListScreen als = animationListScreenTop.GetComponent<AnimationListScreen>();
    //            als.populateAnimations();
    //            break;
    //        case ScreenStates.ANIMATION_EDIT:
    //            animationPreviewScreenTop.SetActive(true);
    //            animationEditScreenBottom.SetActive(true);
    //            break;
    //        case ScreenStates.FRAME_EDIT:
    //            animationPreviewScreenTop.SetActive(true);
    //            frameEditScreenBottom.SetActive(true);
    //            break;
    //        default:
    //            break;
    //    }
    //}
}
