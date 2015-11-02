#ifndef PC_EXCEPTION_H
#define PC_EXCEPTION_H

#include "HpPcApi.hpp"
#include "PcResultStatus.hpp"

namespace hp { namespace pc {

/// <summary>
/// Container for all the exceptions raised by the binding.
/// </summary>
class PcException
{
public:
    /// <summary>
    /// Destructor.
    /// </summary>
    virtual ~PcException() throw () {}

    /// <summary>
    /// Returns a description of the raised exception.
    /// </summary>
    /// <returns>Message with exception description</returns>
    virtual const wchar_t* Message() const throw () = 0;

    /// <summary>
    /// Returns the PcResultStatus associated with this exception.
    /// </summary>
    /// <returns>PcResultStatus associated with excpetion</returns>
    virtual PcResultStatus Result() const throw () = 0;
};

} }

#endif // PC_EXCEPTION_H
