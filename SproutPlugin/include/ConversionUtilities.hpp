#ifndef HPPC_CONVERSION_UTILITIES_H
#define HPPC_CONVERSION_UTILITIES_H

#include "PcPhysicalRectangle.hpp"
#include "IPcScreen.hpp"
#include "PcImage.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class ConversionUtilities provides a set of helper methods for converting between the physical
/// and screen coordinate systems.
/// </summary>
class ConversionUtilities
{
public:
    /// <summary>
    /// Calculates the number of screen pixels that correspond to the physical location and dimensions
    /// of a rectangle, using the pixel density of the target screen.
    /// </summary>
    /// <param name="physicalRectangle">Rectangle (X, Y, width, height) with all measurements in millimeters</param>
    /// <param name="screen">Target screen (mat or monitor)</param>
    /// <returns>PcPixelRectangle (Location, Size) with all measurements in pixels</returns>
    static PcPixelRectangle ToScreenCoordinates(const PcPhysicalRectangle& physicalRectangle, const PcPtr<IPcScreen>& screen)
    {
        return ToPixels(physicalRectangle, screen->PixelDensity());
    }

    /// <summary>
    /// Calculates the number of screen pixels that correspond to the physical location of a point,
    /// using the pixel density of the target screen.
    /// </summary>
    /// <param name="physicalPoint">Point (X, Y) with all measurements in millimeters</param>
    /// <param name="screen">Target screen (mat or monitor)</param>
    /// <returns>PcPixelPoint (X, Y) with all measurements in pixels</returns>
    static PcPixelPoint ToScreenCoordinates(const PcPhysicalPoint& physicalPoint, const PcPtr<IPcScreen>& screen)
    {
        return ToPixels(physicalPoint, screen->PixelDensity());
    }

    /// <summary>
    /// Calculates the number of screen pixels that correspond to the dimensions of a physical object,
    /// using the pixel density of the target screen.
    /// </summary>
    /// <param name="physicalSize">Size (width and height) with all measurements in millimeters</param>
    /// <param name="screen">Target screen (mat or monitor)</param>
    /// <returns>PcPixelSize (width, height) with all measurements in pixels</returns>
    static PcPixelSize ToScreenCoordinates(const PcPhysicalSize& physicalSize, const PcPtr<IPcScreen>& screen)
    {
        return ToPixels(physicalSize, screen->PixelDensity());
    }

    /// <summary>
    /// Calculates the number of screen pixels that correspond to the physical location and dimensions
    /// of a rectangle, using the pixel density specified as an input parameter.
    /// </summary>
    /// <param name="physicalRectangle">Rectangle (X, Y, width, height) with all measurements in millimeters</param>
    /// <param name="pixelDensity">Number of pixels per millimeter</param>
    /// <returns>PcPixelRectangle (X, Y, width, height) with all measurements in pixels</returns>
    static PcPixelRectangle ToPixels(const PcPhysicalRectangle& physicalRectangle, const PcPixelDensity& pixelDensity)
    {
        PcPixelPoint pixelLocation = ToPixels(physicalRectangle.Location(), pixelDensity);
        PcPixelSize pixelSize = ToPixels(physicalRectangle.Size(), pixelDensity);
        return PcPixelRectangle(pixelLocation, pixelSize);
    }

    /// <summary>
    /// Calculates the number of screen pixels that correspond to the physical location of a point,
    /// using the provided pixel density.
    /// </summary>
    /// <param name="physicalPoint">Point (X, Y) with all measurements in millimeters</param>
    /// <param name="pixelDensity">Number of pixels per millimeter</param>
    /// <returns>PcPixelPoint (X, Y) with all measurements in pixels</returns>
    static PcPixelPoint ToPixels(const PcPhysicalPoint& physicalPoint, const PcPixelDensity& pixelDensity)
    {
        return PcPixelPoint(
            static_cast<int>(std::ceil(physicalPoint.X() * pixelDensity.X())),
            static_cast<int>(std::ceil(physicalPoint.Y() * pixelDensity.Y())));
    }

    /// <summary>
    /// Calculates the number of screen pixels that correspond to the dimensions of a physical object,
    /// using the provided pixel density.
    /// </summary>
    /// <param name="physicalSize">Size (width and height) with all measurements in millimeters</param>
    /// <param name="pixelDensity">Number of pixels per millimeter</param>
    /// <returns>PcPixelSize (width, height) with all measurements in pixels</returns>
    static PcPixelSize ToPixels(const PcPhysicalSize& physicalSize, const PcPixelDensity& pixelDensity)
    {
        return PcPixelSize(
            static_cast<int>(std::ceil(physicalSize.Width() * pixelDensity.X())),
            static_cast<int>(std::ceil(physicalSize.Height() * pixelDensity.Y())));
    }

