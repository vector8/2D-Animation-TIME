#ifndef IPC_CAPTURE_PROGRESS_EVENT_ARGS
#define IPC_CAPTURE_PROGRESS_EVENT_ARGS

#include "HpPcApi.hpp"

namespace hp { namespace pc {

/// <summary>
/// Enumerates the capture-progress events that can be raised while capturing a moment.
/// </summary>
enum class HPPC_API PcCaptureProgressEventType : int
{
    /// <summary>
    /// The flash has occurred.
    /// </summary>
    FlashEvent = 0
};

/// <summary>
/// The class IPcCaptureProgressEventArgs is a class for storing information about the events
/// that occur while capturing a moment.
/// </summary>
/// <remarks>
/// This event is received in the IPcCaptureProgressObserver::Updated method.
/// </remarks>
class HPPC_API IPcCaptureProgressEventArgs
{
public:
    /// <summary>
    /// Destroys the instance of IPcCaptureProgressEventArgs.
    /// </summary>
    virtual ~IPcCaptureProgressEventArgs() {}

    /// <summary>
    /// Gets the type of the capture-progress event that was generated.
    /// </summary>
    /// <returns>The type of the capture-progress event that was generated</returns>
    virtual PcCaptureProgressEventType EventType() const throw () = 0;
};

} }

#endif //IPC_CAPTURE_PROGRESS_EVENT_ARGS
