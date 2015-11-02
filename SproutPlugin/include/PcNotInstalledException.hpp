#ifndef PC_NOT_INSTALLED_EXCEPTION_H
#define PC_NOT_INSTALLED_EXCEPTION_H

#include "PcException.hpp"

/******************************************************************************************/

namespace hp { namespace pc {

/// <summary>
/// Exception thrown if the Sprout API used by the binding could not be found.
/// </summary>
/// <remarks>
/// The implementation for accessing Sprout functionality through the C++ bindings is located
/// in the Sprout API DLL which is installed and managed by the Sprout Platform.
/// As the C++ bindings are only DLL forwarding the symbols definition to that DLL, they become
/// broken if the Sprout API cannot be found. In that case, any attempt to use the binding will
/// throw this special exception that doesn't rely on the Sprout API.
/// </remarks>
class PcNotInstalledException
    : public PcException
{
public:
    /// <summary>
    /// Returns a description of the raised exception.
    /// </summary>
    /// <returns>Message with exception description</returns>
    virtual const wchar_t* Message() const throw ()
    {
        return L"Could not find the Sprout API DLL. Please update the Sprout Platform.";
    }

    /// <summary>
    /// This exception does not have any associated status.
    /// </summary>
    /// <returns>PcResultStatus associated with excpetion</returns>
    virtual PcResultStatus Result() const throw ()
    {
        // Not relevant for this exception.
        return PcResultStatus { 0, 0, 0, 0 };
    }
};

} }

/******************************************************************************************/

// The code bellow is used to install a custom DelayLoad hook that will throw an instance
// of PcNotInstalledException in case of failure.

#if defined(_WIN32) && !defined(HPPC_EXPORTS) && !defined(HPPC_DISABLE_NOT_INSTALLED_EXCEPTION)

#pragma comment(lib, "delayimp.lib")

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <delayimp.h>

static FARPROC __stdcall DelayLoadHook(unsigned dliNotify, PDelayLoadInfo pdli)
{
    switch (dliNotify)
    {
    case dliFailLoadLib:
    case dliFailGetProc:
    {
        throw hp::pc::PcNotInstalledException();
        break;
    }
    default:
        break;
    }

    return NULL;
}

struct HookInstaller
{
    HookInstaller()
    {
        // Update the failure hook to use the custom method.
        __pfnDliFailureHook2 = DelayLoadHook;
    }
};

// Declare as static to avoid multiple definition across translation units that include this header.
static HookInstaller instance;

#endif

/******************************************************************************************/

#endif //PC_NOT_INSTALLED_EXCEPTION_H
