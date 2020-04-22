#pragma once

#include <exception>
#include <stdexcept>

/**
 * Custom exception subclass, which signifies a value not found in an array.
 */
class ValueNotFoundError : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: Value not found in array";
    }
};

/**
 * Custom exception subclass, which signifies an array index out of bounds.
 */
class IndexOutOfBoundsError : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: Array index is out of bounds";
    }
};

/**
 * Custom exception subclass, which signifies an empty array.
 */
class ArrayEmptyError : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: Array is empty";
    }
};

/**
 * Custom exception subclass, which signifies a missing file.
 */
class FileNotFoundError : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error:  File could not be found";
    }
};

/**
 * Custom exception subclass, which signifies a missing class.
 */
class ClassNotFoundError : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: This class does not exist in currently loaded class file";
    }
};

/**
 * Custom exception subclass, which signifies that no class is selected.
 */
class ClassNotSelectedError : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: There is no selected class";
    }
};

/**
 * Custom exception subclass, which signifies a missing folder.
 */
class FolderNotFoundError : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: Folder could not be found";
    }
};

/**
 * Custom exception subclass, which signifies a cancelled operation.
 */
class OperationCanceled : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: Operation has been cancelled.";
    }
};

/**
 * Custom exception subclass, which signifies an image, which hasn't been annotated yet.
 */
class ImageNotAnnotatedYet : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: Image is not annotated in this file yet";
    }
};

/**
 * Custom exception subclass, which signifies a lack of vertices for a polygon.
 */
class DrawingIncomplete : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: Drawing cannot be completed, too few points";
    }
};
