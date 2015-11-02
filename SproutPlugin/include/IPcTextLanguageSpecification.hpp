#ifndef IPC_TEXT_LANGUAGE_SPEC_H
#define IPC_TEXT_LANGUAGE_SPEC_H

#include "HpPcApi.hpp"
#include "IPcTextLanguageOption.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"

#include <vector>

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTextLanguageSpecification provides access to language options,
/// and to functions related to language options, for text.
/// </summary>
class HPPC_API IPcTextLanguageSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcTextLanguageSpecification.
    /// </summary>
    virtual ~IPcTextLanguageSpecification() {}

    /// <summary>
    /// Gets the language option for texts in United States English.
    /// </summary>
    /// <remarks>The default language option is EnUS (English, United States).</remarks>
    /// <returns>The default language option, EnUs</returns>
    virtual const PcPtr<IPcTextLanguageOption>& EnUS() const throw () = 0;

    /// <summary>
    /// Finds a specific language option for text by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the requested language opton for text is supported, then Find returns an instance of IPcTextLanguageOption.
    /// If the requested extract option for text is not supported, then Find returns 
    /// a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the language option for text</param>
    /// <returns>An instance of IPcTextLanguageOption, which is the requested language option for text</returns>
    virtual PcPtr<IPcTextLanguageOption> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of language options for text.
    /// </summary>
    /// <returns>An enumeration of IPcTextLanguageOption instances, each of which is a supported language option for text</returns>
    virtual PcCollection<PcPtr<IPcTextLanguageOption>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_TEXT_LANGUAGE_SPEC_H
