#ifndef IPC_TEXT_LANGUAGE_OPTION_H
#define IPC_TEXT_LANGUAGE_OPTION_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc { namespace specification {

/// <summary>
/// The interface IPcTextLanguageOption represents a language option for text.
/// </summary>
class HPPC_API IPcTextLanguageOption : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcTextLanguageOption.
    /// </summary>
    virtual ~IPcTextLanguageOption() {}
};

} } }

#endif // IPC_TEXT_LANGUAGE_OPTION_H
