#ifndef PC_TIMEOUT_EXCEPTION_H
#define PC_TIMEOUT_EXCEPTION_H

#include "PcApiException.hpp"

namespace hp { namespace pc { 

/// <summary>
/// Exception thrown when an API request timeout.
/// </summary>
class HPPC_API PcTimeoutException
    : public PcApiException
{
public:
    /// <summary>
    /// Constructs a PcTimeoutException.
    /// </summary>
    PcTimeoutException() throw ();

    /// <summary>
    /// Destructor.
    /// </summary>
    virtual ~PcTimeoutException() throw ();
};

} }

#endif //PC_TIMEOUT_EXCEPTION_H
