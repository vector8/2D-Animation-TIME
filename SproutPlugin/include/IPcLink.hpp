#ifndef IPC_LINK_H
#define IPC_LINK_H

#include "HpPcApi.hpp"

#include "IPcWindowRegistration.hpp"
#include "IPcTouch.hpp"
#include "IPcTouchLayer.hpp"
#include "IPcMoment.hpp"
#include "IPcPicture.hpp"
#include "IPcCamera.hpp"
#include "IPcOutline.hpp"
#include "IPcSpecification.hpp"
#include "IPcOutlineExtractOption.hpp"
#include "IPcPictureExtractOption.hpp"
#include "IPcTextExtractOption.hpp"
#include "IPcCommunicationHandler.hpp"
#include "IPcClassification.hpp"
#include "IPcObjectTrackingHandler.hpp"
#include "PcTrainingImage.hpp"
#include "IPcText.hpp"
#include "IPcCaptureProgressMonitor.hpp"
#include "PcPtr.hpp"
#include "PcException.hpp"

namespace hp { namespace pc {

/// <summary>
/// The interface IPcLink provides access to all functionality of the Sprout Platform.
/// </summary>
/// <remarks>
/// An application must create an instance of the platform link as a member
/// of the calling application's application class. While the platform link
/// instance exists, your application can provide Sprout Platform features.
/// </remarks>
class HPPC_API IPcLink
{
public:
    /// <summary>
    /// Destroys an instance of IPcLink and releases resources that were used by the platform link.
    /// </summary>
    virtual ~IPcLink() {}

    /// <summary>
    /// Captures a moment, which organizes all of the data captured by Sprout cameras
    /// at a specific point in time by.
    /// </summary>
    /// <remarks>
    /// The moment contains raw sensor data. To obtain usable data such as images, you must
    /// use methods such as ExtractPicture that extract information from the moment.
    /// </remarks>
    /// <returns>An instance of IPcMoment, which contains the raw data for the moment</returns>
    virtual PcPtr<IPcMoment> CaptureMoment() throw (PcException) = 0;

    /// <summary>
    /// Captures a moment, which organizes all of the data captured by Sprout cameras
    /// at a specific point in time, and uses a capture-progress monitor to find out
    /// when the flash happens.
    /// </summary>
    /// <remarks>
    /// The moment contains raw sensor data. To obtain usable data such as images, you must
    /// use methods such as ExtractPicture that extract information from the moment.
    /// By using a capture-progress monitor, a Sprout app can synchronize user-interface
    /// feedback to the user (for example, a shutter sound) with the flash.
    /// </remarks>
    /// <param name="captureProgressMonitor">An instance of the capture-progress monitor</param>
    /// <returns>An instance of IPcMoment, which contains the raw data for the moment</returns>
    virtual PcPtr<IPcMoment> CaptureMoment(const PcPtr<IPcCaptureProgressMonitor>& captureProgressMonitor) throw (PcException) = 0;

    /// <summary>
    /// Creates a moment from an image, for example, from an image obtained from the Web.
    /// </summary>
    /// <remarks>
    /// The data in a moment created from an image differs from the data in a captured moment.
    /// </remarks>
    /// <param name="image">Image from which to create the moment</param>
    /// <returns>An instance of IPcMoment, which contains the raw data for the moment</returns>
    virtual PcPtr<IPcMoment> CaptureMoment(const PcPtr<PcImage>& image) throw (PcException) = 0;

    /// <summary>
    /// Extracts pictures from a moment and allows the platform to decide the extract option
    /// for pictures to use.
    /// </summary>
    /// <remarks>
    /// If this is the first method call to extract pictures or outlines from the moment, then
    /// the current implementation uses the extract option Object, and the method call extracts
    /// high resolution pictures of the work area and of objects on the work area. If this is a
    /// method call after an earlier call to extract pictures or outlines from this moment, then
    /// this call uses the same extract option (explicit or decided by the platform) as the
    /// immediately prior method call. This permits the platform to use data that has already
    /// been extracted and to perform fewer computations.
    /// </remarks>
    /// <param name="moment">Moment from which to extract the high-resolution pictures</param>
    /// <returns>An instance of IPcPicture, which organizes the extracted pictures in a tree structure</returns>
    virtual PcPtr<IPcPicture> ExtractPicture(const PcPtr<IPcMoment>& moment) throw (PcException) = 0;

