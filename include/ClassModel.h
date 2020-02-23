#pragma once

#include <string>
#include <QFileSystemModel>
#include <QFileDialog>
#include <iostream>
#include <fstream>

#include "LinkedList.h"

/**
 * ClassModel, which is responsible for the creating, adding and removing of classes. Maintains internal information
 * about the current selected class and the current file path of the class file.
 */
class ClassModel
{
private:
    LinkedList<std::string> supportedFileFormats;
    std::string selectedClass;
    std::string currentFilePath;
    QFileSystemModel fileSystemModel();
    void removeLine(const std::string&, const std::string&);
    void save();

public:
    void browse();
    void create();
    void addClass(const std::string&);
    void removeClass(const std::string&);
    void select(const std::string&);
    std::string getSelected();
    QStringList getAll();
};
