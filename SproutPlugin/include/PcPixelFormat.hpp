#ifndef PC_PIXEL_FORMAT_H
#define PC_PIXEL_FORMAT_H

#include "HpPcApi.hpp"

namespace hp { namespace pc {

/// <summary>
/// Enumerates the pixel formats for images that are supported by the Sprout Platform.
/// </summary>
enum class HPPC_API PcPixelFormat : int
{
    /// <summary>
    /// Unknown pixel format
    /// </summary>
    Unknown = 0,

    /// <summary>
    /// 4 channels (alpha, red, green, blue)
    /// </summary>
    BGRA = 1,

    /// <summary>
    /// 3 channels (red, green, blue)
    /// </summary>
    BGR = 2,

    /// <summary>
    /// Grayscale (indexed 256 colors)
    /// </summary>
    Grayscale = 3,

    /// <summary>
    /// Grayscale2, 16-bit (indexed 65536 colors)
    /// </summary>
    Grayscale16 = 4
};

} }

#endif // PC_PIXEL_FORMAT_H
