#ifndef IPC_TEXT_EXTRACT_OPTION_H
#define IPC_TEXT_EXTRACT_OPTION_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTextExtractOption represents an extract option for text.
/// </summary>
class HPPC_API IPcTextExtractOption : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcTextExtractOption.
    /// </summary>
    virtual ~IPcTextExtractOption() {}
};

} } }

#endif // IPC_TEXT_EXTRACT_OPTION_H
