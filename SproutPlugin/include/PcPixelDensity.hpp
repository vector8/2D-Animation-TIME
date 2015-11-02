#ifndef PC_PIXEL_DENSITY_H
#define PC_PIXEL_DENSITY_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcPixelDensity represents a pixel density, that is, the number of pixels
/// per physical unit of measurement (pixels per millimeter).
/// </summary>
class HPPC_API PcPixelDensity
{
public:
    /// <summary>
    /// Creates an instance of PcPixelDensity with 0 density for the X and Y axes.
    /// </summary>
    PcPixelDensity();

    /// <summary>
    /// Destroys the instance of PcPixelDensity.
    /// </summary>
    virtual ~PcPixelDensity() {}

    /// <summary>
    /// Creates an instance of PcPixelDensity using the provided densities along the X and Y axes.
    /// </summary>
    /// <param name="x">Pixel density along the X-axis</param>
    /// <param name="y">Pixel density along the Y-axis</param>
    PcPixelDensity(double x, double y);

    /// <summary>
    /// Gets the pixel density along the X-axis (pixels per millimeter).
    /// </summary>
    /// <returns>
    /// The pixel density along the X-axis
    /// </returns>
    double X() const throw ();

    /// <summary>
    /// Gets the pixel density along the Y-axis (pixels per millimeter).
    /// </summary>
    /// <returns>
    /// The pixel density along the Y-axis
    /// </returns>
    double Y() const throw ();

    /// <summary>
    /// Gets a string that describes the pixel densities along the X and Y axes.
    /// </summary>
    /// <returns>
    /// A string that describes the pixel densities along the X and Y axes
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    double mX;
    double mY;
};

} }

#endif // PC_PIXEL_DENSITY
