#ifndef PC_TRACKED_OBJECT_H
#define PC_TRACKED_OBJECT_H

#include "PcPhysicalQuadrilateral.hpp"
#include "PcString.hpp"

namespace hp { namespace pc {

/// <summary>
/// The class PcTrackedObject encapsulates information about an object that
/// has been recognized and is being tracked by the object-tracking handler.
/// </summary>
class HPPC_API PcTrackedObject
{
public:
    /// <summary>
    /// Creates an instance of PcTrackedObject using the default constructor.
    /// </summary>
    PcTrackedObject();

    /// <summary>
    /// Destroys the instance of PcTrackedObject.
    /// </summary>
    virtual ~PcTrackedObject() {}

    /// <summary>
    /// Creates an instance of PcTrackedObject using the provided information.
    /// </summary>
    /// <param name="name">The name of the object that was recognized</param>
    /// <param name="quad">A quadrilateral that surrounds the recognized object</param>
    /// <param name="rotation">Rotation angle (in radians) of the bounding rectangle that contains the quadrilateral</param>
    PcTrackedObject(const PcString& name, const PcPhysicalQuadrilateral& quad, double rotation);

    /// <summary>
    /// Gets the name of the object that was recognized.
    /// </summary>
    /// <returns>The name of the object that was recognized</returns>
    const PcString& Name() const throw ();

    /// <summary>
    /// Gets the bounding retangle that encloses the quadrilateral that surrounds the object that is being tracked.
    /// </summary>
    /// <returns>The bounding rectangle of the quadrilateral</returns>
    const PcPhysicalRectangle& PhysicalBoundaries() const throw ();

    /// <summary>
    /// Gets the quadrilateral that surrounds the object that is being tracked.
    /// </summary>
    /// <remarks>
    /// The quadrilateral represents the distortion of the image of the object that is needed to match
    /// the current orientation of the object.
    /// </remarks>
    /// <returns>The quadrilateral that surrounds the object</returns>
    const PcPhysicalQuadrilateral& PhysicalQuadrilateral() const throw ();

    /// <summary>
    /// Gets the rotation angle (in radians) of the bounding rectangle that contains the quadrilateral
    /// that surrounds the object that was recognized.
    /// </summary>
    /// <returns>The rotation angle of the bounding rectangle</returns>
    double Rotation() const throw ();

private:

    PcString mName;
    PcPhysicalQuadrilateral mQuadrilateral;
    double mRotation;

};

} }


#endif // PC_TRACKED_OBJECT_H
