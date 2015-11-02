#ifndef IPC_OBJECT_TRACKING_OBSERVER_H
#define IPC_OBJECT_TRACKING_OBSERVER_H

#include "HpPcApi.hpp"
#include "PcPtr.hpp"
#include "IPcTrackEventArgs.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class IPcObjectTrackingObserver provides the functionality for
/// an object-tracking observer. It specifies a contract to the app developer
/// and provides a virtual method for receiving object-tracking events.
/// </summary>
/// <remarks>
/// The class IPcObjectTrackingObserver can be used to observe the events that are
/// generated when objects are recognized and tracked. An application can subscribe to
/// object-tracking events by implementing this class, and then use the method
/// AddObserver that is declared on the interface IPcObjectTrackingHandler
/// to provide an instance of the class IPcObjectTrackingObserver to the interface
/// IPcObjectTrackingHandler.
/// </remarks>
class HPPC_API IPcObjectTrackingObserver
{
public:
    /// <summary>
    /// Default constructor.
    /// </summary>
    IPcObjectTrackingObserver();

    /// <summary>
    /// Destroys the instance of IPcObjectTrackingObserver.
    /// </summary>
    virtual ~IPcObjectTrackingObserver();

    /// <summary>
    /// Receives an object-tracking event, which is raised each time one or more
    /// tracked objects is recognized in a video frame.
    /// </summary>
    /// <remarks>
    /// An observer must implement this method to receive notifications about
    /// object-tracking events.
    /// </remarks>
    /// <param name="trackEvent">The object-tracking information</param>
    virtual void Updated(const PcPtr<IPcTrackEventArgs>& trackEvent) throw () = 0;
};

} }

#endif // IPC_OBJECT_TRACKING_OBSERVER_H
