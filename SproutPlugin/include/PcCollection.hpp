#ifndef PC_COLLECTION_H
#define PC_COLLECTION_H

#include "HpPcApi.hpp"
#include "PcPtr.hpp"

namespace hp { namespace pc {

/// <summary>
/// A collection of supported SDK types
/// </summary>
template <class T>
class HPPC_API PcCollection
{
public:
    /// <summary>
    /// The type of the elements.
    /// </summary>
    typedef T value_type;

    /// <summary>
    /// Default constructor.
    /// </summary>
    /// <remarks>
    /// Constructs an empty collection.
    /// </remarks>
    PcCollection();

    /// <summary>
    /// Copy constructor.
    /// </summary>
    /// <remarks>
    /// Constructs the collection with the copy of the contents of other.
    /// </remarks>
    PcCollection(const PcCollection& other);

    /// <summary>
    /// Move constructor.
    /// </summary>
    /// <remarks>
    /// Constructs the collection with the contents of other using move semantics.
    /// </remarks>
    PcCollection(PcCollection&& other);

    /// <summary>
    /// Constructs the collection with the copy of contents of the range [first, last).
    /// </summary>
    PcCollection(const T* first, const T* last);

    /// <summary>
    /// Copy assignment operator.
    /// </summary>
    /// <remarks>
    /// Replaces the contents with a copy of the contents of other.
    /// </remarks>
    PcCollection& operator = (const PcCollection& other);
    
    /// <summary>
    /// Move assignment operator.
    /// </summary>
    /// <remarks>
    /// Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this collection).
    /// Other is in a valid but unspecified state afterwards.
    /// </remarks>
    PcCollection& operator = (PcCollection&& other);

/// Element access --------------------------------------------------------------------------------

    /// <summary>
    /// Returns a reference to the element at specified location pos.
    /// </summar>
    /// <param name="pos>Position of the element to return</param>
    /// <returns>Reference to the requested element</returns>
    T & at(unsigned int pos);

    /// <summary>
    /// Returns a reference to the element at specified location pos.
    /// </summar>
    /// <param name="pos>Position of the element to return</param>
    /// <returns>Constant reference to the requested element</returns>
    const T & at(unsigned int pos) const;

    /// <summary>
    /// Returns a reference to the element at specified location pos.
    /// </summar>
    /// <param name="pos>Position of the element to return</param>
    /// <returns>Reference to the requested element</returns>
    T & operator[] (unsigned int pos);

    /// <summary>
    /// Returns a reference to the element at specified location pos.
    /// </summar>
    /// <param name="pos>Position of the element to return</param>
    /// <returns>Constant reference to the requested element</returns>
    const T & operator[] (unsigned int pos) const;

    /// <summary>
    /// Returns a reference to the first element in the collection.
    /// </summar>
    /// <remarks>
    /// Calling front on an empty collection is undefined.
    /// </remarks>
    /// <returns>Reference to the first element</returns>
    T & front();

    /// <summary>
    /// Returns a reference to the first element in the collection.
    /// </summar>
    /// <remarks>
    /// Calling front on an empty collection is undefined.
    /// </remarks>
    /// <returns>Constant reference to the first element</returns>
    const T & front() const;

    /// <summary>
    /// Returns a reference to the last element in the collection.
    /// </summar>
    /// <remarks>
    /// Calling back on an empty collection is undefined.
    /// </remarks>
    /// <returns>Reference to the last element</returns>
    T & back();

    /// <summary>
    /// Returns a reference to the last element in the collection.
    /// </summar>
    /// <remarks>
    /// Calling back on an empty collection is undefined.
    /// </remarks>
    /// <returns>Constant reference to the last element</returns>
    const T & back() const;

    /// <summary>
    /// Returns pointer to the underlying array serving as element storage.
    /// </summar>
    /// <returns>Pointer to the underlying element storage</returns>
    T* data();

    /// <summary>
    /// Returns pointer to the underlying array serving as element storage.
    /// </summar>
    /// <returns>Constant pointer to the underlying element storage</returns>
    const T* data() const;

/// Iterators -------------------------------------------------------------------------------------

    /// <summary>
    /// Returns an iterator pointing to the first element of the collection.
    /// </summary>
    /// <returns>Pointer to the first element</returns>
    const T* begin() const;

    /// <summary>
    /// Returns an iterator pointing to the past-the-end element of the collection.
    /// </summary>
    /// <returns>Pointer to the character following the last element</returns>
    const T* end() const;

/// Capacity --------------------------------------------------------------------------------------

    /// <summary>
    /// Checks if the collection has no elements, i.e. whether begin() == end().
    /// </summary>
    /// <returns>True if the collection is empty, false otherwise</returns>
    bool empty() const;

    /// <summary>
    /// Returns the number of elements in the collection.
    /// </summary>
    /// <returns>The number of elements in the collection</returns>
    unsigned int size() const;

    /// <summary>
    /// Increase the capacity of the collection to a value that's greater or equal to new_cap.
    /// </summary>
    /// <param name="new_cap">new capacity of the collection</param>
    void reserve(unsigned int new_cap);

/// Modifiers -------------------------------------------------------------------------------------

    /// <summary>
    /// Removes all elements from the collection.
    /// </summary>
    void clear();

    /// <summary>
    /// Appends a copy of the given element value to the end of the collection.
    /// </summary>
    /// <param name="value">The value of the element to append</param>
    void push_back(const T& value);

    /// <summary>
    /// Resizes the collection to contain count elements.
    /// Additional elements are default-inserted.
    /// </summary>
    /// <param name="count">New size of the collection</param>
    void resize(unsigned int count);

private:

    class Impl;
    PcPtr<Impl> pimpl;
};

} }

#endif // PC_COLLECTION_H
