#ifndef IPC_OUTLINE_SPEC_H
#define IPC_OUTLINE_SPEC_H

#include "HpPcApi.hpp"
#include "IPcOutlineExtractSpecification.hpp"
#include "IPcOutlineRefineSpecification.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcOutlineSpecification provides access to options for outlines.
/// </summary>
class HPPC_API IPcOutlineSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcOutlineSpecification.
    /// </summary>
    virtual ~IPcOutlineSpecification() {}

    /// <summary>
    /// Gets the extract options that are supported for outlines.
    /// </summary>
    /// <returns>The supported extract options for outlines</returns>
    virtual const PcPtr<IPcOutlineExtractSpecification>& Extract() const throw () = 0;

    /// <summary>
    /// Gets the refine options that are supported for outlines.
    /// </summary>
    /// <returns>The supported refine options for outlines</returns>
    virtual const PcPtr<IPcOutlineRefineSpecification>& Refine() const throw () = 0;
};

} } }

#endif // IPC_OUTLINE_SPEC_H
