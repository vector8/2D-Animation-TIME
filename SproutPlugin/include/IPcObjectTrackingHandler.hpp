#ifndef IPC_OBJECT_TRACKING_HANDLER_H
#define IPC_OBJECT_TRACKING_HANDLER_H

#include "HpPcApi.hpp"
#include "PcException.hpp"
#include "IPcObjectTrackingObserver.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcObjectTrackingHandler provides a handler that allows an app to
/// recognize and track 2D objects placed on or held above the touch mat, based on prior
/// training to recognize images of the objects.
/// </summary>
/// <remarks>
/// Regarding training to recognize 2D objects, capturing a moment that contains the
/// objects and then extracting the pictures and converting those to images that can
/// be used for training is the best approach. During the capture, the user should lay
/// the objects flat on the touch mat, not hold the objects, and not have his or her
/// hands on or above the touch mat.
/// \n \n
/// It is also possible to train the object-tracking handler using images from other
/// sources, such as digital cameras or the Web. In these cases, a printed copy of
/// the image can be tracked.
/// \n \n
/// The object-tracking handler is not designed to track 3D objects.
/// </remarks>
class HPPC_API IPcObjectTrackingHandler
{
public:
    /// <summary>
    /// Destroys the instance of IPcObjectTrackingHandler.
    /// </summary>
    virtual ~IPcObjectTrackingHandler() {}

    /// <summary>
    /// Starts tracking objects.
    /// </summary>
    virtual void Start() throw (PcException) = 0;

    /// <summary>
    /// Stops tracking objects.
    /// </summary>
    virtual void Stop() throw (PcException) = 0;

    /// <summary>
    /// Adds an observer to the list of object-tracking observers.
    /// </summary>
    /// <param name="observer">The observer to add to the list of object-tracking observers</param>
    virtual void AddObserver(IPcObjectTrackingObserver *observer) throw (PcException) = 0;

    /// <summary>
    /// Removes an observer from the list of object-tracking observers.
    /// </summary>
    /// <param name="observer">The observer to remove from the list of object-tracking observers</param>
    virtual void RemoveObserver(IPcObjectTrackingObserver *observer) throw (PcException) = 0;

    /// <summary>
    /// Gets status information about whether object tracking is in progress.
    /// </summary>
    /// <remarks>
    /// The value "true" indicates that object tracking is in progress. The value
    /// "false" indicates that object tracking is not in progress.
    /// </remarks>
    /// <returns>Status information about whether object tracking is in progress</returns>
    virtual bool IsTrackingInProgress() throw (PcException) = 0;
};

} }

#endif // IPC_OBJECT_TRACKING_HANDLER_H
