#ifndef PC_PHYSICAL_SIZE_3D_H
#define PC_PHYSICAL_SIZE_3D_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPhysicalSize3D represents the size of a physical object in three dimensions
/// (with physical coordinates in millimeters).
/// </summary>
class HPPC_API PcPhysicalSize3D
{
public:
    /// <summary>
    /// Creates an instance of PcPhysicalSize3D with zero width, height, and depth.
    /// </summary>
    PcPhysicalSize3D();

    /// <summary>
    /// Creates an instance of PcPhysicalSize3D using the provided width, height, and depth in millimeters.
    /// </summary>
    /// <param name="x">Width of the physical object (size along the X-axis)</param>
    /// <param name="y">Height of the physical object (size along the Y-axis)</param>
    /// <param name="z">Depth of the physical object (size along the Z-axis)</param>
    PcPhysicalSize3D(double x, double y, double z);

    /// <summary>
    /// Gets the width (size along the X-axis) in millimeters of this physical object.
    /// </summary>
    /// <returns>The width of this physical object</returns>
    double X() const throw ();

    /// <summary>
    /// Gets the height (size along the Y-axis) in millimeters of this physical object.
    /// </summary>
    /// <returns>The height of this physical object</returns>
    double Y() const throw ();

    /// <summary>
    /// Gets the depth (size along the Z-axis) in millimeters of this physical object.
    /// </summary>
    /// <returns>The depth of this physical object</returns>
    double Z() const throw ();

    /// <summary>
    /// Gets a string that describes the size of the physical object along the X, Y, and Z axes.
    /// </summary>
    /// <returns>
    /// A string that describes the size of the physical object along the X, Y, and Z axes
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    double mX;
    double mY;
    double mZ;
};

} }

#endif // PC_PHYSICAL_SIZE_3D_H