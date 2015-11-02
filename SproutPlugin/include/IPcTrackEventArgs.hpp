#ifndef IPC_TRACK_EVENT_ARGS_H
#define IPC_TRACK_EVENT_ARGS_H

#include "HpPcApi.hpp"
#include "PcTrackedObject.hpp"
#include "PcPtr.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcTrackEventArgs defines arguments for the event that is triggered when
/// an object is recognized in a video frame by the object-tracking handler.
/// </summary>
class HPPC_API IPcTrackEventArgs
{
public:
    /// <summary>
    /// Destroys the instance of IPcTrackEventArgs.
    /// </summary>
    virtual ~IPcTrackEventArgs() {}

    /// <summary>
    /// Gets the objects found in a video frame.
    /// </summary>
    /// <returns>A collection of instances of PcTrackedObject</returns>
    virtual const PcCollection<PcTrackedObject>& TrackedObjects() const throw () = 0;
};

} }

#endif // IPC_TRACK_EVENT_ARGS_H
