#ifndef IPC_COMMUNICATION_OBSERVER_H
#define IPC_COMMUNICATION_OBSERVER_H

#include "HpPcApi.hpp"
#include "PcPtr.hpp"
#include "IPcMessageEventArgs.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcCommunicationObserver provides the functionality for
/// a communication observer. It specifies a contract to the app developer
/// and provides a virtual method for receiving messages.
/// </summary>
/// <remarks>
/// IPcCommunicationObserver can be used to observe the messages that are exchanged
/// between Sprout applications. The interface IPcCommunicationHandler provides the communication
/// channels and sends the messages. The app developer must create a concrete implementation
/// of this class to receive events that contain messages. An application can subscribe to
/// the events by implementing this class, and then using the method AddObserver
/// that is declared on the interface IPcCommunicationHandler to provide an instance of the class
/// IPcCommunicationObserver to the interface IPcCommunicationHandler.
/// </remarks>
class HPPC_API IPcCommunicationObserver
{
public:
    /// <summary>
    /// Default constructor.
    /// </summary>
    IPcCommunicationObserver();

    /// <summary>
    /// Destroys the instance of IPcCommunicationObserver.
    /// </summary>
    virtual ~IPcCommunicationObserver();

    /// <summary>
    /// Receives a new message.
    /// </summary>
    /// <remarks>
    /// An communication observer must implement this method to receive notifications about events that contain messages.
    /// </remarks>
    /// <param name="message">The message to be handled</param>
    virtual void Updated(const PcPtr<IPcMessageEventArgs>& message) throw () = 0;
};

} }

#endif // IPC_COMMUNICATION_OBSERVER_H
