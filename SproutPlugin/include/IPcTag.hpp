#ifndef IPC_TAG_H
#define IPC_TAG_H

#include "HpPcApi.hpp"
#include "IPcIntent.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcTag represents a classification tag.
/// </summary>
/// <remarks>
/// Use the interface IPcClassificationSpecification to access the supported tags 
/// that are returned by the method IPcLink::Classify.
/// </remarks>
class HPPC_API IPcTag : public IPcIntent
{
public:
    /// <summary>
    /// Destroys the instance of IPcTag.
    /// </summary>
    virtual ~IPcTag() {}
};

} }

#endif // IPC_TAG_H
