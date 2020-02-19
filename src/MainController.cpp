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

void MainController::browseForClassFile()
{
    this->classController.browse();
}

void MainController::sortLoadedClasses() {}

void MainController::createClassFile()
{
    this->classController.create();
}

void MainController::addClass(const std::string& classname)
{
    this->classController.add(classname);
}

void MainController::selectClass(const std::string& ) {}

void MainController::removeClass(const std::string& ) {}

void MainController::browseForAnnotationFile() {}

void MainController::createAnnotationFile(const std::string& ) {}

void MainController::addPoint(Point) {}

void MainController::finishShape() {}

void MainController::cancelShape() {}
