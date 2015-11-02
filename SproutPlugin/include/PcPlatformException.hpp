#ifndef PC_PLATFORM_EXCEPTION_H
#define PC_PLATFORM_EXCEPTION_H

#include "HpPcApi.hpp"

#include "PcException.hpp"
#include "PcString.hpp"

namespace hp { namespace pc {

/// <summary>
/// Container for all the exceptions raised by the Sprout Platform
/// </summary>
class HPPC_API PcPlatformException
    : public PcException
{
public:
    /// <summary>
    /// Constructs a PcPlatformException with a given message and code.
    /// </summary>
    /// <param name="message">The message associated with this PcPlatformException</param>
    /// <param name="result">The PcResultStatus associated with this PcPlatformException</param>
    PcPlatformException(const PcString& message, const PcResultStatus& result) throw ();

    /// <summary>
    /// Destructor.
    /// </summary>
    virtual ~PcPlatformException() throw ();

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

#endif // PC_PLATFORM_EXCEPTION_H
