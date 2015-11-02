#ifndef HPPC_H
#define HPPC_H

#include "HpPcApi.hpp"

#include "IPcLink.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"
#include "PcApiException.hpp"
#include "PcTimeoutException.hpp"
#include "PcConnectionException.hpp"
#include "PcPlatformException.hpp"
#include "PcDeviceException.hpp"
#include "PcNotInstalledException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class HPPC provides a factory for creating Sprout platform links.
/// </summary>
/// <remarks>
/// Platform links (instances of IPcLink) are the necessary starting points that allow access to all
/// of the functionality of the Sprout Platform.
/// </remarks>
class HPPC_API HPPC
{
public:
    /// <summary>
    /// Creates a platform link as the entry point for accessing all functionality of the Sprout Platform. 
    /// </summary>
    /// <returns>An instance of IPcLink, which provides access to all Sprout Platform functionality</returns>
    static PcPtr<IPcLink> CreateLink() throw (PcException);

private:
    HPPC();
    HPPC(const HPPC&);
};


} }

#endif // HPPC_H
