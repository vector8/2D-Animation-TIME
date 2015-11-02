#ifndef PC_CONNECTION_EXCEPTION_H
#define PC_CONNECTION_EXCEPTION_H

#include "HpPcApi.hpp"

#include "PcApiException.hpp"

namespace hp { namespace pc {

/// <summary>
/// Container for exceptions related to the connection with the Sprout Platform
/// </summary>
class HPPC_API PcConnectionException
    : public PcApiException
{
public:
    /// <summary>
    /// Constructs a PcConnectionException with a given message.
    /// </summary>
    /// <param name="message">The message associated with this PcApiException</param>
    PcConnectionException(const PcString& messsage) throw ();

    /// <summary>
    /// Destroys the instance of PcConnectionException.
    /// </summary>
    virtual ~PcConnectionException() throw ();
};

} }

#endif // PC_CONNECTION_EXCEPTION_H
