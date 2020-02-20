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

void MainController::searchLoadedImages(const QString& ) {}

void MainController::sortLoadedImages() {}

void MainController::selectImage(const QString&) {}

void MainController::openImage(const QString& filename) {
    imageController.open(filename);
}

void MainController::browseForClassFile() {}

void MainController::sortLoadedClasses() {}

void MainController::createClassFile(const QString& ) {}

void MainController::addClass(const QString& ) {}

void MainController::selectClass(const QString& ) {}

void MainController::removeClass(const QString& ) {}

void MainController::browseForAnnotationFile() {}

void MainController::createAnnotationFile(const QString& ) {}

void MainController::addPoint(Point) {}

void MainController::finishShape() {}

void MainController::cancelShape() {}
