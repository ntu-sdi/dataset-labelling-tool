#pragma once

#include <string>
#include <utility>
#include <QFileSystemModel>

#include "LinkedList.h"

using Point = std::pair<int, int>;
using Shape = LinkedList<Point>;

class AnnotationModel
{
private:
    QFileSystemModel fileSystemModel();
    LinkedList<std::string> supportedFileFormats;
    std::string currentFilePath;

    void save();

public:
    void browse();
    void create(const std::string&);
    void add(const std::string&, const int, const LinkedList<Shape>&);
};
