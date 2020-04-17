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
    LinkedList<QString> classes;
    //QStringList classes;
    void save();
    void writeLineToFile(const QString& filename, const QString& line);
    void writeLinesToFile(const QString& filename, LinkedList<QString>& lines);
public:
    void browse();
    void browse(const QString&);
    void create();
    void create(const QString&);
    void addClass(QString);
    void removeClass(const QString&);
    void select(const std::string&);
    void clear();
    std::string getSelected();
    LinkedList<QString> getAll();
    QString getCurrentFilePath();
};
