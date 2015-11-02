#ifndef IPC_TEXT_HPP
#define IPC_TEXT_HPP

#include "HpPcApi.hpp"
#include "PcPhysicalRectangle.hpp"
#include "PcPtr.hpp"

#include "PcCollection.hpp"
#include "PcString.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcText provides read-only access to the text in a moment, some properties
/// of the text, and to children of the text.
/// </summary>
/// <remarks>
/// Capturing a moment creates a moment that contains raw data from the Sprout cameras.
/// You extract texts from the moment with the method ExtractText in the interface
/// IPcLink. The method ExtractText returns an IPcText object. For example, if the moment
/// contains a single paragraph of text, the IPcText object contains the text of the paragraph
/// and its bounding rectangle in the root IPcText object, and a child that contains the same
/// text and bounding rectangle. If the moment contains a more complex structure of texts, for
/// example texts in different places on the mat and multiple paragraphs, then the IPcText object
/// contains a root text that is a concatenation of all child texts (together as one text) and
/// a bounding rectangle that encompasses all of the child texts, and a tree structure of children
/// below the root object, in which the children contain the separate child texts with their
/// bounding rectangles.
/// </remarks>
class HPPC_API IPcText
{
public:
    /// <summary>
    /// Destroys the instance of IPcText.
    /// </summary>
    virtual ~IPcText() {};

    /// <summary>
    /// Gets the rectangle that bounds the text.
    /// </summary>
    /// <remarks>
    /// The bounding rectangle is defined by a PcPhysicalPoint (the X, Y location of the upper-left
    /// corner in millimeters) and a PcPhysicalSize (the width and height in millimeters).
    /// </remarks>
    /// <returns>The rectangle that bounds the text</returns>
    virtual const PcPhysicalRectangle& PhysicalBoundaries() const throw () = 0;

    /// <summary>
    /// Gets a string representation of the text.
    /// </summary>
    /// <returns>A string containing a concatenation of all texts</returns>
    virtual const PcString& Text() const throw () = 0;

    /// <summary>
    /// Gets the collection of texts that are children of this text, and their bounding rectangles.
    /// </summary>
    /// <returns>A collection of texts that are children of this text, and their bounding rectangles</returns>
    virtual const PcCollection<PcPtr<IPcText>>& Children() const throw () = 0;
};

} }

#endif // IPC_TEXT_HPP
