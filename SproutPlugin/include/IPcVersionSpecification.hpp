#ifndef IPC_VERSION_SPEC_H
#define IPC_VERSION_SPEC_H

#include "HpPcApi.hpp"
#include "PcVersion.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcVersionSpecification provides information about the version of the Sprout Platform and of the language binding used by the app.
/// </summary>
class HPPC_API IPcVersionSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcVersionSpecification.
    /// </summary>
    virtual ~IPcVersionSpecification() {}

    /// <summary>
    /// Gets the version of the Sprout Platform installed on this immersive computer.
    /// </summary>
    /// <returns>The Sprout Platform version</returns>
    virtual const PcPtr<PcVersion>& Platform() const throw () = 0;

    /// <summary>
    /// Gets the version of the Sprout API used by this app.
    /// </summary>
    /// <returns>The Sprout API version</returns>
    virtual int API() const throw () = 0;

    /// <summary>
    /// Finds a specific version of the Sprout Platform or language binding by using a unique identifier.
    /// </summary>
    /// <remarks>
    /// If the requested version of the Sprout Platform or language binding is supported, then Find returns an instance of PcVersion.
    /// If the requested version of the Sprout Platform or language binding is not supported, then Find returns a null pointer and an error code.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the Sprout Platform or language binding</param>
    /// <returns>An instance of PcVersion, which is the requested version</returns>
    virtual PcPtr<PcVersion> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of supported versions of the Sprout Platform and of language bindings.
    /// </summary>
    /// <returns>An enumeration of PcVersion instances, each of which is a supported version of the Sprout Platform or of a language binding</returns>
    virtual PcCollection<PcPtr<PcVersion>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_VERSION_SPEC_H
