#pragma once

#include <fstream>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QTextStream>

#include "LinkedList.h"
#include "exceptions.h"

/**
 * ClassModel, which is responsible for the creating, adding and removing of classes. Maintains internal information
 * about the current selected class and the current file path of the class file.
 */
class ClassModel
{
private:
    QString currentFilePath;
    LinkedList<QString> classes;
    QString selectedClass;
    void save();
    void writeLineToFile(const QString& filename, const QString& line);
    void writeLinesToFile(const QString& filename, LinkedList<QString>&);
public:
    void browse();
    void browse(const QString&);
    void create();
    void create(const QString&);
    void addClass(QString);
    void removeClass(const QString&);
    void select(const QString&);
    void clear();
    QString getSelected();
    LinkedList<QString> getAll();
    QString getCurrentFilePath();
};
