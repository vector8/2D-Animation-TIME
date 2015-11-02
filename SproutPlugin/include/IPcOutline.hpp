#ifndef IPC_OUTLINE_H
#define IPC_OUTLINE_H

#include "PcPhysicalRectangle.hpp"
#include "PcPixelDensity.hpp"
#include "PcPixelPoint.hpp"
#include "PcPtr.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcOutline provides read-only access to an outline, some properties
/// of the outline, and to children of the outline.
/// </summary>
/// <remarks>
/// Capturing a moment creates a moment that contains raw data from the device sensors.
/// You extract outlines from the moment with ExtractOutline, which returns an instance
/// of the interface IPcOutline. The contents of the tree structure in an instance of
/// IPcOutline depend on the extract option used.
/// </remarks>
class HPPC_API IPcOutline
{
public:
    /// <summary>
    /// Destroys the instance of IPcOutline.
    /// </summary>
    virtual ~IPcOutline() {};

    /// <summary>
    /// Gets the rectangle that bounds the outline.
    /// </summary>
    /// <remarks>
    /// The bounding rectangle is defined by a PcPhysicalPoint (the X, Y location
    /// of the upper-left corner in millimeters) and a PcPhysicalSize (the width
    /// and height in millimeters).
    /// </remarks>
    /// <returns>The rectangle that bounds the outline</returns>
    virtual const PcPhysicalRectangle& PhysicalBoundaries() const throw () = 0;

    /// <summary>
    /// Gets the horizontal and vertical pixel densities of the picture in pixels per millimeter.
    /// </summary>
    /// <returns>The horizontal and vertical pixel densities</returns>
    virtual const PcPixelDensity& PixelDensity() const throw () = 0;

    /// <summary>
    /// Gets the skew angle that can be used to align the outline.
    /// </summary>
    /// <remarks>
    /// The skew angle is the angle in radians of the rotation that would be required
    /// to bring the longer axis of the minimum area rectangle that contains the outline
    /// in alignment with the nearer of the positive X axis and the negative Y axis. For example,
    /// if the longer axis is rotated -pi/6 radians (30 degrees counterclockwise) relative
    /// to the positive X axis, then the skew angle would be pi/6 radians. If the longer axis is
    /// rotated -pi/3 radians (60 degrees counterclockwise) relative to the positive X axis, then
    /// the skew angle would be -pi/6 radians.
    /// </remarks>
    /// <returns>The skew angle</returns>
    virtual double SkewAngle() const throw() = 0;

    /// <summary>
    /// Gets the contour that describes the outline.
    /// </summary>
    /// <returns>The contour that describes the outline</returns>
    virtual const PcCollection<PcCollection<PcPixelPoint>>& Contour() const throw() = 0;

    /// <summary>
    /// Gets the collection of outlines that are children of this outline.
    /// </summary>
    /// <returns>The collection of outlines that are children of this outline</returns>
    virtual const PcCollection<PcPtr<IPcOutline>>& Children() const throw() = 0;
};


} }

#endif // IPC_OUTLINE_H
