#ifndef IPC_OUTLINE_REFINE_OPTION_H
#define IPC_OUTLINE_REFINE_OPTION_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcOutlineRefineOption represents a refine option for outlines.
/// </summary>
class HPPC_API IPcOutlineRefineOption : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcOutlineRefineOption.
    /// </summary>
    virtual ~IPcOutlineRefineOption() {};
};

} } }

#endif //IPC_OUTLINE_REFINE_OPTION_H