    /// <summary>
    /// Calculates the physical size of the object on the bitmap.
    /// </summary>
    /// <param name="bitmapSource">Original picture</param>
    /// <returns>PcPhysicalSize (width, height) with all measurements in millimeters</returns>
    static PcPhysicalSize GetPhysicalSize(const PcPtr<PcImage>& bitmapSource)
    {
        double width = bitmapSource->Size().Width() / (bitmapSource->PixelDensity().X());
        double height = bitmapSource->Size().Height() / (bitmapSource->PixelDensity().Y());
        return PcPhysicalSize(width, height);
    }

    /// <summary>
    /// Calculates the physical location and dimensions of a rectangle from
    /// the pixel measurements, using the pixel density of the target screen.
    /// </summary>
    /// <param name="pixelRectangle">Rectangle (X, Y, width, height) with all measurements in pixels</param>
    /// <param name="screen">Target screen (mat or monitor)</param>
    /// <returns>PcPhysicalRectangle (X, Y, width, height) with all measurements in millimeters</returns>
    static PcPhysicalRectangle ToPhysicalCoordinates(const PcPixelRectangle& pixelRectangle, const PcPtr<IPcScreen>& screen)
    {
        return ToPhysicalRectangle(pixelRectangle, screen->PixelDensity());
    }

    /// <summary>
    /// Calculates the physical location of a point from the location of the point specified in
    /// pixels, using the pixel density of the target screen.
    /// </summary>
    /// <param name="pixelPoint">Point (X, Y) with all measurements in pixels</param>
    /// <param name="screen">Target screen (mat or monitor)</param>
    /// <returns>PcPhysicalPoint (X, Y) with all measurements in millimeters</returns>
    static PcPhysicalPoint ToPhysicalCoordinates(const PcPixelPoint& pixelPoint, const PcPtr<IPcScreen>& screen)
    {
        return ToPhysicalPoint(pixelPoint, screen->PixelDensity());
    }

    /// <summary>
    /// Calculates the size (dimensions) of a physical object that corresponds to the number of screen pixels,
    /// using the pixel density of the target screen.
    /// </summary>
    /// <param name="pixelSize">Size (width, height) with all measurements in pixels</param>
    /// <param name="screen">Target screen (mat or monitor)</param>
    /// <returns>PcPhysicalSize (width, height) with all measurements in millimeters</returns>
    static PcPhysicalSize ToPhysicalCoordinates(const PcPixelSize& pixelSize, const PcPtr<IPcScreen>& screen)
    {
        return ToPhysicalSize(pixelSize, screen->PixelDensity());
    }

    /// <summary>
    /// Calculates the physical size of a rectangle, using the provided pixel density.
    /// </summary>
    /// <param name="pixelRectangle">Rectangle (X, Y, width, height) with all measurements in pixels</param>
    /// <param name="pixelDensity">Number of pixels per millimeter</param>
    /// <returns>PcPhysicalRectangle (X, Y, width, height) with all measurements in millimeters</returns>
    static PcPhysicalRectangle ToPhysicalRectangle(const PcPixelRectangle& pixelRectangle, const PcPixelDensity& pixelDensity)
    {
        PcPixelPoint location(pixelRectangle.Location().X(), pixelRectangle.Location().Y());
        PcPhysicalPoint physicalLocation = ToPhysicalPoint(location, pixelDensity);
        PcPhysicalSize physicalSize = ToPhysicalSize(pixelRectangle.Size(), pixelDensity);
        return PcPhysicalRectangle(physicalLocation, physicalSize);
    }

    /// <summary>
    /// Calculates the location of a physical point that corresponds to the location specified in screen pixels,
    /// using the provided pixel density.
    /// </summary>
    /// <param name="pixelPoint">Point (X, Y) with all measurements in pixels</param>
    /// <param name="pixelDensity">Number of pixels per millimeter</param>
    /// <returns>PcPhysicalPoint (X, Y) with all measurements in millimeters</returns>
    static PcPhysicalPoint ToPhysicalPoint(const PcPixelPoint& pixelPoint, const PcPixelDensity& pixelDensity)
    {
        return PcPhysicalPoint(
            static_cast<double>(pixelPoint.X() / pixelDensity.X()),
            static_cast<double>(pixelPoint.Y() / pixelDensity.Y()));
    }

    /// <summary>
    /// Calculates the size (dimensions) of a physical object that correspond to the number of screen pixels,
    /// using the provided pixel density.
    /// </summary>
    /// <param name="pixelSize">Size (width and height) with all measurements in pixels</param>
    /// <param name="pixelDensity">Number of pixels per millimeter</param>
    /// <returns>PcPhysicalSize (width and height) with all measurements in millimeters</returns>
    static PcPhysicalSize ToPhysicalSize(const PcPixelSize& pixelSize, const PcPixelDensity& pixelDensity)
    {
        return PcPhysicalSize(
            static_cast<double>(pixelSize.Width() / pixelDensity.X()),
            static_cast<double>(pixelSize.Height() / pixelDensity.Y()));
    }
};

} }

#endif // HPPC_CONVERSION_UTILITIES_H
