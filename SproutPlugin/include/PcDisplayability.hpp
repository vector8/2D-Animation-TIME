#ifndef PC_DISPLAYABILITY_H
#define PC_DISPLAYABILITY_H

#include "HpPcApi.hpp"

namespace hp { namespace pc {

/// <summary>
/// Enumerates the displayability states that a registered window (an instance
/// of the class IPcWindowRegistration) can have during execution of code by the Sprout Platform.
/// </summary>
/// <remarks>
/// The displayability state can be used to detected whether the registered window will
/// be visible to the user when the window is displayed. In addition, different
/// displayability states result in the Sprout Platform performing different actions when
/// IPcWindowRegistration::Display is called. An app can get the Displayability
/// property through the interface IPcWindowRegistration and add observers to be notified
/// of changes in displayability using AddObserver in that interface.
/// </remarks>
enum class HPPC_API PcDisplayability : int
{
    /// <summary>
    /// Mat screen is turned off because the touch mat is not connected.
    /// </summary>
    /// <remarks>
    /// The Sprout Platform cannot turn on the mat screen when the function IPcWindowRegistration::Display
    /// is called. Even though the mat screen is turned off, the SDK places the window on the mat screen,
    /// which will allow the window to be displayed when the touch mat is connected and the mat screen is
    /// turned on.
    /// </remarks>
    MatScreenNotAvailable = 1,

    /// <summary>
    /// Mat screen is turned on (and is visible by the user).
    /// </summary>
    /// <remarks>
    /// A user will be able to see and interact with the window after the app calls
    /// IPcWindowRegistration::Display.
    /// </remarks>
    MatScreenOn = 2,

    /// <summary>
    /// Mat screen is turned off (and is not visible by the user).
    /// </summary>
    /// <remarks>
    /// The Sprout Platform might try to turn on the mat screen, depending of the user's current interactions
    /// with the app. Turning on the mat screen will allow the user to see and interact with the 
    /// window after the function IPcWindowRegistration::Display is called. If the mat screen is
    /// turned on, then the displayability state will change to MatScreenOn. Even though the mat screen
    /// is turned off, the Sprout Platform places the window on the mat screen, which will allow the window to be
    /// displayed when the mat screen is turned on.
    /// </remarks>
    MatScreenOff = 3,
};

} }

#endif // PC_DISPLAYABILITY_H
