#ifndef PC_DEVICE_EXCEPTION_H
#define PC_DEVICE_EXCEPTION_H

#include "PcPlatformException.hpp"

namespace hp { namespace pc {

/// <summary>
/// Container for device exceptions raised by the Sprout Platform.
/// </summary>
class HPPC_API PcDeviceException
    : public PcPlatformException
{
public:
    /// <summary>
    /// Constructs a PcDeviceException with a given message and code.
    /// </summary>
    /// <param name="message">The message associated with this PcDeviceException</param>
    /// <param name="result">The PcResultStatus associated with this PcDeviceException</param>
    PcDeviceException(const PcString& message, const PcResultStatus& result) throw ();

    /// <summary>
    /// Destructor.
    /// </summary>
    virtual ~PcDeviceException() throw ();
};

} }

#endif // PC_DEVICE_EXCEPTION_H
