#include "AnnotationModel.h"
#include<fstream>

QFileSystemModel AnnotationModel::fileSystemModel() {}

void AnnotationModel::save() {}

void AnnotationModel::browse() {}

void AnnotationModel::create(const std::string& fileName) {
   std::ofstream File(fileName + ".annotations");
}

void AnnotationModel::add(const QString&, const int, const LinkedList<Shape>&) {}


