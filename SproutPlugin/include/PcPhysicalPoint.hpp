#ifndef PC_PHYSICAL_POINT_H
#define PC_PHYSICAL_POINT_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPhysicalPoint represents a 2D physical point, that is, a 2D representation
/// of a physical point in the real world.
/// </summary>
/// <remarks>
/// A physical point in the real world has four coordinates, three for space and one
/// for time. Here, we are interested only in two coordinates, ignoring time and considering
/// the location of the point in a plane, for example, in the plane of the mat. The unit of
/// measurement for the coordinate system is millimeters.
/// </remarks>
class HPPC_API PcPhysicalPoint
{
public:
    /// <summary>
    /// Creates a 2D physical point at the location (0, 0).
    /// </summary>
    PcPhysicalPoint();

    /// <summary>
    /// Destroys the instance of PcPhysicalPoint.
    /// </summary>
    virtual ~PcPhysicalPoint() {}

    /// <summary>
    /// Creates a 2D physical point using the provided physical coordinates along the X and Y axes.
    /// </summary>
    /// <param name="x">X coordinate in millimeters</param>
    /// <param name="y">Y coordinate in millimeters</param>
    PcPhysicalPoint(double x, double y);

    /// <summary>
    /// Gets the X coordinate of this 2D physical point in millimeters.
    /// </summary>
    /// <returns>The X coordinate of this 2D physical point</returns>
    double X() const throw ();

    /// <summary>
    /// Gets the Y coordinate of this 2D physical point in millimeters.
    /// </summary>
    /// <returns>The Y coordinate of this 2D physical point</returns>
    double Y() const throw ();

    /// <summary>
    /// Gets a string that represents the 2D physical point.
    /// </summary>
    /// <returns>
    /// A string that represents the 2D physical point
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    double mX;
    double mY;
};

} }

#endif // PC_PHYSICAL_POINT_H
