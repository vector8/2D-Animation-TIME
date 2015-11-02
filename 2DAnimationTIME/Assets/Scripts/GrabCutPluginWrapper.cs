using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class GrabCutPluginWrapper : MonoBehaviour
{
    private const string DLL_NAME = "GrabCutPlugin";

    [DllImport(DLL_NAME)]
    private static extern void run(string filename);

    public void runGrabCut(string filename)
    {
        run(filename);
    }
}
