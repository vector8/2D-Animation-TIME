#ifndef PC_PTR_H
#define PC_PTR_H

#include "HpPcApi.hpp"

namespace hp { namespace pc {

class PcPtrCast;

/// <summary>
/// PcPtr is a smart pointer that retains shared ownership of an object through a pointer.
/// </summary>
template <class T>
class HPPC_API PcPtr
{
public:

    /// <summary>
    /// Default constructor.
    /// </summary>
    /// <remarks>
    /// Constructs a PcPtr with no managed object, i.e. empty PcPtr.
    /// </remarks>
    PcPtr();

    /// <summary>
    /// Constructs a PcPtr with ptr as the pointer to the managed object.
    /// </summary>
    /// <param name="ptr">A pointer to an object to manage</param>
    explicit PcPtr(T* ptr);

    /// <summary>
    /// Copy constructor.
    /// </summary>
    /// <remarks>
    /// Constructs a PcPtr which shares ownership of the object managed by other.
    /// </remarks>
    /// <param name="other">Another smart pointer to share the ownership</param>
    PcPtr(const PcPtr& other);

    /// <summary>
    /// Copy constructor.
    /// </summary>
    /// <remarks>
    /// Overload used when U* is implicitly convertible to T*.
    /// </remarks>
    /// <param name="other">Another smart pointer to share the ownership</param>
    template <class U> PcPtr(const PcPtr<U>& other);

    /// <summary>
    /// Destroys the PcPtr instance.
    /// </summary>
    /// <remarks>
    /// If *this owns an object and it is the last PcPtr owning it, the object is destroyed. Otherwise does nothing.
    /// </remarks>
    ~PcPtr();

    /// <summary>
    /// Replaces the managed object with the one managed by r.
    /// </summary>
    /// <param name="r">Another smart pointer to share the ownership</param>
    /// <returns>Reference to *this</returns>
    PcPtr& operator = (const PcPtr& r);

    /// <summary>
    /// Dereferences pointer to the managed object.
    /// </summary>
    /// <returns>Pointer to the managed object</returns>
    T* operator -> () const;

    /// <summary>
    /// Returns a pointer to the managed object.
    /// </summary>
    /// <returns>Pointer to the managed object</returns>
    T* get() const;

    /// <summary>
    /// Checks if *this stores a non-null pointer, i.e. whether get() != nullptr.
    /// </summary>
    /// <returns>True if *this stores a pointer, false otherwise</returns>
    explicit operator bool() const;

    /// <summary>
    /// Remove onwership of manged pointer and return it.
    /// </summary>
    /// <returns>Pointer to the no longer managed object</returns>
    T* release();

private:

    class Impl;
    Impl* pimpl;

    friend class PcPtrCast;
};

} }

#endif // PC_PTR_H
