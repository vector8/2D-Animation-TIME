#ifndef IPC_TOUCH_H
#define IPC_TOUCH_H

#include "HpPcApi.hpp"
#include "IPcTouchLayer.hpp"
#include "IPcTouchLayerOption.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcTouch provides access to all of the layers in the stack of virtual
/// touch layers that the Sprout Platform uses for managing touch events on the touch mat.
/// </summary>
/// <remarks>
/// Touch layers allow an application to augment or bypass the operating-system path
/// for managing touch events. For example, an app can use the IPcTouch and IPcTouchLayer
/// interfaces when the app needs access to a keyboard (touch layer Input), and when the
/// app wants to use indirect touch (touch layer Bypass).
/// </remarks>
class HPPC_API IPcTouch
{
public:
    /// <summary>
    /// Destroys the instance of IPcTouch.
    /// </summary>
    virtual ~IPcTouch() {}

    /// <summary>
    /// Gets a touch layer by touch layer type. Touch layer types are declared in the
    /// interface IPcTouchSpecification.
    /// </summary>
    /// <remarks>
    /// Getting a touch layer does not make it active, that is, it does not generate touch events
    /// that the app can receive using touch layer observers. First, it is necessary to define
    /// the geometry of the touch-handling area, and then to enable the touch layer. For the
    /// layer Input, the geometry is predefined. You only need to enable the touch layer.
    /// </remarks>
    /// <param name="touchLayerOption">Identifier of the touch layer to get</param>
    /// <returns>An instance of the interface IPcTouchLayer</returns>
    virtual const PcPtr<IPcTouchLayer>& GetTouchLayer(const PcPtr<specification::IPcTouchLayerOption>& touchLayerOption) throw (PcException) = 0;

    /// <summary>
    /// Disables all touch layers.
    /// </summary>
    /// <remarks>
    /// After disabling all touch layers, touch layer observers for the app no longer receive touch events.
    /// </remarks>
    /// <returns>A task</returns>
    virtual void DisableAll() throw (PcException) = 0;

    /// <summary>
    /// Enables all touch layers.
    /// </summary>
    /// <remarks>
    /// When all touch layers are enabled, touch layer observers for the app receive
    /// touch events from all of the touch layers.
    /// </remarks>
    /// <returns>A task</returns>
    virtual void EnableAll() throw (PcException) = 0;
};

} }

#endif
