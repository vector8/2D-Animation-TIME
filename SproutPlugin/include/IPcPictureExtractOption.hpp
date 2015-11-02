#ifndef IPC_PICTURE_EXTRACT_OPTION_H
#define IPC_PICTURE_EXTRACT_OPTION_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcPictureExtractOption represents an extract option for pictures.
/// </summary>
class HPPC_API IPcPictureExtractOption : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcPictureExtractOption.
    /// </summary>
    virtual ~IPcPictureExtractOption() {};
};

} } }

#endif // IPC_PICTURE_EXTRACT_OPTION_H
