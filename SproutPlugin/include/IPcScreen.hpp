#ifndef IPC_SCREEN_H
#define IPC_SCREEN_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"
#include "PcPixelDensity.hpp"
#include "PcPixelSize.hpp"
#include "PcPixelRectangle.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcScreen provides information about a screen on the system.
/// </summary>
/// <remarks>
/// Use the method Find in the interface IPcScreenSpecification to get
/// information for a specific screen. Use the method Enumerate in the
/// interface IPcScreenSpecification to get an enumeration of information for
/// all screens on the system.
/// </remarks>
class HPPC_API IPcScreen : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcScreen.
    /// </summary>
    virtual ~IPcScreen() {}

    /// <summary>
    /// Gets the number of pixels per millimeter for each axis.
    /// </summary>
    /// <returns>The number of pixels per millimeter for each axis</returns>
    virtual const PcPixelDensity& PixelDensity() const throw () = 0;

    /// <summary>
    /// Gets the number of pixels on the X axis (width) and Y axis (height).
    /// </summary>
    /// <returns>The number of pixels on the X and Y axes</returns>
    virtual const PcPixelSize& PixelExtent() const throw () = 0;

    /// <summary>
    /// Gets the position and dimensions of the work area.
    /// </summary>
    /// <remarks>
    /// The work area is the area in pixels that is available for the application.
    /// The area that is available might not be the entire screen and might change.
    /// For example, part of the screen might be covered by the taskbar. The X and
    /// Y coordinate values of the top-left corner of the work area include the
    /// offset of the work area relative to the upper-left corner of the monitor
    /// screen.
    /// </remarks>
    /// <returns>The position and dimensions of the work area</returns>
    virtual const PcPixelRectangle& WorkArea() const throw () = 0;
};

} }

#endif // IPC_SCREEN_H
