#ifndef IPC_CLASSIFICATION_H
#define IPC_CLASSIFICATION_H

#include "HpPcApi.hpp"
#include "IPcTag.hpp"
#include "PcImage.hpp"
#include "PcPhysicalRectangle.hpp"
#include "PcPixelDensity.hpp"
#include "PcPtr.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcClassification provides tag information that classifies
/// the contents of a moment.
/// </summary>
/// <remarks>
/// The tag information is available through the method Classify in
/// the interface IPcLink.
/// </remarks>
class HPPC_API IPcClassification
{
public:
    /// <summary>
    /// Destroys the instance of IPcClassification.
    /// </summary>
    virtual ~IPcClassification() {};

    /// <summary>
    /// Gets the collection of tags that the Sprout Platform considers to apply to the contents
    /// of the moment.
    /// </summary>
    /// <returns>A collection of tags</returns>
    virtual const PcCollection<PcPtr<IPcTag>>& Tags() const throw () = 0;

    /// <summary>
    /// Gets the collection of tags that are children of this tag.
    /// </summary>
    /// <returns>A collection of tags</returns>
    virtual const PcCollection<PcPtr<IPcClassification>>& Children() const throw () = 0;
};

} }

#endif // IPC_CLASSIFICATION_H
