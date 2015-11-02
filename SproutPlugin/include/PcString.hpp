#ifndef PC_STRING_HPP
#define PC_STRING_HPP

#include "HpPcApi.hpp"
#include "PcPtr.hpp"

namespace hp { namespace pc {

/// <summary>
/// Represents a sequences of characters.
/// </summary>
class HPPC_API PcString
{
public:
    /// <summary>
    /// Serialization word size
    /// </summary>
    typedef unsigned short value_type;
    
    /// <summary>
    /// Alias for the PcString size definition
    /// </summary>
    typedef unsigned int size_type;
    
    /// <summary>
    /// Alias for the PcString character definition
    /// </summary>
    typedef wchar_t char_type;

    /// <summary>
    /// PcString max length definition
    /// </summary>
    static const unsigned int npos = (unsigned int)- 1;

    /// <summary>
    /// Default constructor.
    /// </summary>
    /// <remarks>
    /// Constructs an empty string.
    /// </remarks>
    PcString();

    /// <summary>
    /// Constructs a string from a given null terminated character array.
    /// </summary>
    /// <param name="s">Array of characters to be copied</param>
    PcString(char_type const* s);

    /// <summary>
    /// Constructs a string from the first count characters in the given character array.
    /// </summary>
    /// <param name="s">Array of characters to be copied</param>
    /// <param name="count">The number of characters to copy</param>
    PcString(char_type const* s, size_type count);

    /// <summary>
    /// Copy constructor.
    /// </summary>
    /// <remarks>
    /// Constructs the string with the copy of the contents of other.
    /// </remarks>
    /// <param name="other">Another string to use as source to initialize the string with.</param>
    PcString(const PcString& other);

    /// <summary>
    /// Move constructor.
    /// </summary>
    /// <remarks>
    /// Constructs the string with the contents of other using move semantics. other is left in valid, but unspecified state.
    /// </remarks>
    /// <param name="other">Another string to use as source to initialize the string with.</param>
    PcString(PcString&& other);

    /// <summary>
    /// Replaces the contents with a copy of str.
    /// </summary>
    /// <remarks>
    /// If *this and str are the same object, this function has no effect.
    /// </remarks>
    /// <param name="str">String to be used as source to initialize the string with</param>
    // <returns>Reference to *this</returns>
    PcString& operator = (const PcString& str);

    /// <summary>
    /// Replaces the contents with those of str using move semantics.
    /// </summary>
    /// <remarks>
    /// Leaves str in valid, but unspecified state. The behavior is undefined if *this and str are the same object.
    /// </remarks>
    /// <param name="str">String to be used as source to initialize the string with</param>
    // <returns>Reference to *this</returns>
    PcString& operator = (PcString&& str);

/// Element access --------------------------------------------------------------------------------

    /// <summary>
    /// Returns a reference to the character at position pos in the string.
    /// </summary>
    /// <param name = "pos">Position of a character within the string</param>
    /// <returns>Reference to the requested character</returns>
    char_type& at(size_type pos);

    /// <summary>
    /// Returns a reference to the character at position pos in the string.
    /// </summary>
    /// <param name = "pos">Position of a character within the string</param>
    /// <returns>Constant reference to the requested character</returns>
    const char_type& at(size_type pos) const;

    /// <summary>
    /// Returns a reference to the character at position pos in the string.
    /// </summary>
    /// <param name = "pos">Position of a character within the string</param>
    /// <returns>Reference to the requested character</returns>
    char_type& operator[] (size_type pos);

    /// <summary>
    /// Returns a reference to the character at position pos in the string.
    /// </summary>
    /// <param name = "pos">Position of a character within the string</param>
    /// <returns>Reference to the requested character</returns>
    const char_type& operator[] (size_type pos) const;

    /// <summary>
    /// Returns a pointer to an array that contains a null-terminated sequence of characters.
    /// </summary>
    /// <returns>Pointer to the underlying character storage.</returns>
    const char_type* c_str() const;

/// Iterators -------------------------------------------------------------------------------------

    /// <summary>
    /// Returns an iterator pointing to the first character of the string.
    /// </summary>
    /// <returns>Pointer to the first character</returns>
    const char_type* begin() const;

    /// <summary>
    /// Returns an iterator pointing to the past-the-end character of the string.
    /// </summary>
    /// <returns>Pointer to the character following the last character</returns>
    const char_type* end() const;

/// Capacity --------------------------------------------------------------------------------------

    /// <summary>
    /// Returns whether the string is empty (i.e. whether its length is 0).
    /// </summary>
    /// <returns>True if the string is empty, false otherwise</returns>
    bool empty() const;

