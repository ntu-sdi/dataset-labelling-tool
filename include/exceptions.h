#ifndef DATASET_LABELING_TOOL_EXCEPTIONS_H
#define DATASET_LABELING_TOOL_EXCEPTIONS_H

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
        return "Error: Image file could not be found";
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

#endif //DATASET_LABELING_TOOL_EXCEPTIONS_H
