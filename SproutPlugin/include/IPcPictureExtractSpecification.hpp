#ifndef IPC_PICTURE_EXTRACT_SPEC_H
#define IPC_PICTURE_EXTRACT_SPEC_H

#include "HpPcApi.hpp"

#include "IPcPictureExtractOption.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcPictureExtractSpecification provides access to extract options,
/// and to functions related to extract options, for pictures.
/// </summary>
class HPPC_API IPcPictureExtractSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcPictureExtractSpecification.
    /// </summary>
    virtual ~IPcPictureExtractSpecification() {}

    /// <summary>
    /// Gets the extract option BasicProcessing for extracting pictures.
    /// </summary>
    /// <remarks>
    /// When using the extract option BasicProcessing, extraction algorithms are off.
    /// The method returns low resolution image of the whole mat.
    /// </remarks>
    /// <returns>The extract option Object for extracting pictures</returns>
    virtual const PcPtr<IPcPictureExtractOption>& BasicProcessing() const throw () = 0;

    /// <summary>
    /// Gets the extract option Object for extracting pictures.
    /// </summary>
    /// <remarks>
    /// When using the extract option Object, extraction algorithms are optimized for
    /// extracting information from a captured moment that contains objects. The platform
    /// performs segmentation and returns all of the information about the requested item.
    /// </remarks>
    /// <returns>The extract option Object for extracting pictures</returns>
    virtual const PcPtr<IPcPictureExtractOption>& Object() const throw () = 0;

    /// <summary>
    /// Gets the extract option Mat for extracting pictures.
    /// </summary>
    /// <remarks>
    /// When using the extract option Mat, extraction algorithms return only information that
    /// corresponds to the entire work area on the touch mat. Segmentation is not performed.
    /// One goal of the extract option Mat is to return information more quickly than
    /// is the case when using the extract option Object.
    /// </remarks>
    /// <returns>The extract option Mat for extracting pictures</returns>
    virtual const PcPtr<IPcPictureExtractOption>& Mat() const throw () = 0;

    /// <summary>
    /// Gets the extract option Document for extracting pictures.
    /// </summary>
    /// <remarks>
    /// When using the extract option Document, extraction algorithms are optimized for
    /// extracting information from a captured moment that contains a document. The platform
    /// performs segmentation and returns all of the information about the requested item.
    /// </remarks>
    /// <returns>The extract option Document for extracting pictures</returns>
    virtual const PcPtr<IPcPictureExtractOption>& Document() const throw () = 0;

    /// <summary>
    /// Finds a specific extract option for pictures by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the requested extract opton for pictures is supported, then Find returns an instance of IPcPictureExtractOption.
    /// If the requested extract option for pictures is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the extract option for pictures</param>
    /// <returns>An instance of IPcPictureExtractOption, which is the requested extract option for pictures</returns>
    virtual PcPtr<IPcPictureExtractOption> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of extract options for pictures.
    /// </summary>
    /// <returns>An enumeration of IPcPictureExtractOption instances, each of which is a supported extract option for pictures</returns>
    virtual PcCollection<PcPtr<IPcPictureExtractOption>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_PICTURE_EXTRACT_SPEC_H
