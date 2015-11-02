#ifndef IPC_PICTURE_SPEC_H
#define IPC_PICTURE_SPEC_H

#include "HpPcApi.hpp"
#include "IPcPictureExtractSpecification.hpp"
#include "IPcPictureRefineSpecification.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcPictureSpecification provides access to options for pictures.
/// </summary>
class HPPC_API IPcPictureSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcPictureSpecification.
    /// </summary>
    virtual ~IPcPictureSpecification() {}

    /// <summary>
    /// Gets extract options that are supported for pictures.
    /// </summary>
    /// <returns>The supported extract options for pictures</returns>
    virtual const PcPtr<IPcPictureExtractSpecification>& Extract() const throw () = 0;

    /// <summary>
    /// Gets refine options that are supported for pictures.
    /// </summary>
    /// <returns>The supported refine options for pictures</returns>
    virtual const PcPtr<IPcPictureRefineSpecification>& Refine() const throw () = 0;
};

} } }

#endif // IPC_PICTURE_SPEC_H
