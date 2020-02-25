#include "MainController.h"

MainController::MainController(AnnotationController& a,
                               ClassController& c,
                               ImageController& i) : annotationController(a),
                                                     classController(c),
                                                     imageController(i)
{
    this -> annotationController = a;
    this -> classController = c;
    this -> imageController = i;
}

void MainController::browseImages()
{
    imageController.browseFolder();
}

void MainController::searchLoadedImages(const std::string& ) {}

void MainController::sortLoadedImages() {}

void MainController::selectImage(const std::string& ) {}

void MainController::openImage() {}

/**
 * Delegates class folder browsing event to the ClassController.
 */
void MainController::browseForClassFile()
{
    this->classController.browse();
}

void MainController::sortLoadedClasses() {}

/**
 * Delegates the creation of a class file to the ClassController.
 */
void MainController::createClassFile()
{
    this->classController.create();
}

/**
 * Delegates the addition of a new class to the ClassController.
 * @param classname Name of the class to add.
 */
void MainController::addClass(const QString& classname)
{
    this->classController.add(classname);
}

void MainController::selectClass(const std::string& ) {}

/**
 * Delegates the removal of a class to the ClassController.
 * @param classname Name of the class to remove.
 */
void MainController::removeClass(const QString& classname)
{
    this->classController.remove(classname);
}

void MainController::browseForAnnotationFile() {}

void MainController::createAnnotationFile(const QString& ) {}

void MainController::addPoint(Point) {}

void MainController::finishShape() {}

void MainController::cancelShape() {}
