#include<fstream>
#include <string>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <fstream>

#include "AnnotationModel.h"

void AnnotationModel::browse() {}

/**
 * @brief Prompts the user for a annotation file name. Creates a file using this name and path.
 */
void AnnotationModel::create()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Create New Annotation File",
                                                    "./",
                                                    "Annotation files (*.annotation)");
    fileName = fileName.trimmed();
    if (!fileName.contains(".annotation")) fileName.append(".annotation");
    QFile file(fileName);
    if(!file.open( QIODevice::ReadWrite)) std::invalid_argument("Could not create file");
    this->currentFilePath = fileName;

}

void AnnotationModel::create(const QString& fileName){

    QFile file(fileName);
    if(!file.open( QIODevice::ReadWrite)) std::invalid_argument("Could not create file");
    this->currentFilePath = fileName;
}

void AnnotationModel::add(const QString&, const int, const LinkedList<Shape>&) {}

/**
 * @brief Returns path of currently active annotation file
 * @return Path to a annotation file
 */
QString AnnotationModel::getCurrentFilePath(){
    return this->currentFilePath;
}


