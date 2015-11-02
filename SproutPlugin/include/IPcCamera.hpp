#ifndef IPC_CAMERA_H
#define IPC_CAMERA_H

#include "HpPcApi.hpp"
#include "PcPixelFormat.hpp"
#include "PcPixelSize.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcCamera provides information about a camera on the system.
/// </summary>
/// <remarks>
/// Use the method Find in the interface IPcCameraSpecification to get
/// information for a specific camera. Use the method Enumerate in the
/// interface IPcCameraSpecification to get an enumeration of information for
/// all cameras on the system.
/// </remarks>
class HPPC_API IPcCamera : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcCamera.
    /// </summary>
    virtual ~IPcCamera() {}

    /// <summary>
    /// Gets the format of the color data for each pixel in an image.
    /// </summary>
    /// <returns>The pixel format</returns>
    virtual PcPixelFormat PixelFormat() const throw () = 0;

    /// <summary>
    /// Gets the number of pixels on the X axis (width) and Y axis (height) of an image.
    /// </summary>
    /// <returns>The number of pixels on each axis of an image</returns>
    virtual const PcPixelSize& PixelExtent() const throw () = 0;
};

} }

#endif //IPC_CAMERA_H
