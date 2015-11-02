#ifndef IPC_MOMENT_H
#define IPC_MOMENT_H

#include "HpPcApi.hpp"
#include "PcGuid.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcMoment contains a moment of life captured by Sprout.
/// </summary>
/// <remarks>
/// Use Extract methods in the interface IPcLink to extract the contents
/// of the moment.
/// </remarks>
class HPPC_API IPcMoment
{
public:
    /// <summary>
    /// Destroys the instance of IPcMoment.
    /// </summary>
    virtual ~IPcMoment() {}

    /// <summary>
    /// Gets the unique identifier of this moment.
    /// </summary>
    /// <returns>The unique identifier of this moment</returns>
    virtual const PcGuid& Identifier() const throw () = 0;
};

} }

#endif // IPC_MOMENT_H
