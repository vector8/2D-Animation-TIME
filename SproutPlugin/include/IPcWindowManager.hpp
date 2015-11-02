#ifndef IPC_WINDOW_MANAGER_H
#define IPC_WINDOW_MANAGER_H

#include "HpPcApi.hpp"
#include "PcPixelPoint.hpp"
#include "PcPixelSize.hpp"

namespace hp { namespace pc {

/// <summary>
/// This interface defines methods that will be called by the Display method from IPcWindowRegistration
/// to properly configure the associated window in a platform independent way.
/// </summary>
class HPPC_API IPcWindowManager
{
public:
    /// <summary>
    /// Destroys the instance of IPcWindowManager.
    /// </summary>
    virtual ~IPcWindowManager() {}

    /// <summary>
    /// Moves the top-left corner of the window maintaining the same size.
    /// </summary>
    /// <param name="pos">New position for the top-left corner</param>
    virtual void Move(const PcPixelPoint& pos) throw () = 0;

    /// <summary>
    /// Resizes the window to match the specified size without moving its position.
    /// </summary>
    /// <param name="size">New size that the window should have</param>
    virtual void Resize(const PcPixelSize& size) throw () = 0;

    /// <summary>
    /// Removes all decorations from the window.
    /// </summary>
    virtual void RemoveDecoration() throw () = 0;

    /// <summary>
    /// Shows the associated window.
    /// </summary>
    virtual void Show() throw () = 0;
};

} }

#endif // IPC_WINDOW_MANAGER_H
