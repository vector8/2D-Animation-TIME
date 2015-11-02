#ifndef IPC_OUTLINE_REFINE_SPEC_H
#define IPC_OUTLINE_REFINE_SPEC_H

#include "HpPcApi.hpp"
#include "IPcOutlineRefineOption.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"

#include <vector>

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcOutlineRefineSpecification provides access to refine options,
/// and to functions related to refine options, for outlines.
/// </summary>
class HPPC_API IPcOutlineRefineSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcOutlineRefineSpecification.
    /// </summary>
    virtual ~IPcOutlineRefineSpecification() {}

    /// <summary>
    /// Gets the Default refine option for outlines.
    /// </summary>
    /// <returns>The Default option to refine outlines</returns>
    virtual const PcPtr<IPcOutlineRefineOption>& Default() const throw () = 0;

    /// <summary>
    /// Gets the refine option for outlines that can be used to refine the outline of a rectangular 2D (flat) object.
    /// </summary>
    /// <returns>The Document option to refine outlines of a rectangular 2D (flat) object</returns>
    virtual const PcPtr<IPcOutlineRefineOption>& Document() const throw () = 0;

    /// <summary>
    /// Finds a specific refine option for outlines by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the requested refine opton for outlines is supported, then Find returns an instance of IPcOutlineRefineOption.
    /// If the requested refine option for outlines is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the refine option for outlines</param>
    /// <returns>An instance of IPcOutlineRefineOption, which is the requested refine option for outlines</returns>
    virtual PcPtr<IPcOutlineRefineOption> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of refine options for outlines.
    /// </summary>
    /// <returns>An enumeration of IPcOutlineRefineOption instances, each of which is a supported refine option for outlines</returns>
    virtual PcCollection<PcPtr<IPcOutlineRefineOption>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_OUTLINE_REFINE_SPEC_H
