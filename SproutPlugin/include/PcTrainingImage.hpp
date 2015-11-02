#ifndef PC_TRAINING_IMAGE_H
#define PC_TRAINING_IMAGE_H

#include "PcImage.hpp"
#include "PcPtr.hpp"
#include "PcString.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcTrainingImage represents an association between an image of an object
/// and the name of the object in the image.
/// </summary>
/// <remarks>
/// A vector of instances of the class PcTrainingImage is used to train an object tracking
/// handler to recognize the the objects contained in the images, so that the objects can be
/// recognized in video frames and tracked.
/// </remarks>
class HPPC_API PcTrainingImage
{
public:
    /// <summary>
    /// Creates an instance of PcTrainingImage using the default constructor with an empty name and no image.
    /// </summary>
    PcTrainingImage();

    /// <summary>
    /// Destroys the instance of PcTrainingImage.
    /// </summary>
    virtual ~PcTrainingImage() {}

    /// <summary>
    /// Creates an instance of PcTrainingImage using the provided name and image of the object.
    /// </summary>
    /// <param name="name">An arbitrary name of the object in the image</param>
    /// <param name="image">The image that contains the object to recognize and track</param>
    PcTrainingImage(const PcString& name, const PcPtr<PcImage>& image) throw ();

    /// <summary>
    /// Gets the name of the object in the image.
    /// </summary>
    /// <returns>The name of the object in the image</returns>
    const PcString& Name() const throw ();

    /// <summary>
    /// Gets the image of the object to recognize and track.
    /// </summary>
    /// <returns>The image of the object</returns>
    const PcPtr<PcImage>& Image() const throw ();

private:
    PcString mName;
    PcPtr<PcImage> mImage;
};

} }


#endif // PC_TRAINING_IMAGE_H
