#pragma once

#include <string>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <fstream>

#include "LinkedList.h"
#include "exceptions.h"

/**
 * ClassModel, which is responsible for the creating, adding and removing of classes. Maintains internal information
 * about the current selected class and the current file path of the class file.
 */
class ClassModel
{
private:
    std::string selectedClass;
    QString currentFilePath;
    QStringList classes;
    void save();
    void writeLineToFile(const QString& filename, const QString& line);
    void writeLinesToFile(const QString& filename, const QStringList& lines);
public:
    void browse();
    void browse(const QString&);
    void create();
    void create(const QString&);
    void addClass(QString);
    void removeClass(const QString&);
    void select(const std::string&);
    std::string getSelected();
    QStringList getAll();
    QString getCurrentFilePath();
};
