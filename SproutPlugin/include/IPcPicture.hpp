#ifndef IPC_PICTURE_H
#define IPC_PICTURE_H

#include "PcPhysicalRectangle.hpp"
#include "PcPixelDensity.hpp"
#include "PcImage.hpp"
#include "PcPtr.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcPicture provides read-only access to a picture, some properties
/// of the picture, and to children of the picture.
/// </summary>
/// <remarks>
/// Capturing a moment creates a moment that contains raw data from the device sensors.
/// You extract pictures from the moment with ExtractPicture, which returns an instance
/// of the interface IPcPicture. The contents of the tree structure in an instance of
/// IPcPicture depend on the extract option used.
/// </remarks>
class HPPC_API IPcPicture
{
public:
    /// <summary>
    /// Destroys the instance of IPcPicture.
    /// </summary>
    virtual ~IPcPicture() {};

    /// <summary>
    /// Gets the rectangle that bounds the picture.
    /// </summary>
    /// <remarks>
    /// The bounding rectangle is defined by a PcPhysicalRectangle, which is composed of
    /// a PcPhysicalPoint (the X, Y location of the upper-left corner in millimeters) and
    /// a PcPhysicalSize (the width and height in millimeters).
    /// </remarks>
    /// <returns>The rectangle that bounds the picture</returns>
    virtual const PcPhysicalRectangle& PhysicalBoundaries() const throw () = 0;

    /// <summary>
    /// Gets the horizontal and vertical pixel densities of the picture in pixels per millimeter.
    /// </summary>
    /// <returns>The horizontal and vertical pixel densities</returns>
    virtual const PcPixelDensity& PixelDensity() const throw () = 0;

    /// <summary>
    /// Gets the skew angle that can be used to align the picture.
    /// </summary>
    /// <remarks>
    /// The skew angle is the angle in radians of the rotation that would be required
    /// to bring the longer axis of the minimum area rectangle that contains the picture
    /// in alignment with the nearer of the positive X axis and the negative Y axis. For example,
    /// if the longer axis is rotated -pi/6 radians (30 degrees counterclockwise) relative
    /// to the positive X axis, then the skew angle would be pi/6 radians. If the longer axis is
    /// rotated -pi/3 radians (60 degrees counterclockwise) relative to the positive X axis, then
    /// the skew angle would be -pi/6 radians.
    /// </remarks>
    /// <returns>The skew angle</returns>
    virtual double SkewAngle() const throw () = 0;

    /// <summary>
    /// Gets the bitmap representation of the picture.
    /// </summary>
    /// <returns>A bitmap representation of the picture</returns>
    virtual const PcPtr<PcImage>& Image() const throw () = 0;

    /// <summary>
    /// Gets the collection of pictures that are children of this picture.
    /// </summary>
    /// <returns>The collection of pictures that are children of this picture</returns>
    virtual const PcCollection<PcPtr<IPcPicture>>& Children() const throw () = 0;
};

} }

#endif // IPC_PICTURE_H
