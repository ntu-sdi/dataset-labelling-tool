#pragma once

#include <string>
#include <QFileSystemModel>

#include <LinkedList.h>

class ClassModel
{
private:
    QFileSystemModel fileSystemModel();
    LinkedList<std::string> supportedFileFormats;
    std::string selectedClass;
    std::string currentFilePath;

    void save();

public:
    void browse();
    void create(const std::string&);
    void addClass(const std::string&);
    void removeClass(const std::string&);
    void select(const std::string&);
    std::string getSelected();
    LinkedList<std::string> getAll();
};
