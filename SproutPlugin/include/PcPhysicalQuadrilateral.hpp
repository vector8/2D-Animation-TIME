#ifndef PC_PHYSICAL_QUADRILATERAL_H
#define PC_PHYSICAL_QUADRILATERAL_H

#include "HpPcApi.hpp"
#include "PcPhysicalPoint.hpp"
#include "PcPhysicalRectangle.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPhysicalQuadrilateral represents a 2D physical quadrilateral.
/// </summary>
/// <remarks>
/// The quadrilateral is represented by four points: A, B, C, and D. A is the point that is
/// closest to the origin point (0, 0), that is, the leftmost of the uppermost two points of the
/// quadrilateral, when an object is first recognized. Points B, C, and D follow from point A
/// in a clockwise direction.
/// For example:
    /// \n
    /// <pre>
    /// (A)--------------(B) 
    ///  |                |
    ///  |                |
    /// (D)--------------(C)
    /// </pre>
/// The unit of measurement for the coordinate system is millimeters.
/// </remarks>
class HPPC_API PcPhysicalQuadrilateral
{
public:
    /// <summary>
    /// Creates a default (and degenerate) quadrilateral with all points on the origin.
    /// </summary>
    PcPhysicalQuadrilateral();

    /// <summary>
    /// Creates a 2D physical quadrilateral using four PcPhysicalPoints.
    /// </summary>
    /// <param name="a">Physical location of point A specified by its PcPhysicalPoint</param>
    /// <param name="b">Physical location of point B specified by its PcPhysicalPoint</param>
    /// <param name="c">Physical location of point C specified by its PcPhysicalPoint</param>
    /// <param name="d">Physical location of point D specified by its PcPhysicalPoint</param>
    PcPhysicalQuadrilateral(const PcPhysicalPoint& a, const PcPhysicalPoint& b, const PcPhysicalPoint& c, const PcPhysicalPoint& d);

    /// <summary>
    /// Destroys the instance of PcPhysicalQuadrilateral.
    /// </summary>
    virtual ~PcPhysicalQuadrilateral() {}

    /// <summary>
    /// Gets the PcPhysicalPoint that represents point A of the quadrilateral.
    /// </summary>
    /// <returns>The physical coordinates of point A of the quadrilateral</returns>
    const PcPhysicalPoint& A() const throw ();

    /// <summary>
    /// Gets the PcPhysicalPoint that represents point B of the quadrilateral.
    /// </summary>
    /// <returns>The physical coordinates of point B of the quadrilateral</returns>
    const PcPhysicalPoint& B() const throw ();

    /// <summary>
    /// Gets the PcPhysicalPoint that represents point C of the quadrilateral.
    /// </summary>
    /// <returns>The physical coordinates of point C of the quadrilateral</returns>
    const PcPhysicalPoint& C() const throw ();

    /// <summary>
    /// Gets the PcPhysicalPoint that represents point D of the quadrilateral.
    /// </summary>
    /// <returns>The physical coordinates of point D of the quadrilateral</returns>
    const PcPhysicalPoint& D() const throw ();

    /// <summary>
    /// Gets the PcPhysicalRectangle that represents the physical boundaries,
    /// that is the bounding rectangle, of the quadrilateral.
    /// </summary>
    /// <returns>The physical rectangle that bounds the quadrilateral</returns>
    const PcPhysicalRectangle& PhysicalBoundaries() const throw ();

private:

    PcPhysicalPoint mA;
    PcPhysicalPoint mB;
    PcPhysicalPoint mC;
    PcPhysicalPoint mD;
    PcPhysicalRectangle mBoundaries;

};

} }

#endif // PC_PHYSICAL_QUADRILATERAL_H
