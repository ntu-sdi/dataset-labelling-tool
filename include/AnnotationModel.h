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
    LinkedList<std::string> supportedFileFormats;
    std::string currentFilePath;
    QFileSystemModel fileSystemModel();
    void save();

public:
    void browse();
    void create(const std::string&);
    void add(const QString&, const int, const LinkedList<Shape>&);
};
