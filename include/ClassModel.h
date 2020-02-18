#pragma once

#include <string>
#include <QFileSystemModel>
#include <QFileDialog>
#include <iostream>
#include <fstream>

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
    void create();
    void addClass(const std::string&);
    void removeClass(const std::string&);
    void select(const std::string&);
    std::string getSelected();
    LinkedList<std::string> getAll();
};
