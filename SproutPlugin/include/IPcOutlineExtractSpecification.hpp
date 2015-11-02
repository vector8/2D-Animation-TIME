#ifndef IPC_OUTLINE_EXTRACT_SPEC_H
#define IPC_OUTLINE_EXTRACT_SPEC_H

#include "HpPcApi.hpp"
#include "IPcOutlineExtractOption.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcOutlineExtractSpecification provides access to extract options,
/// and to functions related to extract options, for outlines.
/// </summary>
class HPPC_API IPcOutlineExtractSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcOutlineExtractSpecification.
    /// </summary>
    virtual ~IPcOutlineExtractSpecification() {}

    /// <summary>
    /// Gets the extract option BasicProcessing for extracting outlines.
    /// </summary>
    /// <remarks>
    /// When using the extract option BasicProcessing, extraction algorithms are off.
    /// The platform returns the rectangle covering the whole mat.
    /// </remarks>
    /// <returns>The extract option Object for extracting outlines</returns>
    virtual const PcPtr<IPcOutlineExtractOption>& BasicProcessing() const throw () = 0;

    /// <summary>
    /// Gets the extract option Object for extracting outlines.
    /// </summary>
    /// <remarks>
    /// When using the extract option Object, extraction algorithms are optimized for
    /// extracting information from a captured moment that contains objects. The platform
    /// performs segmentation and returns all of the information about the requested item.
    /// </remarks>
    /// <returns>The extract option Object for extracting outlines</returns>
    virtual const PcPtr<IPcOutlineExtractOption>& Object() const throw () = 0;

    /// <summary>
    /// Gets the extract option Mat for extracting outlines.
    /// </summary>
    /// <remarks>
    /// When using the extract option Mat, extraction algorithms return only information that
    /// corresponds to the entire work area on the touch mat. Segmentation is not performed.
    /// One goal of the extract option Mat is to return information more quickly than
    /// is the case when using the extract option Object.
    /// </remarks>
    /// <returns>The extract option Mat for extracting outlines</returns>
    virtual const PcPtr<IPcOutlineExtractOption>& Mat() const throw () = 0;

    /// <summary>
    /// Gets the extract option Document for extracting outlines.
    /// </summary>
    /// <remarks>
    /// When using the extract option Document, extraction algorithms are optimized for
    /// extracting information from a captured moment that contains a document. The platform
    /// performs segmentation and returns all of the information about the requested item.
    /// </remarks>
    /// <returns>The extract option Document for extracting outlines</returns>
    virtual const PcPtr<IPcOutlineExtractOption>& Document() const throw () = 0;

    /// <summary>
    /// Finds a specific extract option for outlines by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the requested extract opton for outlines is supported, then Find returns an instance of IPcOutlineExtractOption.
    /// If the requested extract option for outlines is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the extract option for outlines</param>
    /// <returns>An instance of IPcOutlineExtractOption, which is the requested extract option for outlines</returns>
    virtual PcPtr<IPcOutlineExtractOption> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of extract options for outlines.
    /// </summary>
    /// <returns>An enumeration of IPcOutlineExtractOption instances, each of which is a supported extract option for outlines</returns>
    virtual PcCollection<PcPtr<IPcOutlineExtractOption>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_OUTLINE_EXTRACT_SPEC_H
