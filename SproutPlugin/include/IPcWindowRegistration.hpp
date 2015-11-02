#ifndef IPC_WINDOW_REGISTRATION_H
#define IPC_WINDOW_REGISTRATION_H

#include "HpPcApi.hpp"
#include "IPcDisplayabilityObserver.hpp"
#include "PcDisplayability.hpp"
#include "PcException.hpp"
#include "IPcWindowManager.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcWindowRegistration provides a window handler for an application window
/// that needs to appear on the mat screen and that needs access to the touch mat.
/// </summary>
/// <remarks>
/// By registering a window, which creates an IPcWindowRegistration window handler, you can manage
/// an application window that will appear on the mat screen. Only a registered window can appear on
/// the mat screen and access touch functionality.
/// </remarks>
class HPPC_API IPcWindowRegistration
{
public:
    /// <summary>
    /// Destroys the instance of IPcWindowRegistration.
    /// </summary>
    virtual ~IPcWindowRegistration() {}

    /// <summary>
    /// Gets the window that this instance of the window handler will handle.
    /// </summary>
    /// <returns>The window handler</returns>
    virtual long long Window() const throw () = 0;

    /// <summary>
    /// Gets the displayability state of this registered window.
    /// </summary>
    /// <returns>
    /// The displayability state of this registered window
    /// </returns>
    virtual PcDisplayability Displayability() const throw () = 0;

    /// <summary>
    /// Adds an observer to the list of displayability observers.
    /// </summary>
    /// <remarks>
    /// For an app to receive displayability-change events that describe changes
    /// in the displayability of a registered window, the displayability observer must
    /// be added to the list of displayability observers.
    /// </remarks>
    /// <param name="observer">Observer to add to the list of displayability observers</param>
    virtual void AddObserver(IPcDisplayabilityObserver* observer) throw (PcException) = 0;

    /// <summary>
    /// Removes an observer from the list of displayability observers.
    /// </summary>
    /// <param name="observer">Observer to remove from the list of displayability observers</param>
    virtual void RemoveObserver(IPcDisplayabilityObserver* observer) throw (PcException) = 0;

    /// <summary>
    /// Unregisters the window with the Sprout Platform.
    /// </summary>
    virtual void Unregister() throw (PcException) = 0;

    /// <summary>
    /// Displays the registered window and enforces that the window is displayed on the mat screen.
    /// </summary>
    /// <remarks>
    /// Although it is possible to use external APIs to display the window on the mat screen, those
    /// APIs cannot do as good a job to ensure that the window is displayed on the mat screen.
    /// The Display function implements the required logic and uses the supplied IPcWindowManager to
    /// take care of moving the window from the monitor to the mat screen if necessary, and displays
    /// the window as a full-screen, uppermost, active window without borders.
    /// The correct behavior depends on the implementation of an appropriate IPcWindowManager specific
    /// to the graphical system in use. The methods from the manager will be called in the correct order
    /// and with the desired values, but is up to it to execute those requests.
    /// </remarks>
    /// <param name="manager">IPcWindowManager instance implementing platform dependent functionalities.</param>
    virtual void Display(IPcWindowManager* manager) throw (PcException) = 0;

};

} }

#endif // IPC_WINDOW_REGISTRATION_H