    /// <summary>
    /// Extracts pictures from a moment using the specified extract option.
    /// </summary>
    /// <param name="moment">Moment from which to extract the pictures</param>
    /// <param name="option">Extract option to use for the extraction</param>
    /// <returns>An instance of IPcPicture, which organizes the extracted pictures in a tree structure</returns>
    virtual PcPtr<IPcPicture> ExtractPicture(const PcPtr<IPcMoment>& moment, const PcPtr<specification::IPcPictureExtractOption>& option) throw (PcException) = 0;

    /// <summary>
    /// Extracts outlines from a moment and allows the platform to decide the extract option
    /// for outlines to use.
    /// </summary>
    /// <remarks>
    /// If this is the first method call to extract pictures or outlines from the moment, then
    /// the current implementation uses the extract option Object, and the method call extracts
    /// outline of the work area and of objects on the work area. If this is a method call after
    /// an earlier call to extract pictures or outlines from this moment, then this call uses
    /// the same extract option (explicit or decided by the platform) as the immediately prior
    /// method call. This permits the platform to use data that has already been extracted and
    /// to perform fewer computations.
    /// </remarks>
    /// <param name="moment">Moment from which to extract the outlines</param>
    /// <returns>An instance of IPcOutline, which organizes the extracted outlines in a tree structure</returns>
    virtual PcPtr<IPcOutline> ExtractOutline(const PcPtr<IPcMoment>& moment) throw (PcException) = 0;

    /// <summary>
    /// Extracts outlines from a moment using the specified extract option.
    /// </summary>
    /// <param name="moment">Moment from which to extract the outlines</param>
    /// <param name="option">Extract option to use for the extraction</param>
    /// <returns>An instance of IPcOutline, which organizes the extracted outlines in a tree structure</returns>
    virtual PcPtr<IPcOutline> ExtractOutline(const PcPtr<IPcMoment>& moment, const PcPtr<specification::IPcOutlineExtractOption>& option) throw (PcException) = 0;

    /// <summary>
    /// Extracts text from a moment.
    /// </summary>
    /// <param name="moment">Moment from which to extract the text</param>
    /// <returns>An instance of IPcText, which organizes the extracted text in a tree structure</returns>
    virtual PcPtr<IPcText> ExtractText(const PcPtr<IPcMoment>& moment) throw (PcException) = 0;

    /// <summary>
    /// Refines an existing outline using a bitmap representation of the set of strokes that describe
    /// regions to be included and excluded.
    /// </summary>
    /// <remarks>
    /// The existing outline and the new outline have the same tree structure.
    /// </remarks>
    /// <param name="moment">Moment that contains the existing outline</param>
    /// <param name="outline">Existing outline from which to start the refinement</param>
    /// <param name="strokeBmp">Bitmap with a set of strokes that represents regions to include in or exclude from the outline</param>
    /// <returns>A new IPcOutline instance, which contains the refined outline</returns>
    virtual PcPtr<IPcOutline> RefineOutline(const PcPtr<IPcMoment>& moment, const PcPtr<IPcOutline>& outline, const PcPtr<PcImage>& strokeBmp) throw (PcException) = 0;

    /// <summary>
    /// Refines an existing picture using a refined outline.
    /// </summary>
    /// <param name="moment">Moment that contains the existing picture</param>
    /// <param name="picture">Existing picture from which to start the refinement</param>
    /// <param name="outline">Previously refined outline</param>
    /// <returns>A new IPcPicture instance, which contains the refined picture</returns>
    virtual PcPtr<IPcPicture> RefinePicture(const PcPtr<IPcMoment>& moment, const PcPtr<IPcPicture>& picture, const PcPtr<IPcOutline>& outline) throw (PcException) = 0;

    /// <summary>
    /// Classifies the contents of a moment.
    /// </summary>
    /// <remarks>
    /// A moment can contain images, or texts, or images and texts. A person is able to look at the
    /// objects on the mat and classify them. The Classify method does the same thing with
    /// the contents of a captured moment. Classify studies the moment and classifies
    /// its contents using tags, for example, as Flat and Rectangular. The classification tags
    /// are defined in the interface IPcClassificationSpecification, which is available through
    /// the interface IPcSpecification. The result of the classification has the same tree
    /// structure as the contents of the moment.
    /// </remarks>
    /// <param name="moment">Moment that contains the contents to be classified</param>
    /// <returns>An instance of IPcClassification, which classifies the contents of the moment</returns>
    virtual PcPtr<IPcClassification> Classify(const PcPtr<IPcMoment>& moment) throw (PcException) = 0;

