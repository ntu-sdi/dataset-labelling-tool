#include<fstream>

#include "AnnotationModel.h"

void AnnotationModel::save() {}

void AnnotationModel::browse() {}

/**
 * @brief Create a new annotation file.
 *
 * @param fileName
 */
void AnnotationModel::create(const std::string& fileName)
{
   std::ofstream File(fileName + ".annotations");
}

void AnnotationModel::add(const QString&, const int, const LinkedList<Shape>&) {}


