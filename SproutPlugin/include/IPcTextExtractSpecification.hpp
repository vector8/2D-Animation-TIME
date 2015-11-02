#ifndef IPC_TEXT_EXTRACT_SPEC_H
#define IPC_TEXT_EXTRACT_SPEC_H

#include "HpPcApi.hpp"
#include "IPcTextExtractOption.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTextExtractSpecification provides access to extract options,
/// and to functions related to extract options, for text.
/// </summary>
class HPPC_API IPcTextExtractSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcTextExtractSpecification.
    /// </summary>
    virtual ~IPcTextExtractSpecification() {}

    /// <summary>
    /// Gets the extract option Default for text.
    /// </summary>
    /// <remarks>
    /// When using the extract option Default, extraction algorithms return all information about the
    /// requested item, and use the best approach, for example, using a large dictionary. This
    /// can take a while.
    /// </remarks>
    /// <returns>The extract option Default for text</returns>
    virtual const PcPtr<IPcTextExtractOption>& Default() const throw () = 0;

    /// <summary>
    /// Gets the extract option BasicProcessing for text, which can be used to decrease the amount of processing
    /// performed by the Sprout Platform.
    /// </summary>
    /// <remarks>
    /// The aim of the extract option BasicProcessing is to obtain extracted information more quickly than when using 
    /// the extract option Default. This might be accomplished by using a smaller dictionary, for example.
    /// </remarks>
    /// <returns>The extract option BasicProcessing for text</returns>
    virtual const PcPtr<IPcTextExtractOption>& BasicProcessing() const throw () = 0;

    /// <summary>
    /// Finds a specific extract option for text by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the requested extract opton for text is supported, then Find returns an instance of IPcTextExtractOption.
    /// If the requested extract option for text is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the extract option for text</param>
    /// <returns>An instance of IPcTextExtractOption, which is the requested extract option for text</returns>
    virtual PcPtr<IPcTextExtractOption> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of supported extract options for text.
    /// </summary>
    /// <returns>An enumeration of IPcTextExtractOption instances, each of which is a supported extract option for text</returns>
    virtual PcCollection<PcPtr<IPcTextExtractOption>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_TEXT_EXTRACT_SPEC_H
