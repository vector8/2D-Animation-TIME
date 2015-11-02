#ifndef IPC_MESSAGE_EVENT_ARGS_H
#define IPC_MESSAGE_EVENT_ARGS_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcMessageEventArgs represents a data structure that contains
/// a message and related data.
/// </summary>
/// <remarks>
/// An instance of IPcMessageEventArgs can be sent as an argument in an event. This event
/// is received in the IPcCommunicationObserver::Updated method. By this means, Sprout
/// applications can exchange messages.
/// </remarks>
class HPPC_API IPcMessageEventArgs
{
public:
    /// <summary>
    /// Destroys the instance of IPcMessageEventArgs.
    /// </summary>
    virtual ~IPcMessageEventArgs() {}

    /// <summary>
    /// Gets the message sender.
    /// </summary>
    /// <returns>The message sender identifier</returns>
    virtual const PcString& Source() const throw () = 0;

    /// <summary>
    /// Gets the message receiver.
    /// </summary>
    /// <returns>The message receiver identifier</returns>
    virtual const PcString& Destination() const throw () = 0;

    /// <summary>
    /// Gets the message data as a byte collection.
    /// </summary>
    /// <returns>The message data stream</returns>
    virtual const PcCollection<unsigned char>& Message() const throw() = 0;
};

} }

#endif // IPC_MESSAGE_EVENT_ARGS_H
