#ifndef PC_RESULT_STATUS_H
#define PC_RESULT_STATUS_H

#include "HpPcApi.hpp"

namespace hp { namespace pc {

/// <summary>
/// The PcResultStatus is the result for every API call and represents the response for basically every 
/// Sprout system call
/// </summary>
struct PcResultStatus
{
    /// <summary>
    /// Gets the facility code associated with the PcResultStatus.
    /// <summary>
    /// <returns>
    /// The facility code which this PcResultStatus is associated to. For more information on facility codes
    /// please consult the Sprout developer documentation.
    /// </returns>
    int Facility;

    /// <summary>
    /// Gets the ErrorCode code associated with the PcResultStatus.
    /// <summary>
    /// <returns>
    /// The specific error code represented by this PcResultStatus. For more information on error codes
    /// please consult the Sprout developer documentation.
    /// </returns>
    int ErrorCode;

    /// <summary>
    /// Gets the severity level associated with the PcResultStatus.
    /// <summary>
    /// <returns>
    /// The severity level for this PcResultStatus. For more information on severity level
    /// please consult the Sprout developer documentation.
    /// </returns>
    int Severity;

    /// <summary>
    /// Gets the HResult associated with the PcResultStatus
    /// <summary>
    /// <returns>
    /// The PcResultStatus in HResult format.
    /// </returns>
    int HResult;
};

} }

#endif // PC_RESULT_STATUS_H
