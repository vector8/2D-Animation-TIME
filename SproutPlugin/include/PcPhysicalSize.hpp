#ifndef PC_PHYSICAL_SIZE_H
#define PC_PHYSICAL_SIZE_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPhysicalSize represents the size of a 2D object in physical coordinates (in millimeters).
/// </summary>
class HPPC_API PcPhysicalSize
{
public:
    /// <summary>
    /// Creates an instance of PcPhysicalSize with zero width and height.
    /// </summary>
    PcPhysicalSize();

    /// <summary>
    /// Destroys the instance of PcPhysicalSize.
    /// </summary>
    virtual ~PcPhysicalSize() {}

    /// <summary>
    /// Creates an instance of PcPhysicalSize using the provided width and height in millimeters.
    /// </summary>
    /// <param name="width">Width of the physical object (size along the X-axis) in millimeters</param>
    /// <param name="height">Height of the physical object (size along the Y-axis) in millimeters</param>
    PcPhysicalSize(double width, double height);

    /// <summary>
    /// Gets the width (size along the X-axis) in millimeters of this physical object.
    /// </summary>
    /// <returns>The width of this physical object</returns>
    double Width() const throw ();

    /// <summary>
    /// Gets the height (size along the Y-axis) in millimeters of this physical object.
    /// </summary>
    /// <returns>The height of this physical object</returns>
    double Height() const throw ();

    /// <summary>
    /// Gets a string that describes the physical size of the object along the X and Y axes.
    /// </summary>
    /// <returns>
    /// A string that describes the physical size of the object along the X and Y axes
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    double mWidth;
    double mHeight;
};

} }

#endif // PC_PHYSICAL_SIZE_H
