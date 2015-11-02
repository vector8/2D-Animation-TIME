#ifndef PC_IMAGE_H
#define PC_IMAGE_H

#include "HpPcApi.hpp"
#include "PcPixelDensity.hpp"
#include "PcPixelSize.hpp"
#include "PcPixelFormat.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcImage contains constructors for creating bitmap images and methods for
/// obtaining information about bitmap images.
/// </summary>
/// <remarks>
/// An example of when the class PcImage is used is in a method overload of the method
/// CaptureMoment that creates a moment from an image. Another example is the method
/// overload of RefineOutline that refines an existing outline using a bitmap representation
/// of the set of strokes that describe regions to be included and excluded.
/// </remarks>
class HPPC_API PcImage
{
public:
    /// <summary>
    /// Creates an image of the specified size and format by making a copy of content from a buffer.
    /// </summary>
    /// <param name="imageSize">Image size</param>
    /// <param name="pixelDensity">Pixel density in pixels per millimeter</param>
    /// <param name="rowSize">Row size in bytes</param>
    /// <param name="pixelFormat">Pixel format (BGRA, BGR, or Grayscale)</param>
    /// <param name="buffer">Image buffer to be copied</param>
    /// <returns>An instance of PcImage</returns>
    PcImage(const PcPixelSize& imageSize, const PcPixelDensity& pixelDensity, int rowSize,
        PcPixelFormat pixelFormat, const PcCollection<unsigned char>& buffer);

    /// <summary>
    /// Creates an image of the specified size and format by taking ownership of the buffer.
    /// </summary>
    /// <param name="imageSize">Image size</param>
    /// <param name="pixelDensity">Pixel density in pixels per millimeter</param>
    /// <param name="rowSize">Row size in bytes</param>
    /// <param name="pixelFormat">Pixel format (BGRA, BGR, or Grayscale)</param>
    /// <param name="data">Image data to be moved</param>
    /// <returns>An instance of PcImage</returns>
    PcImage(const PcPixelSize& imageSize, const PcPixelDensity& pixelDensity, int rowSize,
        PcPixelFormat pixelFormat, PcCollection<unsigned char>&& buffer);

    /// <summary>
    /// Destroys the instance of PcImage.
    /// </summary>
    virtual ~PcImage() {}

    /// <summary>
    /// Gets the size of the image in pixels.
    /// </summary>
    /// <returns>The size of the image in pixels</returns>
    const PcPixelSize& Size() const throw ();

    /// <summary>
    /// Gets the pixel density of the image.
    /// </summary>
    /// <returns>The pixel density of the image in pixels per millimeter</returns>
    const PcPixelDensity& PixelDensity() const throw ();

    /// <summary>
    /// Gets the length of the image data row in bytes.
    /// </summary>
    /// <remarks>
    /// The length is typically equal to (Width*BytesPerPixel)+Alignment, where Alignment
    /// makes the RowSize divisible both by 4 and by the number of channels.
    /// </remarks>
    /// <returns>The row size of the image data in bytes</returns>
    int RowSize() const throw ();

    /// <summary>
    /// Gets how the image data is formatted, that is, which colors and channels are
    /// available and in which order.
    /// </summary>
    /// <returns>The pixel format</returns>
    PcPixelFormat PixelFormat() const throw ();

    /// <summary>
    /// Gets the image buffer itself.
    /// </summary>
    /// <returns>The image buffer</returns>
    const PcCollection<unsigned char>& Buffer() const throw ();

private:

    PcPixelSize mSize;
    PcPixelDensity mPixelDensity;
    int mRowSize;
    PcPixelFormat mPixelFormat;
    PcCollection<unsigned char> mBuffer;

};

} }

#endif // PC_IMAGE_H
