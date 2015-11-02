#ifndef IPC_TOUCH_LAYER_H
#define IPC_TOUCH_LAYER_H

#include "HpPcApi.hpp"
#include "PcException.hpp"
#include "PcPixelRectangle.hpp"
#include "IPcTouchLayerObserver.hpp"
#include "PcPtr.hpp"
#include "PcImage.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcTouchLayer provides access to a specific layer in the stack of virtual
/// touch layers that the Sprout Platform uses for managing touch events on the touch mat.
/// </summary>
/// <remarks>
/// Touch layers allow an application to augment or bypass the operating-system path
/// for managing touch events. For example, an app can use the IPcTouch and IPcTouchLayer
/// interfaces when the app needs access to a keyboard (touch layer Input), and when the
/// app wants to use indirect touch (touch layer Bypass).
/// </remarks>
class HPPC_API IPcTouchLayer
{
public:
    /// <summary>
    /// Destroys the instance of IPcTouchLayer.
    /// </summary>
    virtual ~IPcTouchLayer() {}

    /// <summary>
    /// Gets the mask for the touch layer.
    /// </summary>
    /// <remarks>
    /// The mask for a layer is a rectangle that specifies which area of the layer generates the touch
    /// event associated with the layer when that area of the touch mat is touched.  The areas
    /// inside the mask also block consideration of the touches by lower layers and from passing
    /// through the virtual touch layers to the touch mat.
    /// </remarks>
    /// <returns>The mask of the touch layer</returns>
    virtual PcPtr<PcImage> GetMask() throw (PcException) = 0;

    /// <summary>
    /// Sets the mask that specify the active area of the touch layer.
    /// </summary>
    /// <remarks>
    /// The mask for a layer is a bitmap that specifies which areas of the layer generate the touch
    /// event associated with the layer, when those areas of the touch mat are touched. The areas
    /// inside the mask also block consideration of the touches by lower layers and from passing
    /// through the virtual touch layers to the touch mat.
    /// \n \n
    /// It is not possible to specify the mask for the Input layer.
    /// The keyboard has a fixed location and size.
    /// </remarks>
    /// <param name="mask">Maskask for the layer, specified as a bitmap</param>
    virtual void SetMask(const PcPtr<PcImage>& mask) throw (PcException) = 0;

    /// <summary>
    /// Sets the mask that specify the active area of the touch layer.
    /// </summary>
    /// <remarks>
    /// This is an overloaded method method. Internally it will create a PcImage representating the
    /// mask using the specified rectangle.
    /// </remarks>
    /// <param name="rectangle">Mask for the layer, specified as a rectangle</param>
    virtual void SetMask(const PcPixelRectangle& rectangle) throw (PcException) = 0;

    /// <summary>
    /// Gets the current layer state.
    /// </summary>
    /// <remarks>
    /// The value "true" indicates that the layer is enabled. The value
    /// "false" indicates that the layer is disabled.
    /// </remarks>
    /// <returns>The information about whether the touch layer is enabled</returns>
    virtual bool IsEnabled() throw (PcException) = 0;

    /// <summary>
    /// Enables the touch layer so that it can be used.
    /// </summary>
    /// <remarks>
    /// For example, when displaying the keyboard, enable the layer Input. This also shows
    /// the keyboard. The keyboard is a special case. In general, enabling a touch layer
    /// does not show anything. When the first of one or more touch layers is enabled,
    /// the Sprout Platform starts to handle user touches for the app. The Sprout Platform handles user touches
    /// on the work area of the touch mat. User touches that happen outside of the work area are
    /// not processed.
    /// </remarks>
    virtual void Enable() throw (PcException) = 0;

    /// <summary>
    /// Disables the touch layer when it is not in use.
    /// </summary>
    /// <remarks>
    /// For example, when the keyboard is no longer needed, disable the layer Input. This also
    /// hides the keyboard. The keyboard is a special case. In general, disabling a touch-input layer
    /// does not hide anything. When the last of one or more touch layers is disabled, the SDK stops
    /// handling user touches for the app.
    /// </remarks>
    virtual void Disable() throw (PcException) = 0;

    /// <summary>
    /// Adds a touch observer that will be notified about events for this touch layer.
    /// </summary>
    /// <remarks>
    /// An app can subscribe to events from this touch layer to receive touch events (when they
    /// occur in the touch-handling area), and to receive events that indicate when the layer
    /// has been enabled or disabled.
    /// </remarks>
    /// <param name="observer">The observer that will receive updates from the touch handler</param>
    virtual void AddObserver(IPcTouchLayerObserver* observer) throw (PcException) = 0;

    /// <summary>
    /// Removes an observer from the list of touch observers for this touch layer.
    /// </summary>
    /// <param name="observer">The observer that will be removed</param>
    virtual void RemoveObserver(IPcTouchLayerObserver* observer) throw (PcException) = 0;

};

} }

#endif // IPC_TOUCH_LAYER_H
