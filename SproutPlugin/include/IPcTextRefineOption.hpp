#ifndef IPC_TEXT_REFINE_OPTION_H
#define IPC_TEXT_REFINE_OPTION_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTextRefineOption represents a refine option for text.
/// </summary>
class HPPC_API IPcTextRefineOption : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcTextRefineOption.
    /// </summary>
    virtual ~IPcTextRefineOption() {}
};

} } }

#endif // IPC_TEXT_REFINE_OPTION_H
