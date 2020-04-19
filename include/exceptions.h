#pragma once

#include <exception>
#include <stdexcept>

class ValueNotFoundError : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: Value not found in array";
    }
};

class IndexOutOfBoundsError : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: Array index is out of bounds";
    }
};

class ArrayEmptyError : public std::exception
{
    const char * what () const throw ()
    {
        return "Error: Array is empty";
    }
};


class FileNotFoundError : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error:  File could not be found";
    }
};

class ClassNotFoundError : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: This class does not exist in currently loaded class file";
    }
};

class ClassNotSelectedError : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: There is no selected class";
    }
};

class FolderNotFoundError : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: Folder could not be found";
    }
};

class OperationCanceled : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: Folder could not be found";
    }
};

class ImageNotAnnotatedYet : public std::exception
{
public:
    const char * what () const throw ()
    {
        return "Error: Image is not annotated in this file yet";
    }
};
