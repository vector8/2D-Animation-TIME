#ifndef IPC_CLASSIFICATION_SPEC_H
#define IPC_CLASSIFICATION_SPEC_H

#include "HpPcApi.hpp"
#include "IPcTag.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcClassificationSpecification provides the classification
/// tags that are available in the Sprout Platform.
/// </summary>
/// <remarks>
/// The tags represent categories of objects that are detected in a moment when using
/// the method Classify in the interface IPcLink.
/// </remarks>
class HPPC_API IPcClassificationSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcClassificationSpecification.
    /// </summary>
    virtual ~IPcClassificationSpecification() {}

    /// <summary>
    /// Gets the tag for a flat object.
    /// </summary>
    /// <returns>The tag for a flat object</returns>
    virtual const PcPtr<IPcTag>& Flat() const throw () = 0;

    /// <summary>
    /// Gets the tag for a rectangular object.
    /// </summary>
    /// <returns>The tag for a rectangular object</returns>
    virtual const PcPtr<IPcTag>& Rectangular() const throw () = 0;

    /// <summary>
    /// Gets the tag for a three-dimensional object.
    /// </summary>
    /// <returns>The tag for a 3D object</returns>
    virtual const PcPtr<IPcTag>& ThreeDimensional() const throw () = 0;

    /// <summary>
    /// Finds a specific tag that is supported by the Sprout Platform by using a unique identifier,
    /// in order to obtain the tag, which is contained in an instance of the interface IPcTag.
    /// </summary>
    /// <remarks>
    /// If the requested tag is supported, then Find returns an instance of IPcTag.
    /// If the requested tag is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the tag</param>
    /// <returns>An instance of IPcTag, which contains the tag</returns>
    virtual PcPtr<IPcTag> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of tags supported by the Sprout Platform, in an enumeration of instances of
    /// the interface IPcTag.
    /// </summary>
    /// <returns>
    /// An enumeration of IPcTag instances, each of which contains a tag
    /// </returns>
    virtual PcCollection<PcPtr<IPcTag>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_CLASSIFICATION_SPEC_H
