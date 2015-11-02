using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class SproutPluginWrapper : MonoBehaviour
{
    private const string DLL_NAME = "SproutPlugin";

    [DllImport(DLL_NAME)]
    private static extern void captureImageFromSprout(string outputFilePath);

    public string captureSproutImage()
    {
        string outputFilePath = "C:\\2DAnimStationTest\\" + System.DateTime.Now.ToString("yyyyMMddHHmmssffff") + ".bmp";

        captureImageFromSprout(outputFilePath);

        return outputFilePath;
    }
}
