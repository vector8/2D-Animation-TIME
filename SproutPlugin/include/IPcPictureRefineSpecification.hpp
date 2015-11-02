#ifndef IPC_PICTURE_REFINE_SPEC_H
#define IPC_PICTURE_REFINE_SPEC_H

#include "HpPcApi.hpp"
#include "IPcPictureRefineOption.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"

#include <vector>

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcPictureRefineSpecification provides access to refine options,
/// and to functions related to refine options, for pictures.
/// </summary>
class HPPC_API IPcPictureRefineSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcPictureRefineSpecification.
    /// </summary>
    virtual ~IPcPictureRefineSpecification() {}

    /// <summary>
    /// Gets the Default refine option for pictures.
    /// </summary>
    /// <returns>The Default option to refine pictures</returns>
    virtual const PcPtr<IPcPictureRefineOption>& Default() const throw () = 0;

    /// <summary>
    /// Gets the refine option for pictures that can be used to refine the picture of a rectangular 2D (flat) object.
    /// </summary>
    /// <returns>The Document option to refine pictures of a rectangular 2D (flat) object</returns>
    virtual const PcPtr<IPcPictureRefineOption>& Document() const throw () = 0;

    /// <summary>
    /// Finds a specific refine option for pictures by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the requested refine option for pictures is supported, then Find returns an instance of IPcPictureRefineOption.
    /// If the requested refine option for pictures is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the refine option for pictures</param>
    /// <returns>An instance of IPcPictureRefineOption, which is the requested refine option for pictures</returns>
    virtual PcPtr<IPcPictureRefineOption> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of refine options for pictures.
    /// </summary>
    /// <returns>An enumeration of IPcPictureRefineOption instances, each of which is a supported refine option for pictures</returns>
    virtual PcCollection<PcPtr<IPcPictureRefineOption>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_PICTURE_REFINE_SPEC_H
