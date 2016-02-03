using UnityEngine;
using System;
using System.Collections;

public class DatabaseManager : MonoBehaviour
{
    public string databaseAddress = "localhost";

    private static DatabaseManager databaseManager = null;

    public static DatabaseManager getInstance()
    {
        if (databaseManager == null)
        {
            databaseManager = GameObject.Find("DatabaseManager").GetComponent<DatabaseManager>();
        }

        return databaseManager;
    }

    public IEnumerator getAnimations(string rfidKey)
    {
        string url = "http://" + databaseAddress + "/playtime/getAnimations.php";

        WWWForm form = new WWWForm();

        form.AddField("rfidKey", rfidKey);

        WWW www = new WWW(url, form);

        yield return www;

        string[] delimiters = { "<br>" };
        string[] results = www.text.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);
        if (results.Length == 0)
        {
            // Figurine does not exist or has no animations in the database.
        }
        else
        {
            // for each animation associated to this figurine
            for (int i = 0; i < results.Length; i++)
            {
                print(results[i]);
                string[] delim = { "," };
                string[] vals = results[i].Split(delim, StringSplitOptions.None);

                // do something with results[0], results[1], etc.
                //yield return StartCoroutine(addComponentByName(p.first, p.second, vals[1], vals[2], vals[3], vals[4], vals[5], vals[6]));
            }
        }
    }

    public IEnumerator createAnimation(/*string rfidKey,*/ TIME.Animation anim)
    {
        string url = "http://" + databaseAddress + "/playtime/createAnimation.php";

        //WWWForm form = new WWWForm();

        //form.AddField("rfidKey", rfidKey);

        WWW www = new WWW(url);//, form);

        yield return www;

        //string[] delimiters = { "<br>" };
        //string[] results = www.text.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);
        //if (results.Length == 0)
        //{
        //    // An has error occurred...
        //}
        //else
        //{
        //Debug.Log(www.text);
        anim.id = int.Parse(www.text);
        //}
    }

    public IEnumerator createFrame(TIME.Animation anim, int index)
    {
        string url = "http://" + databaseAddress + "/playtime/createFrame.php";

        WWWForm form = new WWWForm();

        byte[] frameData = anim.frames[index].getBytes();

        form.AddField("animID", anim.id);
        form.AddField("frameIndex", index);
        form.AddField("duration", anim.frames[index].durationMillis());
        form.AddField("frameDataLength", frameData.Length);
        form.AddBinaryData("frameData", frameData);

        WWW www = new WWW(url, form);

        yield return www;

        anim.frames[index].id = int.Parse(www.text);
    }

    public IEnumerator updateFrame(TIME.Animation anim, int index)
    {
        string url = "http://" + databaseAddress + "/playtime/updateFrame.php";

        WWWForm form = new WWWForm();

        form.AddField("id", anim.frames[index].id);
        form.AddField("frameIndex", index);
        form.AddField("duration", anim.frames[index].durationMillis());
        form.AddBinaryData("data", anim.frames[index].getBytes());

        WWW www = new WWW(url, form);

        yield return www;
    }
}
