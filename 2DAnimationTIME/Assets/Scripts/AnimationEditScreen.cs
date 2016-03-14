using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class AnimationEditScreen : MonoBehaviour
{
    public GameObject frameGroup;
    public GameObject framePrefab;
    public GameObject newFrameBtn;

    public GameObject[] deletePrompt;

    public RawImageAnimator animPreview;

    private TIME.Animation currentAnim;

    public void populateFrames(TIME.Animation anim)
    {
        currentAnim = anim;

        foreach (Transform child in frameGroup.transform)
        {
            Destroy(child.gameObject);
        }

        for (int i = 0; i < anim.frames.Count; i++)
        {
            GameObject preview = Instantiate<GameObject>(framePrefab);
            preview.transform.SetParent(frameGroup.transform, false);
            RectTransform rt = preview.GetComponent<RectTransform>();
            rt.anchoredPosition = new Vector2((120 * (i % 6) + 50), -20 - (160 * (i / 6)));

            GameObject frameImage = preview.transform.FindChild("FrameImage").gameObject;
            GameObject durationGO = preview.transform.Find("Duration").gameObject;
            frameImage.GetComponent<RawImage>().texture = currentAnim.frames[i].texture;
            durationGO.GetComponent<InputField>().text = currentAnim.frames[i].duration.ToString();
            FrameControl fc = durationGO.GetComponent<FrameControl>();
            fc.frameID = i;
            fc.animEditScreen = this;
        }

        RectTransform rectTransform = newFrameBtn.GetComponent<RectTransform>();
        rectTransform.anchoredPosition = new Vector2((120 * (currentAnim.frames.Count % 6) + 50), -20 - (160 * (anim.frames.Count / 6)));

        animPreview.anim = currentAnim;
    }

    public void showDeletePrompt()
    {
        // show delete prompt
        foreach(GameObject g in deletePrompt)
        {
            g.SetActive(true);
        }
    }

    public void confirmDelete()
    {
        hideDeletePrompt();

        ScreenManager sm = ScreenManager.getInstance();
        sm.currentFigurine.animations.Remove(currentAnim);
        StartCoroutine(DatabaseManager.getInstance().deleteAnimation(currentAnim));
        sm.goToAnimationListScreen();
    }

    public void hideDeletePrompt()
    {
        // hide delete prompt
        foreach (GameObject g in deletePrompt)
        {
            g.SetActive(false);
        }
    }

    public void newFrame()
    {
        TIME.Frame frame = new TIME.Frame();
        frame.duration = 1f;
        int frameID = currentAnim.frames.Count;
        currentAnim.frames.Add(frame);
        ScreenManager.getInstance().goToFrameEditScreen(currentAnim, frameID);
    }

    public void frameDurationChanged(int frameID, float duration)
    {
        TIME.Frame frame = currentAnim.frames[frameID];
        frame.duration = duration;
        currentAnim.frames[frameID] = frame;
    }

    public void frameClicked(int frameID)
    {
        ScreenManager.getInstance().goToFrameEditScreen(currentAnim, frameID);
    }
}
