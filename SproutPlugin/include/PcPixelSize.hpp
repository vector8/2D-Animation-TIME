#ifndef PC_PIXEL_SIZE_H
#define PC_PIXEL_SIZE_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPixelSize represents the size of a 2D object in pixel coordinates.
/// </summary>
class HPPC_API PcPixelSize
{
public:

    /// <summary>
    /// Creates an instance of PcPixelSize that represents an object that has zero width and zero height.
    /// </summary>
    PcPixelSize();

    /// <summary>
    /// Destroys the instance of PcPixelSize.
    /// </summary>
    virtual ~PcPixelSize() {}

    /// <summary>
    /// Creates an instance of the PcPixelSize using the provided width and height.
    /// </summary>
    /// <param name="width">Width of the object (size along the X-axis)</param>
    /// <param name="height">Height of the object (size along the Y-axis)</param>
    PcPixelSize(int width, int height);

    /// <summary>
    /// Gets the width of the object (size along the X-axis) in pixels.
    /// </summary>
    /// <returns>
    /// The width of the object in pixels
    /// </returns>
    int Width() const throw ();

    /// <summary>
    /// Gets the height of the object (size along the Y-axis) in pixels.
    /// </summary>
    /// <returns>
    /// The height of the object in pixels
    /// </returns>
    int Height() const throw ();

    /// <summary>
    /// Gets a string that describes the size in pixels of the object along the X and Y axes.
    /// </summary>
    /// <returns>
    /// A string that describes the size in pixels of the object along the X and Y axes
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    int mWidth;
    int mHeight;
};


} }

#endif // PC_PIXEL_SIZE_H
