#ifndef IPC_TEXT_REFINE_SPEC_H
#define IPC_TEXT_REFINE_SPEC_H

#include "HpPcApi.hpp"
#include "IPcTextRefineOption.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"

#include <vector>

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTextRefineSpecification provides access to refine options,
/// and to functions related to refine options, for text.
/// </summary>
class HPPC_API IPcTextRefineSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcTextRefineSpecification.
    /// </summary>
    virtual ~IPcTextRefineSpecification() {}

    /// <summary>
    /// Gets the Default refine option for text.
    /// </summary>
    /// <returns>The Default option to refine text</returns>
    virtual const PcPtr<IPcTextRefineOption>& Default() const throw () = 0;

    /// <summary>
    /// Gets the refine option for texts that can be used to refine the text of a rectangular 2D (flat) object.
    /// </summary>
    /// <returns>The Document option to refine text on a rectangular 2D (flat) object</returns>
    virtual const PcPtr<IPcTextRefineOption>& Document() const throw () = 0;

    /// <summary>
    /// Finds a specific refine option for text by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the requested refine opton for text is supported, then Find returns an instance of IPcTextRefineOption.
    /// If the requested refine option for text is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the refine option for text</param>
    /// <returns>An instance of IPcTextRefineOption, which is the requested refine option for text</returns>
    virtual PcPtr<IPcTextRefineOption> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of refine options for text.
    /// </summary>
    /// <returns>An enumeration of IPcTextRefineOption instances, each of which is a supported refine option for text</returns>
    virtual PcCollection<PcPtr<IPcTextRefineOption>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_TEXT_REFINE_SPEC_H
