#ifndef PC_API_EXCEPTION_H
#define PC_API_EXCEPTION_H

#include "HpPcApi.hpp"

#include "PcException.hpp"
#include "PcString.hpp"

namespace hp { namespace pc {

/// <summary>
/// Container for all the exceptions raised by the Sprout API
/// </summary>
class HPPC_API PcApiException
    : public PcException
{
public:
    /// <summary>
    /// Constructs a PcApiException for a given message and error code.
    /// </summary>
    /// <param name="message">The message associated with this PcApiException</param>
    /// <param name="errorCode">Error associated with this PcApiException</param>
    PcApiException(const PcString& messsage, int errorCode) throw ();

    /// <summary>
    /// Destroys the instance of PcApiException.
    /// </summary>
    virtual ~PcApiException() throw ();

    /// <summary>
    /// Returns a description of the raised exception.
    /// </summary>
    /// <returns>Message with exception description</returns>
    virtual const wchar_t* Message() const throw ();

    /// <summary>
    /// Returns the PcResultStatus associated with this exception.
    /// </summary>
    /// <returns>PcResultStatus associated with excpetion</returns>
    virtual PcResultStatus Result() const throw ();

private:

    PcString mMessage;
    PcResultStatus mResult;
};

} }

#endif // PC_API_EXCEPTION_H
