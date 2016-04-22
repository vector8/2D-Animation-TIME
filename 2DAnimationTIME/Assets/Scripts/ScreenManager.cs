using UnityEngine;
using System.Collections;

public class ScreenManager : MonoBehaviour
{
    public GameObject placeRfidScreenTop, animationListScreenTop, animationPreviewScreenTop, frameAnimationPreviewScreenTop, createNewAnimationScreenTop;
    public GameObject animationListScreenBottom, animationEditScreenBottom, frameEditScreenBottom, createNewAnimationScreenBottom;
    public TIME.Figurine currentFigurine;

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
    }

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
}
