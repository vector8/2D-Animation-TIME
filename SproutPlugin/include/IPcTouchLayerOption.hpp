#ifndef IPC_TOUCH_LAYER_OPTION_H
#define IPC_TOUCH_LAYER_OPTION_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTouchLayerOption represents a supported touch layer type when using the interface IPcTouch.
/// </summary>
/// <remarks>
/// Use the interface IPcTouchSpecification to access the supported touch layer types
/// that are returned by the method GetTouchLayer in the interface IPcTouch.
/// </remarks>
class HPPC_API IPcTouchLayerOption : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcTouchLayerOption.
    /// </summary>
    virtual ~IPcTouchLayerOption() {};
};

} } }

#endif // IPC_TOUCH_LAYER_OPTION_H
