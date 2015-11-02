#ifndef IPC_TOUCH_SPEC_H
#define IPC_TOUCH_SPEC_H

#include "HpPcApi.hpp"
#include "IPcTouchLayerOption.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTouchSpecification provides information about the touch layers
/// that are available in the Sprout Platform.
/// </summary>
/// <remarks>
/// Touch layers allow an application to augment or bypass the operating-system path
/// for managing touch events. For example, an app can use the IPcTouch and IPcTouchLayer
/// interfaces when the app needs access to a keyboard (touch layer Input), and when the
/// app wants to use indirect touch (touch layer Bypass).
/// </remarks>
class HPPC_API IPcTouchSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcTouchSpecification.
    /// </summary>
    virtual ~IPcTouchSpecification() {}

    /// <summary>
    /// Gets the touch layer used to send touch input to an app.
    /// </summary>
    /// <remarks>
    /// User touches that occur in touch-handling areas of this layer when
    /// the layer is enabled result in touch events that are sent to the app
    /// instead of to the operating system (the touch events "bypass" the
    /// operating system). The app can ignore the events (this can be used
    /// to create "rejection" areas that do not respond to user touches)
    /// or the app can process the events in some way (for example, by
    /// making some change in the user interface).
    /// </remarks>
    /// <returns>The layer used to bypass the OS and send touch events to the app</returns>
    virtual const PcPtr<IPcTouchLayerOption>& Bypass() const throw () = 0;

    /// <summary>
    /// Gets the touch layer used to accept touch input and to send the input to the operating system.
    /// </summary>
    /// <remarks>
    /// Currently, the touch layer Input contains the keyboard.
    /// </remarks>
    /// <returns>The touch layer used for touch input to the operating system</returns>
    virtual const PcPtr<IPcTouchLayerOption>& Input() const throw () = 0;

    /// <summary>
    /// Finds a specific touch layer type that is supported by the Sprout Platform by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the specific layer is supported, then Find returns an instance of IPcTouchLayerOption.
    /// If the specific layer is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the touch layer</param>
    /// <returns>An instance of IPcTouchLayerOption, which is the touch layer type</returns>
    virtual PcPtr<IPcTouchLayerOption> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of touch layer types that are supported by the Sprout Platform.
    /// </summary>
    /// <returns>An enumeration of IPcTouchLayerOption instances, each of which is a supported touch layer type</returns>
    virtual PcCollection<PcPtr<IPcTouchLayerOption>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_TOUCH_SPEC_H
