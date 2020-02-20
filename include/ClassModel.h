#pragma once

#include <string>
#include <QFileSystemModel>

#include "LinkedList.h"

class ClassModel
{
private:
    LinkedList<std::string> supportedFileFormats;
    std::string selectedClass;
    std::string currentFilePath;
    QFileSystemModel fileSystemModel();
    void save();

public:
    void browse();
    void create(const QString&);
    void addClass(const QString&);
    void removeClass(const QString&);
    void select(const QString&);
    std::string getSelected();
    LinkedList<std::string> getAll();
};
