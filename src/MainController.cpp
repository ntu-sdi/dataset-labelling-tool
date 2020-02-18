#include "MainController.h"

MainController::MainController(AnnotationController& a,
                               ClassController& c,
                               ImageController& i)
{
    this -> annotationController = a;
    this -> classController = c;
    this -> imageController = i;
}

void MainController::browseImages() {}

void MainController::searchLoadedImages(const std::string& ) {}

void MainController::sortLoadedImages() {}

void MainController::selectImage(const std::string& ) {}

void MainController::openImage() {}

void MainController::browseForClassFile() {}

void MainController::sortLoadedClasses() {}

void MainController::createClassFile()
{
    this->classController.create();
}

void MainController::addClass(const std::string& ) {}

void MainController::selectClass(const std::string& ) {}

void MainController::removeClass(const std::string& ) {}

void MainController::browseForAnnotationFile() {}

void MainController::createAnnotationFile(const std::string& ) {}

void MainController::addPoint(Point) {}

void MainController::finishShape() {}

void MainController::cancelShape() {}
