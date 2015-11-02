#ifndef PC_PIXEL_RECTANGLE_H
#define PC_PIXEL_RECTANGLE_H

#include "HpPcApi.hpp"
#include "PcPixelPoint.hpp"
#include "PcPixelSize.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPixelRectangle represents a pixel rectangle.
/// </summary>
/// <remarks>
/// A pixel rectangle is defined by the location of the upper-left corner and
/// the size of the rectangle in pixels.
/// </remarks>
class HPPC_API PcPixelRectangle
{
public:
    /// <summary>
    /// Creates a pixel rectangle at the location (0, 0) with a width and height of 0 pixels.
    /// </summary>
    PcPixelRectangle();

    /// <summary>
    /// Destroys the instance of PcPixelRectangle.
    /// </summary>
    virtual ~PcPixelRectangle() {}

    /// <summary>
    /// Creates a pixel rectangle using the provided location and size.
    /// </summary>
    /// <param name="location">Location in pixels of the rectangle</param>
    /// <param name="size">Size in pixels of the rectangle</param>
    PcPixelRectangle(const PcPixelPoint& location, const PcPixelSize& size);

    /// <summary>
    /// Creates a pixel rectangle using the provided location and size attributes.
    /// </summary>
    /// <param name="x">X coordinate in pixels of the top-left corner of the rectangle</param>
    /// <param name="y">Y coordinate in pixels of the top-left corner of the rectangle</param>
    /// <param name="width">Width in pixels of the rectangle</param>
    /// <param name="height">Height in pixels of the rectangle</param>
    PcPixelRectangle(int x, int y, int width, int height);

    /// <summary>
    /// Gets the location in pixels of the upper-left corner of this pixel rectangle.
    /// </summary>
    /// <returns>
    /// The location of this pixel rectangle
    /// </returns>
    const PcPixelPoint& Location() const throw ();

    /// <summary>
    /// Gets the size in pixels of this pixel rectangle.
    /// </summary>
    /// <returns>
    /// The size of this pixel rectangle
    /// </returns>
    const PcPixelSize& Size() const throw ();

    /// <summary>
    /// Gets a string that describes the location and size of this rectangle in pixel coordinates.
    /// </summary>
    /// <returns>
    /// A string that describes the location and size of this rectangle in pixel coordinates.
    /// The location is the location of the upper-left corner.
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    PcPixelPoint mLocation;
    PcPixelSize mSize;
};


} }

#endif // PC_PIXEL_RECTANGLE_H
