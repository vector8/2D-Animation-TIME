#ifndef IPC_SPECIFICATION_H
#define IPC_SPECIFICATION_H

#include "HpPcApi.hpp"

#include "IPcVersionSpecification.hpp"
#include "IPcCameraSpecification.hpp"
#include "IPcScreenSpecification.hpp"
#include "IPcPictureSpecification.hpp"
#include "IPcOutlineSpecification.hpp"
#include "IPcTextSpecification.hpp"
#include "IPcClassificationSpecification.hpp"
#include "IPcTouchSpecification.hpp"
#include "PcPtr.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcSpecification provides access to other interfaces used for getting
/// information about the Sprout immersive computer and Sprout Platform, as well as access
/// to interfaces that define options for the Sprout immersive computer and Sprout Platform.
/// </summary>
/// <remarks>
/// The interface IPcSpecification provides access to other interfaces for getting
/// the versions of the Sprout Platform and the language binding used by an app; for
/// getting information about the cameras and screens on the immersive computer; for
/// Sprout Platform options for pictures, outlines, and text; for classification tags
/// that classify the contents of a moment; and for the types of touch layers.
/// </remarks>
class HPPC_API IPcSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcSpecification.
    /// </summary>
    virtual ~IPcSpecification() {}

    /// <summary>
    /// Gets version information about the Sprout Platform and language binding.
    /// </summary>
    /// <returns>The versions of the Sprout Platform and language binding</returns>
    virtual const PcPtr<specification::IPcVersionSpecification>& Version() const throw () = 0;

    /// <summary>
    /// Gets camera information.
    /// </summary>
    /// <returns>Information about the supported cameras</returns>
    virtual const PcPtr<specification::IPcCameraSpecification>& Camera() const throw () = 0;

    /// <summary>
    /// Gests screen information.
    /// </summary>
    /// <returns>Information about the supported screens</returns>
    virtual const PcPtr<specification::IPcScreenSpecification>& Screen() const throw () = 0;

    /// <summary>
    /// Gets options for pictures.
    /// </summary>
    /// <returns>The supported options for pictures</returns>
    virtual const PcPtr<specification::IPcPictureSpecification>& Picture() const throw () = 0;

    /// <summary>
    /// Gets options for outlines.
    /// </summary>
    /// <returns>The supported options for outlines</returns>
    virtual const PcPtr<specification::IPcOutlineSpecification>& Outline() const throw () = 0;

    /// <summary>
    /// Gets options for text.
    /// </summary>
    /// <returns>The supported options for text</returns>
    virtual const PcPtr<specification::IPcTextSpecification>& Text() const throw () = 0;

    /// <summary>
    /// Gets classification tags.
    /// </summary>
    /// <returns>The supported classification tags</returns>
    virtual const PcPtr<specification::IPcClassificationSpecification>& Classification() const throw () = 0;

    /// <summary>
    /// Gets touch layer types.
    /// </summary>
    /// <returns>The supported touch layer types</returns>
    virtual const PcPtr<specification::IPcTouchSpecification>& Touch() const throw () = 0;
};

} }

#endif // IPC_SPECIFICATION_H
