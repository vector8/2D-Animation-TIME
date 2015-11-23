using UnityEngine;
using System.Collections;

public class AnimationListScreen : MonoBehaviour
{
    public GameObject animationGroup;
    public GameObject previewPrefab;

    public void populateAnimations(TIME.Figurine fig)
    {
        foreach(Transform child in animationGroup.transform)
        {
            DestroyImmediate(child.gameObject);
        }

        for (int i = 0; i < fig.animations.Count; i++)
        {
            GameObject preview = Instantiate<GameObject>(previewPrefab);
            preview.transform.SetParent(animationGroup.transform, false);
            RectTransform rt = preview.GetComponent<RectTransform>();
            rt.anchoredPosition = new Vector2((120 * (i % 6) + 100), -150 - (120 * (i / 6)));

            RawImageAnimator riAnim = preview.GetComponent<RawImageAnimator>();
            riAnim.anim = fig.animations[i];
        }
    }
}
