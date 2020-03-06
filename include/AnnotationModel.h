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
    QString currentFilePath;
public:
    void browse();
    void browse(const QString&);
    void create();
    void create(const QString&);
    void add(const QString& jsonFilePath, const QString& imageFilePath, const QString& className, LinkedList<std::pair<int,int>>& coordinates);
    void add(const QString& imageFilePath,const QString& className, LinkedList<std::pair<int,int>>& coordinates);
    QString getCurrentFilePath();
};
