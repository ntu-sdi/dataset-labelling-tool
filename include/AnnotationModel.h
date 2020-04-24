#pragma once

#include <utility>
#include <QFileSystemModel>
#include <QJsonDocument>

#include "LinkedList.h"

using Point = QPair<int, int>;
using Shape = LinkedList<Point>;

/**
 * Model, which is responsible for accessing annotation data.
 */
class AnnotationModel
{
private:
    QString currentFilePath;
    QJsonDocument loadedAnnotations;
public:
    QString getCurrentFilePath();
    void browse();
    void browse(const QString&);
    void load();
    void save();
    void create();
    void create(const QString&);
    void add(const QString& jsonFilePath, const QString& imageFilePath, const QString& className, LinkedList<QPair<int,int>>& coordinates);
    void add(const QString& imageFilePath,const QString& className, LinkedList<QPair<int,int>>& coordinates);
    LinkedList<QPair<QString, Shape>> get(const QString&);
    QMap <QString,Shape> get(const QString&, const QString&);
};
