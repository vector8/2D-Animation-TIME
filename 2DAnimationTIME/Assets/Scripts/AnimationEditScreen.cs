using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class AnimationEditScreen : MonoBehaviour
{
    public GameObject frameGroup;
    public GameObject framePrefab;
    public GameObject newFrameBtn;

    public void populateFrames(TIME.Animation anim)
    {
        foreach (Transform child in frameGroup.transform)
        {
            DestroyImmediate(child.gameObject);
        }

        for (int i = 0; i < anim.frames.Count; i++)
        {
            GameObject preview = Instantiate<GameObject>(framePrefab);
            preview.transform.SetParent(frameGroup.transform, false);
            RectTransform rt = preview.GetComponent<RectTransform>();
            rt.anchoredPosition = new Vector2((120 * (i % 6) + 50), -20 - (160 * (i / 6)));

            GameObject frameImage = preview.transform.FindChild("FrameImage").gameObject;
            GameObject durationGO = preview.transform.Find("Duration").gameObject;
            frameImage.GetComponent<RawImage>().texture = anim.frames[i].texture;
            durationGO.GetComponent<InputField>().text = anim.frames[i].duration.ToString();
        }

        RectTransform rectTransform = newFrameBtn.GetComponent<RectTransform>();
        rectTransform.anchoredPosition = new Vector2((120 * (anim.frames.Count % 6) + 50), -20 - (160 * (anim.frames.Count / 6)));
    }
}
