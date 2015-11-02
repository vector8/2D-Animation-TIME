#ifndef IPC_TEXT_SPEC_H
#define IPC_TEXT_SPEC_H

#include "HpPcApi.hpp"
#include "IPcTextExtractSpecification.hpp"
#include "IPcTextRefineSpecification.hpp"
#include "IPcTextLanguageSpecification.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTextSpecification provides access to options for text.
/// </summary>
class HPPC_API IPcTextSpecification
{
public:
    /// <summary>
    /// Destroys the instance of IPcTextSpecification.
    /// </summary>
    virtual ~IPcTextSpecification() {}

    /// <summary>
    /// Gets extract options that are supported for text.
    /// </summary>
    /// <returns>The supported extract options for text</returns>
    virtual const PcPtr<IPcTextExtractSpecification>& Extract() const throw () = 0;

    /// <summary>
    /// Gets refine options that are supported for text.
    /// </summary>
    /// <returns>The supported refine options for text</returns>
    virtual const PcPtr<IPcTextRefineSpecification>& Refine() const throw () = 0;

    /// <summary>
    /// Gets language options that are supported for text.
    /// </summary>
    /// <returns>The supported language options for text</returns>
    virtual const PcPtr<IPcTextLanguageSpecification>& Language() const throw () = 0;
};

} } }

#endif // IPC_TEXT_SPEC_H
