#ifndef IPC_SCREEN_SPEC_H
#define IPC_SCREEN_SPEC_H

#include "HpPcApi.hpp"
#include "IPcScreen.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcScreenSpecification provides information about the screens that
/// are supported by the Sprout Platform.
/// </summary>
/// <remarks>
///  These screens actually represent software interfaces to the hardware screens. Beyond
///  the software interface, there might or might not actually be a hardware screen of some type.
///  For example, the hardware screen might not be present, or it might be turned off.
/// </remarks>
class HPPC_API IPcScreenSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcScreenSpecification.
    /// </summary>
    virtual ~IPcScreenSpecification() {}

    /// <summary>
    /// Gets information about the mat screen projected by the projector on top of the touchmat.
    /// </summary>
    /// <returns>Information about the mat screen</returns>
    virtual const PcPtr<IPcScreen>& Mat() const throw () = 0;

    /// <summary>
    /// Gets information about the monitor screen.
    /// </summary>
    /// <returns>Information about the monitor screen</returns>
    virtual const PcPtr<IPcScreen>& Monitor() const throw () = 0;

    /// <summary>
    /// Finds a specific screen that is supported by the Sprout Platform by using a unique identifier,
    /// in order to obtain the information in the interface IPcScreen for that screen.
    /// </summary>
    /// <remarks>
    /// If the requested screen is supported, then Find returns an instance of IPcScreen.
    /// If the requested screen is not supported, then Find returns a null pointer and an error code.
    /// Note that the screen does not have to be available (present and turned on) to obtain information
    /// about the screen.
    /// </remarks>
    /// <param name="identifier">Unique identifier of the screen</param>
    /// <returns>An instance of IPcScreen, which provides information about the screen</returns>
    virtual PcPtr<IPcScreen> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of screens supported by the Sprout Platform, and for each the information in
    /// the interface IPcScreen.
    /// </summary>
    /// <returns>An enumeration of IPcScreen instances, each of which provides information about a supported screen</returns>
    virtual PcCollection<PcPtr<IPcScreen>> Enumerate() throw (PcException) = 0;
};

} } }

#endif // IPC_SCREEN_SPEC_H
