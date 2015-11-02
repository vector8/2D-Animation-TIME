#ifndef IPC_CAPTURE_PROGRESS_OBSERVER_H
#define IPC_CAPTURE_PROGRESS_OBSERVER_H

#include "HpPcApi.hpp"
#include "PcPtr.hpp"
#include "IPcCaptureProgressEventArgs.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcCaptureProgressObserver provides the functionality for an observer of
/// capture-progress events. It specifies a contract to the app developer and provides a
/// virtual method for receiving the capture-progress events.
/// </summary>
/// <remarks>
/// The app developer must create a concrete implementation of this class to receive
/// capture-progress events that occur while capturing a moment if the method overload
/// CaptureMoment that takes a instance of IPcCaptureProgressMonitor as a parameter
/// was used. An instance of this monitor can be created by using the method
/// CreateCaptureProgressMonitor that is declared on the interface IPcLink.
/// The capture-progress observer instance must be added to the monitor using the
/// method AddObserver method that is declared on the interface IPcCaptureProgressMonitor.
/// </remarks>
class HPPC_API IPcCaptureProgressObserver
{
public:
    /// <summary>
    /// Default constructor.
    /// </summary>
    IPcCaptureProgressObserver();

    /// <summary>
    /// Destroys the instance of IPcCaptureProgressObserver.
    /// </summary>
    virtual ~IPcCaptureProgressObserver();

    /// <summary>
    /// Receives a capture-progress event, which is raised each time a meaningful event occurs
    /// while capturing a moment.
    /// </summary>
    /// <remarks>
    /// An observer must implement this method to receive notifications about capture-progress events.
    /// </remarks>
    /// <param name="args">Arguments for a capture-progress event</param>
    virtual void Updated(const PcPtr<IPcCaptureProgressEventArgs>& args) throw () = 0;
};

} }

#endif // IPC_CAPTURE_PROGRESS_OBSERVER_H
