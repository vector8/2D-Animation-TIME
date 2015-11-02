#ifndef PC_PHYSICAL_RECTANGLE_H
#define PC_PHYSICAL_RECTANGLE_H

#include "HpPcApi.hpp"
#include "PcPhysicalPoint.hpp"
#include "PcPhysicalSize.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPhysicalRectangle is used to construct a physical rectangle,
/// that is, a rectangle in physical coordinates (in millimeters).
/// </summary>
class HPPC_API PcPhysicalRectangle
{
public:
    /// <summary>
    /// Creates a physical rectangle at the location (0, 0) with a width and height of 0 millimeters.
    /// </summary>
    PcPhysicalRectangle();

    /// <summary>
    /// Destroys the instance of PcPhysicalRectangle.
    /// </summary>
    virtual ~PcPhysicalRectangle() {}

    /// <summary>
    /// Creates a physical rectangle using the provided physical location (specified by PcPhysicalPoint)
    /// and physical size (specified by PcPhysicalSize).
    /// </summary>
    /// <param name="location">Physical location of the rectangle specified by its PcPhysicalPoint</param>
    /// <param name="size">Physical size of the rectangle specified by its PcPhysicalSize</param>
    PcPhysicalRectangle(const PcPhysicalPoint& location, const PcPhysicalSize& size);

    /// <summary>
    /// Creates a physical rectangle using the provided physical coordinates for the location
    /// and physical lengths for the size.
    /// </summary>
    /// <param name="x">X coordinate in millimeters of the upper-left corner of the rectangle</param>
    /// <param name="y">Y coordinate in millimeters of the upper-left corner of the rectangle</param>
    /// <param name="width">Width in millimeters of the rectangle</param>
    /// <param name="height">Height in millimeters of the rectangle</param>
    PcPhysicalRectangle(double x, double y, double width, double height);

    /// <summary>
    /// Gets an instance of PcPhysicalPoint, which represents the location in millimeters
    /// of the upper-left corner of this physical rectangle.
    /// </summary>
    /// <returns>The location of this physical rectangle</returns>
    const PcPhysicalPoint& Location() const throw ();

    /// <summary>
    /// Gets an instance of PcPhysicalSize, which represents the size (width and height) in millimeters
    /// of this physical rectangle.
    /// </summary>
    /// <returns>The size of this physical rectangle</returns>
    const PcPhysicalSize& Size() const throw ();

    /// <summary>
    /// Gets a string that describes the location and size of this physical rectangle measured in millimeters.
    /// </summary>
    /// <returns>
    /// A string that describes the location and size of this physical rectangle measured in millimeters. The location
    /// is the location of the upper-left corner.
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    PcPhysicalPoint mLocation;
    PcPhysicalSize mSize;
};

} }

#endif // PC_PHYSICAL_RECTANGLE_H
