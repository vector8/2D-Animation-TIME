using UnityEngine;
using System;
using System.Collections;

public class DatabaseManager : MonoBehaviour
{
    public string databaseAddress;

    private static DatabaseManager databaseManager = null;

    public TIME.Animation createdAnimation;
    public TIME.Frame createdFrame;

    public static DatabaseManager getInstance()
    {
        if (databaseManager == null)
        {
            databaseManager = GameObject.Find("DatabaseManager").GetComponent<DatabaseManager>();
        }

        return databaseManager;
    }

    public IEnumerator getAnimations(TIME.Figurine figurine)
    {
        string url = "http://" + databaseAddress + "/playtime/getAnimations.php";

        WWWForm form = new WWWForm();

        form.AddField("rfidKey", figurine.key);

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

                int animID;
                if(int.TryParse(results[i], out animID))
                {
                    TIME.Animation anim = new TIME.Animation();
                    anim.id = animID;

                    yield return StartCoroutine(getFrames(anim));

                    figurine.animations.Add(anim);
                }

                // do something with results[0], results[1], etc.
                //yield return StartCoroutine(addComponentByName(p.first, p.second, vals[1], vals[2], vals[3], vals[4], vals[5], vals[6]));
            }
        }
    }

    public IEnumerator createAnimation(string rfidKey)
    {
        string url = "http://" + databaseAddress + "/playtime/createAnimation.php";

        WWWForm form = new WWWForm();

        form.AddField("rfidKey", rfidKey);

        WWW www = new WWW(url, form);

        yield return www;

        if(createdAnimation != null)
        {
            if (!int.TryParse(www.text, out createdAnimation.id))
            {
                print(www.text);
            }
        }
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

        while (!www.isDone && www.error == null) ;

        if (createdFrame != null)
        {
            if(!int.TryParse(www.text, out createdFrame.id))
            {
                print(www.text);
            }
        }

        yield return null;
    }

    public IEnumerator updateFrame(TIME.Animation anim, int index)
    {
        string url = "http://" + databaseAddress + "/playtime/updateFrame.php";

        WWWForm form = new WWWForm();

        byte[] frameData = anim.frames[index].getBytes();

        form.AddField("id", anim.frames[index].id);
        form.AddField("frameIndex", index);
        form.AddField("duration", anim.frames[index].durationMillis());
        form.AddField("frameDataLength", frameData.Length);
        form.AddBinaryData("data", frameData);

        WWW www = new WWW(url, form);

        yield return www;
    }

    public IEnumerator getFrames(TIME.Animation anim)
    {
        string url = "http://" + databaseAddress + "/playtime/getFrames.php";

        WWWForm form = new WWWForm();

        form.AddField("animID", anim.id);

        WWW www = new WWW(url, form);

        yield return www;

        string[] delimiters = { "<br>" };
        string[] results = www.text.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);

        if (results.Length == 0)
        {
            // Animation has no frames in the database.
        }
        else
        {
            TIME.Frame[] frames = new TIME.Frame[results.Length];
            // for each frame of this animation
            for (int i = 0; i < results.Length; i++)
            {
                print(results[i]);

                int frameID;
                string[] delim = { "," };
                string[] vals = results[i].Split(delim, StringSplitOptions.None);
                if (int.TryParse(vals[0], out frameID))
                {
                    TIME.Frame frame = new TIME.Frame();
                    frame.id = frameID;
                    int index = int.Parse(vals[1]);
                    frame.duration = int.Parse(vals[2]) / 1000f;

                    yield return StartCoroutine(getFrameData(frame));

                    frames[index] = frame;
                }
            }

            // Now add the frames to the animation in the correct order
            // just in case they were not retrieve in the correct order on the DB
            for(int i = 0; i < frames.Length; i++)
            {
                anim.frames.Add(frames[i]);
            }
        }
    }

    public IEnumerator getFrameData(TIME.Frame frame)
    {
        string url = "http://" + databaseAddress + "/playtime/getFrameData.php";

        WWWForm form = new WWWForm();

        form.AddField("frameID", frame.id);

        WWW www = new WWW(url, form);

        yield return www;

        // Set the frame data using the downloaded bytes
        frame.setBytes(www.bytes);
    }

    public IEnumerator deleteAnimation(TIME.Animation anim)
    {
        string url = "http://" + databaseAddress + "/playtime/deleteAnimation.php";

        WWWForm form = new WWWForm();

        form.AddField("animID", anim.id);

        WWW www = new WWW(url, form);

        yield return www;
    }

    public IEnumerator deleteFrame(TIME.Frame frame)
    {
        string url = "http://" + databaseAddress + "/playtime/deleteFrame.php";

        WWWForm form = new WWWForm();

        form.AddField("frameID", frame.id);

        WWW www = new WWW(url, form);

        yield return www;
    }
}
