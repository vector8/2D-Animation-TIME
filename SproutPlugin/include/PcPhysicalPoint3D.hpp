#ifndef PC_PHYSICAL_POINT_3D_H
#define PC_PHYSICAL_POINT_3D_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPhysicalPoint3D represents a 3D physical point, that is, a 3D representation
/// of a physical point in the real world.
/// </summary>
/// <remarks>
/// A physical point in the real world has four coordinates, three for space and one
/// for time. Here, we are interested only in three coordinates, ignoring time and considering
/// the location of the point in the volume of space above the mat. The unit of
/// measurement for the coordinate system is millimeters.
/// </remarks>
class HPPC_API PcPhysicalPoint3D
{
public:
    /// <summary>
    /// Creates a 3D physical point at the location (0, 0, 0).
    /// </summary>
    PcPhysicalPoint3D();

    /// <summary>
    /// Destroys the instance of PcPhysicalPoint3D.
    /// </summary>
    virtual ~PcPhysicalPoint3D() {}

    /// <summary>
    /// Creates a 3D physical point using the provided physical coordinates along the X, Y, and Z axes.
    /// </summary>
    /// <param name="x">X coordinate in millimeters</param>
    /// <param name="y">Y coordinate in millimeters</param>
    /// <param name="z">Z coordinate in millimeters</param>
    PcPhysicalPoint3D(double x, double y, double z);

    /// <summary>
    /// Gets the X coordinate of this 3D physical point in millimeters.
    /// </summary>
    /// <returns>The X coordinate of this 3D physical point.</returns>
    double X() const throw ();

    /// <summary>
    /// Gets the Y coordinate of this 3D physical point in millimeters.
    /// </summary>
    /// <returns>The Y coordinate of this 3D physical point.</returns>
    double Y() const throw ();

    /// <summary>
    /// Gets the Z coordinate of this 3D physical point in millimeters.
    /// </summary>
    /// <returns>The Z coordinate of this 3D physical point.</returns>
    double Z() const throw ();

    /// <summary>
    /// Gets a string that represents the 3D physical point.
    /// </summary>
    /// <returns>
    /// A string that represents the 3D physical point
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    double mX;
    double mY;
    double mZ;
};

} } 

#endif // PC_PHYSICAL_POINT_3D_H
