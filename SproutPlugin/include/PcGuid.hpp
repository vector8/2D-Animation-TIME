#ifndef PC_GUID_H
#define PC_GUID_H

#pragma warning(disable:4251)

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcGuid represents a globally unique identifier (GUID).
/// </summary>
class HPPC_API PcGuid
{
public:
    /// <summary>
    /// Creates a new PcGuid using the default constructor, which creates a PcGuid with all bytes zero.
    /// </summary>
    /// <returns>An instance of PcGuid</returns>
    PcGuid();

    /// <summary>
    /// Creates a new PcGuid using the supplied bytes.
    /// </summary>
    /// <param name="bytes">Array with 16 bytes (128 bits)</param>
    /// <returns>An instance of PcGuid</returns>
    PcGuid(unsigned char* bytes);

    /// <summary>
    /// Checks whether the PcGuid is zeroed (if all bytes are zero).
    /// </summary>
    /// <returns>True if all bytes are zero, false otherwise</returns>
    bool IsZero() const throw ();

    /// <summary>
    /// Converts a PcGuid to a string format.
    /// </summary>
    /// <returns>String representation of the PcGuid</returns>
    PcString ToString() const throw (PcException);

    /// <summary>
    /// Generates a new random PcGuid.
    /// </summary>
    /// <returns>An instance of PcGuid</returns>
    static PcGuid Generate() throw (PcException);

    /// <summary>
    /// Generates a new PcGuid from the supplied string.
    /// </summary>
    /// <remarks>
    /// The source string must be in the format "{00000000-0000-0000-0000-000000000000}"
    /// </remarks>
    /// <param name="str">String describing all 128 bits of of the GUID</param>
    /// <returns>An instance of PcGuid</returns>
    static PcGuid FromString(const PcString& str) throw (PcException);

private:

    unsigned char mBytes[16];
};

/// <summary>
/// Tests whether two PcGuids are equal.
/// </summary>
/// <param name="left">First PcGuid to compare</param>
/// <param name="right">Second PcGuid to compare</param>
/// <returns>True if equal, false otherwise</returns>
HPPC_API bool operator == (const PcGuid& left, const PcGuid& right);

/// <summary>
/// Tests whether two PcGuids are different.
/// </summary>
/// <param name="left">First PcGuid to compare</param>
/// <param name="right">Second PcGuid to compare</param>
/// <returns>True if the two PcGuides are different, and false otherwise</returns>
HPPC_API bool operator != (const PcGuid& left, const PcGuid& right);

/// <summary>
/// Tests whether the first PcGuid is less than the second PcGuid.
/// </summary>
/// <param name="left">First PcGuid to compare</param>
/// <param name="right">Second PcGuid to compare</param>
/// <returns>True if the first PcGuid is smaller, and false otherwise</returns>
HPPC_API bool operator < (const PcGuid& left, const PcGuid& right);

/// <summary>
/// Tests whether the first PcGuid is greater than the second PcGuid.
/// </summary>
/// <param name="left">First PcGuid to compare</param>
/// <param name="right">Second PcGuid to compare</param>
/// <returns>True if the first PcGuid is larger, and false otherwise</returns>
HPPC_API bool operator > (const PcGuid& left, const PcGuid& right);

/// <summary>
/// Tests whether the first PcGuid is less than or equal to the second PcGuid.
/// </summary>
/// <param name="left">First PcGuid to compare</param>
/// <param name="right">Second PcGuid to compare</param>
/// <returns>True if the first PcGuid is smaller or equal, and false otherwise</returns>
HPPC_API bool operator <= (const PcGuid& left, const PcGuid& right);

/// <summary>
/// Tests whether the first PcGuid is greater than or equal to the second PcGuid.
/// </summary>
/// <param name="left">First PcGuid to compare</param>
/// <param name="right">Second PcGuid to compare</param>
/// <returns>True if the first PcGuid is larger or equal, and false otherwise</returns>
HPPC_API bool operator >= (const PcGuid& left, const PcGuid& right);

} }

#endif // PC_GUID_H
