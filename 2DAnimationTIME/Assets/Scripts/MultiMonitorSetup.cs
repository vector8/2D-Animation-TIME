using UnityEngine;
using System.Collections;

public class MultiMonitorSetup : MonoBehaviour 
{
	public Vector2 topScreenResolution;
	public Vector2 bottomScreenResolution;
	public Camera topCam;
	public Camera bottomCam;

	// Use this for initialization
	void Start () 
	{
		float totalYResolution = topScreenResolution.y + bottomScreenResolution.y;
		Screen.SetResolution((int)Mathf.Min(topScreenResolution.x, bottomScreenResolution.x), 
		                     (int)totalYResolution, 
		                     false);
		
		Rect rect = bottomCam.rect;
		rect.height = bottomScreenResolution.y / totalYResolution;
		bottomCam.rect = rect;

		rect = topCam.rect;
		rect.height = topScreenResolution.y / totalYResolution;
		rect.y = 1f - rect.height;
		topCam.rect = rect;
	}
}
