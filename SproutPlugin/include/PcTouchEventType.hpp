#ifndef PC_TOUCH_EVENT_TYPE_H
#define PC_TOUCH_EVENT_TYPE_H

#include "HpPcApi.hpp"

namespace hp { namespace pc {

/// <summary>
/// Enumerates the touch events and other touch-layer related events that are supported by the Sprout Platform.
/// </summary>
enum class HPPC_API PcTouchEventType : int
{
    /// <summary>
    /// Unknown or error
    /// </summary>
    TouchUnknownEvent = 0,

    /// <summary>
    /// Touch down event
    /// </summary>
    TouchDownEvent = 1,

    /// <summary>
    /// Touch up event
    /// </summary>
    TouchUpEvent = 2,

    /// <summary>
    /// Touch move event
    /// </summary>
    TouchMoveEvent = 3,

    /// <summary>
    /// Layer-state changed event
    /// </summary>
    /// <remarks>
    /// This event is raised when a touch layer is enabled or disabled.
    /// </remarks>
    TouchLayerStateChanged
};

} }

#endif // PC_TOUCH_EVENT_TYPE_H