    /// <summary>
    /// Creates an object-tracking handler, which allows an app to recognize and
    /// track 2D objects that are placed on or held above the touch mat, based on prior training
    /// using images of the objects.
    /// </summary>
    /// <remarks>
    /// This method takes an enumeration of instances of PcTrainingImage, which allows the user
    /// to track a set of objects, each of which has a name.
    /// </remarks>
    /// <param name="images">A collection of training images of objects to be tracked, with each image associated with the name of the object</param>
    /// <returns>An instance of IPcObjectTrackingHandler, the object-tracking handler</returns>
    virtual PcPtr<IPcObjectTrackingHandler> CreateObjectTrackingHandler(const PcCollection<PcTrainingImage>& images) throw (PcException) = 0;

    /// <summary>
    /// Creates a communication handler, which allows an app to send messages to and receive messages from other
    /// apps that use the Sprout Platform.
    /// </summary>
    /// <remarks>
    /// Receiving messages also entails using message observers, which use the interface
    /// IPcCommunicationObserver.
    /// </remarks>
    /// <param name="identifier">Identifier for the communication handler</param>
    /// <param name="name">Friendly name of the communication handler</param>
    /// <returns>An instance of IPcCommunicationHandler, the communication handler</returns>
    virtual PcPtr<IPcCommunicationHandler> CreateCommunicationHandler(
        const PcString& identifier, const PcString& name = PcString()) throw (PcException) = 0;

    /// <summary>
    /// Creates a capture-progress monitor, which allows an app to receive the event Flash
    /// when the flash occurs while capturing a moment.
    /// </summary>
    /// <remarks>
    /// Capturing a moment can take some time, and it can take different amounts of time
    /// depending on the prior states of the cameras. This method permits a Sprout app to
    /// synchronize user-interface feedback to the user (for example, a shutter sound)
    /// with the flash.
    /// </remarks>
    /// <returns>An instance of IPcCaptureProgressMonitor, the capture-progress monitor</returns>
    virtual PcPtr<IPcCaptureProgressMonitor> CreateCaptureProgressMonitor() throw (PcException) = 0;

    /// <summary>
    /// Creates a touch controller, which allows configuration of and interaction with virtual touch-input layers.
    /// </summary>
    /// <remarks>
    /// Virtual touch-input layers are a stack of virtual layers above the touch mat. They allow the Sprout Platform to designate
    /// specific areas of the touch mat for specific purposes, for example, as an area for a keyboard, and to handle
    /// user touches on those areas accordingly. In this way, the Sprout Platform is able to bypass the operating-system handling of
    /// touches. User touches that are not intercepted and handled by a touch layer are sent to the operating system.
    /// </remarks>
    /// <param name="window">Window handler for the window that will use the touch controller</param>
    /// <returns>An instance of IPcTouch, the touch controller</returns>
    virtual PcPtr<IPcTouch> AccessTouch(const PcPtr<IPcWindowRegistration>& window) throw (PcException) = 0;

    /// <summary>
    /// Accesses specification information that includes the versions of the Sprout Platform and binding;
    /// the cameras and screens on the system; Sprout Platform options for pictures, outlines, and text;
    /// and classification tags that classify the contents of a moment.
    /// </summary>
    /// <returns>An instance of IPcSpecification, which contains the specification information</returns>
    virtual PcPtr<IPcSpecification> AccessSpecification() throw (PcException) = 0;

    /// <summary>
    /// Registers a window that will be displayed on the mat screen.
    /// </summary>
    /// <remarks>
    /// RegisterWindow registers the window with the Sprout Platform. This allows the window to appear
    /// on the mat screen and to use touch features provided by the Sprout Platform.
    /// The window can only be registered after it has been created using Windows APIs.
    /// </remarks>
    /// <param name="windowId">Window ID representing the window handle to register with the Sprout Platform</param>
    /// <returns>An instance of IPcWindowRegistration, a window handler for the registered window</returns>
    virtual PcPtr<IPcWindowRegistration> RegisterWindow(long long windowId) throw (PcException) = 0;
};

} }

#endif // IPC_LINK_H
