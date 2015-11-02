#ifndef IPC_PICTURE_REFINE_OPTION_H
#define IPC_PICTURE_REFINE_OPTION_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcPictureRefineOption represents a refine option for pictures.
/// </summary>
class HPPC_API IPcPictureRefineOption : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcPictureRefineOption.
    /// </summary>
    virtual ~IPcPictureRefineOption() {};
};

} } }

#endif // IPC_PICTURE_REFINE_OPTION_H
