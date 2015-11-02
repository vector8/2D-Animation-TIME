#ifndef IPC_DISPLAYABILITY_OBSERVER_H
#define IPC_DISPLAYABILITY_OBSERVER_H

#include "HpPcApi.hpp"
#include "PcPtr.hpp"
#include "IPcDisplayabilityChangeEventArgs.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcDisplayabilityObserver provides the functionality for
/// an observer of displayability-change events. It specifies a contract to the app developer
/// and provides a virtual method for receiving the displayability-change events.
/// </summary>
/// <remarks>
/// The app developer must create a concrete implementation of this class to receive
/// displayability-change events that happen for a registered window. Any application can subscribe
/// to be notified of displayability changes, which affect the ability of an app to display a registered
/// window on the mat. The observer instance must be added to a list of displayability observers using the
/// method AddObserver in the interface IPcWindowRegistration.
/// </remarks>
class HPPC_API IPcDisplayabilityObserver
{
public:
    /// <summary>
    /// Default constructor.
    /// </summary>
    IPcDisplayabilityObserver();

    /// <summary>
    /// Destroys the instance of IPcDisplayabilityObserver.
    /// </summary>
    virtual ~IPcDisplayabilityObserver();

    /// <summary>
    /// Receives a displayability-change event, which is raised each time
    /// the displayability of the active registered window changes.
    /// </summary>
    /// <remarks>
    /// An observer must implement this method to receive notifications about
    /// displayability-change events.
    /// </remarks>
    /// <param name="args">Arguments for a displayability-change event</param>
    virtual void Updated(const PcPtr<IPcDisplayabilityChangeEventArgs>& args) throw () = 0;
};

} }

#endif // IPC_DISPLAYABILITY_OBSERVER_H
