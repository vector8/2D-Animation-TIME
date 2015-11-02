#ifndef IPC_CAMERA_SPEC_H
#define IPC_CAMERA_SPEC_H

#include "HpPcApi.hpp"
#include "IPcCamera.hpp"
#include "PcGuid.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcCollection.hpp"

namespace hp { namespace pc {

/// <summary>
/// The namespace hp::pc::specification encompasses the APIs for specifications
/// in the C++ binding for the Sprout SDK.
/// </summary>
/// <remarks>
/// The top-level specification interface, IPcSpecification, is in the namespace hp::pc.
/// </remarks>
namespace specification {

/// <summary>
/// The interface IPcCameraSpecification provides information about the cameras
/// that are supported by the Sprout Platform.
/// </summary>
/// <remarks>
/// These cameras actually represent software interfaces to the hardware cameras. Beyond
/// the software interface, there might or might not actually be a hardware camera of some type.
/// For example, the hardware camera might not be present, or it might be turned off.
/// </remarks>
class HPPC_API IPcCameraSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcCameraSpecification.
    /// </summary>
    virtual ~IPcCameraSpecification() {}

    /// <summary>
    /// Gets information about the high-definition camera.
    /// </summary>
    /// <returns>Information about the high-definition camera</returns>
    virtual const PcPtr<IPcCamera>& HighDefinition() const throw () = 0;

    /// <summary>
    /// Gets information about the low-definition camera
    /// </summary>
    /// <returns>Information about the low-definition camera</returns>
    virtual const PcPtr<IPcCamera>& LowDefinition() const throw () = 0;

    /// <summary>
    /// Gets information about the infrared camera.
    /// </summary>
    /// <returns>Information about the infrared camera</returns>
    virtual const PcPtr<IPcCamera>& Infrared() const throw () = 0;

    /// <summary>
    /// Gets information about the depth camera.
    /// </summary>
    /// <returns>Information about the depth camera</returns>
    virtual const PcPtr<IPcCamera>& Depth() const throw () = 0;

    /// <summary>
    /// Finds a specific camera that is supported by the Sprout Platform by using a unique identifier,
    /// in order to obtain the information in the interface IPcCamera for that camera.
    /// </summary>
    /// <param name="identifier">Unique identifier of the camera</param>
    /// <returns>
    /// If the specific camera is supported, then Find returns a pointer to an instance
    /// of IPcCamera, which provides information about the camera. If the specific camera
    /// is not supported, then Find returns a null pointer and an error code. Note that
    /// the camera does not have to be available (present and turned on) to obtain information
    /// about the camera.
    /// </returns>
    virtual PcPtr<IPcCamera> Find(const PcGuid& identifier) throw (PcException) = 0;

    /// <summary>
    /// Gets the collection of cameras supported by the Sprout Platform, and for each the information
    /// in the interface IPcCamera.
    /// </summary>
    /// <returns>
    /// An enumeration of IPcCamera instances, each of which provides information about
    /// a specific supported camera
    /// </returns>
    virtual PcCollection<PcPtr<IPcCamera>> Enumerate() throw (PcException) = 0;
};

typedef PcPtr < IPcCameraSpecification > IPcCameraSpecificationPcPtr;

} } }

#endif // IPC_CAMERA_SPEC_H
