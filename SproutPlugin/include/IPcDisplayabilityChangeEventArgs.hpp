#ifndef IPC_DISPLAYABILITY_CHANGE_EVENT_ARGS_H
#define IPC_DISPLAYABILITY_CHANGE_EVENT_ARGS_H

#include "HpPcApi.hpp"
#include "PcDisplayability.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcDisplayabilityChangeEventArgs is a class for receiving information about
/// a change in the displayability state of a registered window as arguments in an event.
/// </summary>
/// <remarks>
/// This event is received in the IPcDisplayabilityObserver::Updated method.
/// Observers for this event must be registered using the IPcWindowRegistration interface.
/// </remarks>
class HPPC_API IPcDisplayabilityChangeEventArgs
{
public:
    /// <summary>
    /// Destroys the instance of IPcDisplayabilityChangeEventArgs.
    /// </summary>
    virtual ~IPcDisplayabilityChangeEventArgs() {}

    /// <summary>
    /// Gets the prior value of the displayability state.
    /// </summary>
    /// <returns>
    /// The prior value of the displayability state
    /// </returns>
    virtual PcDisplayability OldValue() const throw () = 0;

    /// <summary>
    /// Gets the new value of the displayability state.
    /// </summary>
    /// <returns>
    /// The new value of the displayability state
    /// </returns>
    virtual PcDisplayability NewValue() const throw () = 0;
};

} }

#endif // IPC_DISPLAYABILITY_CHANGE_EVENT_ARGS_H
