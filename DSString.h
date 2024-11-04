/*
 * This file should help you to create a minimal interface for your string class based on
 * a dynamically allocated char array. Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions
 * from <string.h> or <cstring> other than for conversion from a c-string.
 */

#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>

class DSString
{

private:
 //a pointer that points to a character array with a '\0' terminator
    char *data;
 //length of the string
    size_t len;
    // Note: we keep the terminator only so we can return a c-string version in function c_str().

public:
    /**
     * Make sure you implement the rule-of-three and use proper memory management.
     * To help you get started, you can implement the following:
     **/

    DSString();
 //constructor that takes an inputted char and declares our own string
    DSString(const char *);

    // Rule of three: copy constructor, copy assignment, and destructor (to delete the allocated memory)
 //shallow copy is default while deep copy copies entire
    DSString(const DSString &);         //constructor
    DSString &operator=(const DSString &);  //copy assignment
    ~DSString();      //destructor

    //returns length of the string
    size_t length() const;

    //returns a reference to character at index
    char &operator[](size_t);

    /**
     * Overloaded operator+ which appends the string in the argument to this string
     */
   //combining the two strings, one being from the argument
    DSString operator+(const DSString &) const;

    /**
     * Standard relational operators to compare and order your strings.
     * Feel free to add more.
     **/
 //
    bool operator==(const DSString &) const; //*making the two strings equal and passing the equaled value
    bool operator<(const DSString &) const; //*alphabetical organized

    /**
     * The substring method returns a new string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(size_t start, size_t numChars) const;
 //*first parameter, the start index of the string you wanna remove from main string (substring)
 //*and second is the length of the substring returned

    /**
     * @brief Returns a new string object with all characters in lowercase
     *
     * @return DSString
     */
    DSString toLower() const; // look at the ASCII table for this!
  //*lowercase

    /**
     * the c_str function returns a pointer a null-terminated c-string holding the
     * contents of this object. Since data already has a `\0`
     * at the end of the string in DSString so you can just return a pointer to data.
     **/
    const char *c_str() const; //*returning data ex. string is a array of char AKA c-string

    // a conversion to std::string would also be nice to have: string string() const;

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument. Remember:
     * This operator needs to be implemented outside of the class (and outside the class
     * namespace) as a friend because it operates on the stream and not the DSString object.
     **/
 //*friends passes through the ostream and string and lets us use the cout operator now
    friend std::ostream &operator<<(std::ostream &, const DSString &);  //*cout a string or outputting to a file

    // You are free to add more functionality to the class.  For example,
    // you may want to add a find(...) function that will search for a
    // substring within a string or a function that breaks a string into words.
    // You will need a split or tokenize function.
};

#endif
