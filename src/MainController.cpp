#include "MainController.h"

/**
 * Constructs a MainController, taking in references to each type of sub-controller.
 *
 * @param annotationController
 * @param classController
 * @param imageController
 */
MainController::MainController(AnnotationController& annotationController,
                               ClassController& classController,
                               ImageController& imageController) :
                               annotationController(annotationController),
                               classController(classController),
                               imageController(imageController)
{
    this->annotationController = annotationController;
    this->classController = classController;
    this->imageController = imageController;
}

/**
 * Delegates the image folder browsing event to the ImageController.
 */
void MainController::browseImages()
{
    imageController.browseFolder();
}

void MainController::searchLoadedImages(const std::string& ) {}

void MainController::sortLoadedImages() {}

void MainController::selectImage(const QString&) {}

void MainController::openImage(const QString& filename) {
    imageController.open(filename);
}

void MainController::browseForClassFile() {}

void MainController::sortLoadedClasses() {}

void MainController::createClassFile(const std::string& ) {}

void MainController::addClass(const std::string& ) {}

void MainController::selectClass(const std::string& ) {}

void MainController::removeClass(const std::string& ) {}

void MainController::browseForAnnotationFile() {}

void MainController::createAnnotationFile(const std::string& ) {}

void MainController::addPoint(Point) {}

void MainController::finishShape() {}

void MainController::cancelShape() {}
