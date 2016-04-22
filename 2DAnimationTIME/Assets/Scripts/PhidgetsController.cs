using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using Phidgets;

public class PhidgetsController : MonoBehaviour
{
    public ScreenManager screenManager;

    private RFID reader;
    private bool tagFound = false;
    private bool tagPresent = false;
    private DatabaseManager dbMgr;
    private bool waitingForAnimations = false;

    // Use this for initialization
    void Start()
    {
        screenManager = FindObjectOfType<ScreenManager>();
        dbMgr = DatabaseManager.getInstance();
        reader = new RFID();
        reader.Tag += tagAdded;
        reader.TagLost += tagRemoved;
        reader.Attach += rfidAttached;
        reader.Detach += rfidDetached;
        reader.Error += rfidError;
        reader.open();
    }

    // Update is called once per frame
    void Update()
    {
        if(waitingForAnimations && dbMgr.doneFetchingAnimations)
        {
            dbMgr.doneFetchingAnimations = false;
            waitingForAnimations = false;
            screenManager.goToAnimationListScreen();
        }
        else if(!waitingForAnimations && dbMgr.doneFetchingAnimations)
        {
            dbMgr.doneFetchingAnimations = false;
        }

        if (tagFound && !tagPresent)
        {
            tagPresent = true;
            waitingForAnimations = true;
            screenManager.currentFigurine = new TIME.Figurine(reader.LastTag);
            StartCoroutine(dbMgr.getAnimations(screenManager.currentFigurine));
        }
        else if (!tagFound && tagPresent)
        {
            waitingForAnimations = false;
            tagPresent = false;
            screenManager.goToHomeScreen();
        }
    }

    private void rfidError(object sender, Phidgets.Events.ErrorEventArgs e)
    {
        print("ERROR: " + e.Description);
    }

    private void rfidAttached(object sender, Phidgets.Events.AttachEventArgs e)
    {
        print("RFID reader attached.");
        print("Name: " + reader.Name);

        print(reader.Antenna);
    }

    private void rfidDetached(object sender, Phidgets.Events.DetachEventArgs e)
    {
        print("RFID reader detached.");
    }

    private void tagAdded(object sender, Phidgets.Events.TagEventArgs e)
    {
        print("Tag found!");
        print("Tag: " + e.Tag);

        tagFound = true;
    }

    private void tagRemoved(object sender, Phidgets.Events.TagEventArgs e)
    {
        print("Tag removed!");

        tagFound = false;
    }
}
