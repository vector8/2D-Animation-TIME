#ifndef IPC_TOUCH_LAYER_OBSERVER_H
#define IPC_TOUCH_LAYER_OBSERVER_H

#include "HpPcApi.hpp"
#include "PcPtr.hpp"
#include "IPcTouchEventArgs.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcTouchLayerObserver provides the functionality for
/// a touch-layer observer. It specifies a contract to the app developer
/// and provides a virtual method for receiving touch events.
/// </summary>
/// <remarks>
/// IPcTouchLayerObserver can be used to observe touch events that are generated when
/// a user touches the touch mat. The interface IPcTouchLayer enables and disables
/// the touch layer and sends touch events. The app developer must create a concrete
/// implementation of the class IPcTouchLayerObserver to receive touch events that are
/// generated by a touch layer. An application can subscribe to the native events of
/// the touch mat by implementing this class, and then using the method
/// AddObserver that is declared on the interface IPcTouchLayer to provide
/// an instance of the class IPcTouchLayerObserver to the interface IPcTouchLayer.
/// </remarks>
class HPPC_API IPcTouchLayerObserver
{
public:
    /// <summary>
    /// Default constructor.
    /// </summary>
    IPcTouchLayerObserver();

    /// <summary>
    /// Destroys the instance of IPcTouchLayerObserver.
    /// </summary>
    virtual ~IPcTouchLayerObserver();

    /// <summary>
    /// Receives a notification about a touch event, which is raised each time
    /// a user touches the touch-handling region of an enabled touch layer that is not
    /// obscured by a higher layer.
    /// </summary>
    /// <remarks>
    /// An observer must implement this method to receive notifications about touch events.
    /// </remarks>
    /// <param name="args">Arguments for a touch event</param>
    virtual void Updated(const PcPtr<IPcTouchEventArgs>& args) throw () = 0;
};

} }

#endif // IPC_TOUCH_LAYER_OBSERVER_H