    /// <summary>
    /// Returns the length of the string, in terms of number of characters.
    /// </summary>
    /// <returns>The number of characters in the string</returns>
    size_type size() const;

    /// <summary>
    /// Returns the length of the string, in terms of number of characters.
    /// </summary>
    /// <returns>The number of characters in the string</returns>
    size_type length() const;

    /// <summary>
    /// Returns the maximum length the string can reach.
    /// </summary>
    /// <returns>Maximum number of characters</returns>
    size_type max_size() const;

    /// <summary>
    /// Requests that the string capacity be adapted to a planned change in size to a length of up to new_cap characters.
    /// </summary>
    /// <param name = "new_cap">New capacity of the string.</param>
    void reserve(size_type new_cap);

    /// <summary>
    /// Returns the size of the storage space currently allocated for the string, expressed in terms of characters.
    /// </summary>
    /// <returns>Capacity of the currently allocated storage</returns>
    size_type capacity() const;

/// Operations ------------------------------------------------------------------------------------

    /// <summary>
    /// Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
    /// </summary>
    void clear();

    /// <summary>
    /// Inserts string str at the position index.
    /// </summary>
    /// <param name="index">Position at which the content will be inserted</param>
    /// <param name="str">String to insert</param>
    // <returns>Reference to *this</returns>
    PcString& insert(size_type index, const PcString& str);

    /// <summary>
    /// Inserts null-terminated character string pointed to by s at the position index.
    /// </summary>
    /// <param name="index">Position at which the content will be inserted</param>
    /// <param name="s">Pointer to the character string to insert</param>
    // <returns>Reference to *this</returns>
    PcString& insert(size_type index, const char_type* s);

    /// <summary>
    /// Removes min(count, size() - index) characters starting at index.
    /// </summary>
    /// <param name="index">First character to remove</param>
    /// <param name="count">Number of characters to remove</param>
    // <returns>Reference to *this</returns>
    PcString& erase(size_type index, size_type count = npos);

    /// <summary>
    /// Appends the given character ch to the end of the string, increasing its length by one.
    /// </summary>
    /// <param name="ch">The character to append</param>
    void push_back(char_type ch);

    /// <summary>
    /// Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
    /// </summary>
    /// <remarks>
    /// Returns a substring [pos, pos+count).
    /// If the requested substring extends past the end of the string, or if count == npos, the returned substring is[pos, size())
    /// </remarks>
    /// <param name = "pos">Position of the first character to be copied as a substring.</param>
    /// <param name = "count">Number of characters to include in the substring (if the string is shorter, as many characters as possible are used).</param>
    /// <returns>PcString containing the substring [pos, pos + count)</returns>
    PcString substr(size_type pos = 0, size_type count = npos) const;

    /// <summary>
    /// Resizes the string to contain count characters.
    /// </summary>
    /// <param name = "count">New string length, expressed in number of characters</param>
    void resize(size_type count);

    /// <summary>
    /// Resizes the string to a length of n characters.
    /// </summary>
    /// <param name = "count">New string length, expressed in number of characters</param>
    /// <param name = "ch">Character used to fill the new character space added to the string (in case the string is expanded)</param>
    void resize(size_type count, char_type ch);

/// Search ----------------------------------------------------------------------------------------

    /// <summary>
    /// Finds the first substring equal to the given character sequence.
    /// </summary>
    /// <remarks>
    /// Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
    /// </remarks>
    /// <param name = "s">Pointer to an array of characters.</param>
    /// <param name = "pos">Position at which to start the search</param>
    /// <returns>Position of the first character of the found substring or npos if no such substring is found</returns>
    size_type find(const char_type* s, size_type pos = 0) const;

    /// <summary>
    /// Finds the first substring equal to the given character sequence.
    /// </summary>
    /// <remarks>
    /// Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
    /// Only the first count characters of s are considered.
    /// </remarks>
    /// <param name = "s">Pointer to an array of characters.</param>
    /// <param name = "pos">Position at which to start the search</param>
    /// <param name = "count">Length of substring to search for</param>
    /// <returns>Position of the first character of the found substring or npos if no such substring is found</returns>
    size_type find(const char_type* s, size_type pos, size_type count) const;

    /// <summary>
    /// Finds the first character ch.
    /// </summary>
    /// <remarks>
    /// Search begins at pos, i.e. the found substring must not begin in a position preceding pos.
    /// </remarks>
    /// <param name = "ch">Individual character to be searched for</param>
    /// <param name = "pos">Position at which to start the search</param>
    /// <returns>Position of the first occurrence of the character or npos if not found</returns>
    size_type find(char_type ch, size_type pos = 0) const;

private:
    class Impl;
    PcPtr<Impl> pimpl;
};

} }

#endif // PC_STRING_HPP
