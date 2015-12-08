using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class OnClickSendEnum : MonoBehaviour
{
    public ScreenManager.ScreenStates targetState;
    public ScreenManager screenManager;

    void Start()
    {
        screenManager = ScreenManager.getScreenManager();
        Button btn = GetComponent<Button>();
        btn.onClick.AddListener(() =>
            {
                //screenManager.changeState(targetState);
            });
    }
}
