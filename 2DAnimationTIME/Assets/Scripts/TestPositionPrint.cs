using UnityEngine;
using System.Collections;

public class TestPositionPrint : MonoBehaviour
{
    private RectTransform rt;

    void Start()
    {
        rt = GetComponent<RectTransform>();
    }

    // Update is called once per frame
    void Update()
    {
        //print(transform.position);

        print(rt.anchoredPosition);
    }
}
