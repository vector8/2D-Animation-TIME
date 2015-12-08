using UnityEngine;
using System.Collections;

public class AnimClickControl : MonoBehaviour
{
    public RawImageAnimator ria;

    void Start()
    {
        ria = GetComponent<RawImageAnimator>();
    }

    public void clicked()
    {
        ScreenManager.getScreenManager().goToAnimationEditScreen(ria.anim);
    }
}
