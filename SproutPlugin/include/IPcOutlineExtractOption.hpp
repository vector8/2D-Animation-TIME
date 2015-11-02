#ifndef IPC_OUTLINE_EXTRACT_OPTION_H
#define IPC_OUTLINE_EXTRACT_OPTION_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcOutlineExtractOption represents an extract option for outlines.
/// </summary>
class HPPC_API IPcOutlineExtractOption : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcOutlineExtractOption.
    /// </summary>
    virtual ~IPcOutlineExtractOption() {};
};

} } }

#endif // IPC_OUTLINE_EXTRACT_OPTION_H
