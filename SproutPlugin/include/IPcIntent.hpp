#ifndef IPC_INTENT_H
#define IPC_INTENT_H

#include "HpPcApi.hpp"
#include "PcGuid.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcIntent represents an optional intent that can be used
/// when calling some SDK methods, in order to obtain a specific implementation
/// of the Sprout Platform functionality that the methods provide access to.
/// </summary>
/// <remarks>
/// The interface IPcIntent provides a unique identifier of the intent.
/// </remarks>
class HPPC_API IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcIntent.
    /// </summary>
    virtual ~IPcIntent() {}

    /// <summary>
    /// Gets the unique identifier of this intent.
    /// </summary>
    /// <returns>The unique identifier of this intent</returns>
    virtual const PcGuid& Identifier() const throw () = 0;
};

} }

#endif // IPC_INTENT_H
