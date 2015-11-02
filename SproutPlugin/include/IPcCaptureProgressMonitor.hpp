#ifndef IPC_CAPTURE_PROGRESS_MONITOR_H
#define IPC_CAPTURE_PROGRESS_MONITOR_H

#include "HpPcApi.hpp"
#include "PcException.hpp"
#include "IPcCaptureProgressObserver.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcCaptureProgressMonitor provides the functionality for
/// a capture-progress monitor.
/// </summary>
/// <remarks>
/// Capturing a moment can take some time, and it can take different amounts of time
/// depending on the prior states of the cameras. The enumeration PcCaptureProgressEventType
/// declares the event FlashEvent, which is raised when the flash happens during a moment
/// capture. By using a capture-progress observer that is notified about this event,
/// a Sprout app can synchronize user-interface feedback to the user (for example,
/// a shutter sound) with the flash.
/// </remarks>
class HPPC_API IPcCaptureProgressMonitor
{
public:
    /// <summary>
    /// Destroys the instance of IPcCaptureProgressMonitor.
    /// </summary>
    virtual ~IPcCaptureProgressMonitor() {}

    /// <summary>
    /// Adds a capture-progress observer that will be notified about events while capturing a moment.
    /// </summary>
    /// <param name="observer">The observer to add to the list of capture-progress observers</param>
    virtual void AddObserver(IPcCaptureProgressObserver* observer) throw (PcException) = 0;

    /// <summary>
    /// Removes an observer from the list of capture-progress observers.
    /// </summary>
    /// <param name="observer">The observer to remove from the list of capture-progress observers</param>
    virtual void RemoveObserver(IPcCaptureProgressObserver* observer) throw (PcException) = 0;

};

} }

#endif // IPC_CAPTURE_PROGRESS_MONITOR_H
