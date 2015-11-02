#ifndef PC_VERSION_H
#define PC_VERSION_H

#include "HpPcApi.hpp"
#include "PcString.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcVersion represents the version of the Sprout Platform or of a language binding of the Sprout SDK.
/// </summary>
class HPPC_API PcVersion
{
public:

    PcVersion();
    PcVersion(int major, int minor, int revision, int build);

    /// <summary>
    /// Gets the major version.
    /// </summary>
    /// <returns>
    /// The major version of the Sprout Platform or language binding
    /// </returns>
    int  Major() const throw ();

    /// <summary>
    /// Gets the minor version.
    /// </summary>
    /// <returns>
    /// The minor version of the Sprout Platform or language binding
    /// </returns>
    int  Minor() const throw ();

    /// <summary>
    /// Gets the revision number.
    /// </summary>
    /// <returns>
    /// The revision number of the Sprout Platform or language binding
    /// </returns>
    int  Revision() const throw ();

    /// <summary>
    /// Gets the build number.
    /// </summary>
    /// <returns>
    /// The build number of the Sprout Platform or language binding
    /// </returns>
    int  Build() const throw ();

    /// <summary>
    /// Converts the version specification to a string representation.
    /// </summary>
    /// <returns>
    /// A string representation of the version of the Sprout Platform or of the language binding
    /// </returns>
    PcString ToString() const throw (PcException);

private:
    int mMajor;
    int mMinor;
    int mRevision;
    int mBuild;
};

} }

#endif // PC_VERSION_H
