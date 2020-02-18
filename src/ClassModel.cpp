#include "ClassModel.h"

QFileSystemModel ClassModel::fileSystemModel() {}

void ClassModel::save() {}

void ClassModel::browse() {}

void ClassModel::create()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "New Annotation",
                                                        "./data/",
                                                        "Annotaion files (*.annotation)");
    std::ofstream file(fileName.toStdString());
    file.close();

}

void ClassModel::addClass(const std::string&) {}

void ClassModel::removeClass(const std::string&) {}

void ClassModel::select(const std::string&) {}

std::string ClassModel::getSelected() {}

LinkedList<std::string> ClassModel::getAll() {}
