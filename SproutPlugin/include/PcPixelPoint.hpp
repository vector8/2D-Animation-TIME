#ifndef PC_PIXEL_POINT_H
#define PC_PIXEL_POINT_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPixelPoint represents a point in 2D pixel coordinates as an integer pair (x, y).
/// </summary>
/// <remarks>
/// A pixel point in 2D coordinates relates to a 2D pixel matrix, such as a representation
/// of a 2D object.
/// </remarks>
class HPPC_API PcPixelPoint
{
public:
    /// <summary>
    /// Creates a 2D pixel point at the location (0, 0).
    /// </summary>
    PcPixelPoint();

    /// <summary>
    /// Destroys the instance of PcPixelPoint.
    /// </summary>
    virtual ~PcPixelPoint() {}

    /// <summary>
    /// Creates a 2D pixel point using the provided pixel coordinates along the X and Y axes.
    /// </summary>
    /// <param name="x">Pixel coordinate of the pixel along the X-axis</param>
    /// <param name="y">Pixel coordinate of the pixel along the Y-axis</param>
    PcPixelPoint(int x, int y);

    /// <summary>
    /// Gets the X coordinate in pixels of this pixel point.
    /// </summary>
    /// <returns>
    /// The X coordinate in pixels
    /// </returns>
    int X() const throw ();

    /// <summary>
    /// Gets the Y coordinate in pixels of this pixel point.
    /// </summary>
    /// <returns>
    /// The Y coordinate in pixels
    /// </returns>
    int Y() const throw ();

    /// <summary>
    /// Gets a string that represents the 2D pixel point.
    /// </summary>
    /// <returns>
    /// A string that represents the 2D ixel point
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    int mX;
    int mY;
};

} }

#endif // PC_PIXEL_POINT_H
