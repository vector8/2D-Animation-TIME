#ifndef PC_PIXEL_POINT_3D_H
#define PC_PIXEL_POINT_3D_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPixelPoint3D represents a point in 3D pixel coordinates as an integer triplet (x, y, z).
/// </summary>
/// <remarks>
/// A pixel point in 3D coordinates relates to a 3D pixel matrix, such as a representation
/// of a 3D object.
/// </remarks>
class HPPC_API PcPixelPoint3D
{
public:
    /// <summary>
    /// Creates a 3D pixel point at the location (0, 0, 0).
    /// </summary>
    PcPixelPoint3D();

    /// <summary>
    /// Destroys the instance of PcPixelPoint3D.
    /// </summary>
    virtual ~PcPixelPoint3D() {}

    /// <summary>
    /// Creates a 3D pixel point using the provided pixel coordinates along the X, Y, and Z axes.
    /// </summary>
    /// <param name="x">Pixel coordinate of the pixel along the X-axis</param>
    /// <param name="y">Pixel coordinate of the pixel along the Y-axis</param>
    /// <param name="z">Pixel coordinate of the pixel along the Z-axis</param>
    PcPixelPoint3D(int x, int y, int z);

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
    /// Gets the Z coordinate in pixels of this pixel point.
    /// </summary>
    /// <returns>
    /// The Z coordinate in pixels
    /// </returns>
    int Z() const throw ();

    /// <summary>
    /// Gets a string that represents the 3D pixel point.
    /// </summary>
    /// <returns>
    /// A string that represents the 3D pixel point
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    int mX;
    int mY;
    int mZ;
};


} }

#endif // PC_PIXEL_POINT_3D_H
