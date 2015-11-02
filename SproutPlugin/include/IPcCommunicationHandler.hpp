#ifndef IPC_COMMUNICATION_HANDLER_H
#define IPC_COMMUNICATION_HANDLER_H

#include "HpPcApi.hpp"
#include "IPcMessageEventArgs.hpp"
#include "IPcCommunicationObserver.hpp"
#include "PcException.hpp"
#include "PcString.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcCommunicationHandler provides the functionality for
/// a communication channel.
/// </summary>
/// <remarks>
/// IPcCommunicationHandler can be used to to send messages to other
/// Sprout applications. The interface IPcCommunicationObserver can be used by
/// observers to observe the messages.
/// </remarks>
class HPPC_API IPcCommunicationHandler
{
public:
    /// <summary>
    /// Destroys the instance of IPcCommunicationHandler.
    /// </summary>
    virtual ~IPcCommunicationHandler() {}

    /// <summary>
    /// Gets the unique identifier of this end of the communication channel.
    /// </summary>
    /// <returns>A string that contains the identifier</returns>
    virtual const PcString& Identifier() const throw () = 0;

    /// <summary>
    /// Gets the name of this end of the communication channel.
    /// </summary>
    /// <returns>A string that contains the name</returns>
    virtual const PcString& Name() const throw () = 0;

    /// <summary>
    /// Starts the communication channel.
    /// </summary>
    virtual void Start() throw (PcException) = 0;

    /// <summary>
    /// Stops the communication channel.
    /// </summary>
    virtual void Stop() throw (PcException) = 0;

    /// <summary>
    /// Sends a message to the destination as a data stream.
    /// </summary>
    /// <param name="destination">Identifier of the receiver of the message</param>
    /// <param name="message">Data stream to be sent over the network</param>
    virtual void Send(const PcString& destination, const PcCollection<unsigned char>& message) throw (PcException) = 0;

    /// <summary>
    /// Adds an observer to the list of communication observers.
    /// </summary>
    /// <remarks>
    /// The observer triggers when a new message is available and provides a way to get
    /// the instance of the class IPcMessageEventArgs, which contains information about
    /// the sender, the destination, and the data stream.
    /// </remarks>
    /// <param name="observer">The observer to add to the list of communication observers</param>
    virtual void AddObserver(IPcCommunicationObserver* observer) throw (PcException) = 0;

    /// <summary>
    /// Removes an observer from the list of communication observers.
    /// </summary>
    /// <param name="observer">The observer to remove from the list of communication observers</param>
    virtual void RemoveObserver(IPcCommunicationObserver* observer) throw (PcException) = 0;
};

} }

#endif // IPC_COMMUNICATION_HANDLER_H
