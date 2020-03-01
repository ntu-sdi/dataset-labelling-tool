#pragma once

#include <string>
#include <utility>
#include <QFileSystemModel>

#include "LinkedList.h"

using Point = std::pair<int, int>;
using Shape = LinkedList<Point>;

/**
 * Model, which is responsible for accessing annotation data.
 */
class AnnotationModel
{
private:
    std::string currentFilePath;
    void save();
public:
    void browse();
    void create(const std::string&);
    void add(const QString&, const int, const LinkedList<Shape>&);
};
