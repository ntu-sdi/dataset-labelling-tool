#include "MainController.h"

/**
 * @brief Constructs a MainController, taking in references to each type of sub-controller.
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
 * @brief Delegates the image folder browsing event to the ImageController.
 */
void MainController::browseImages()
{
    imageController.browseFolder();
}

void MainController::searchLoadedImages(const QString& ) {}

void MainController::sortLoadedImages() {}

void MainController::selectImage(const QString&) {}

/**
 * @brief Gets the image filename from the MainView and passes request to open image to MainController
 *
 * @param filename
 */
void MainController::openImage(const QString& fileName)
{
    imageController.open(fileName);
}

/**
 * @brief Delegates class folder browsing event to the ClassController.
 */
void MainController::browseForClassFile()
{
    this->classController.browse();
}

void MainController::sortLoadedClasses() {}

/**
 * @brief Delegates the creation of a class file to the ClassController.
 */
void MainController::createClassFile()
{
    this->classController.create();
}

/**
 * @brief Delegates the addition of a new class to the ClassController.
 *
 * @param classname Name of the class to add.
 */
void MainController::addClass(const QString& className)
{
    this->classController.add(className);
}

void MainController::selectClass(const std::string& ) {}

/**
 * @brief Delegates the removal of a class to the ClassController.
 *
 * @param classname Name of the class to remove.
 */
void MainController::removeClass(const QString& className)
{
    this->classController.remove(className);
}

void MainController::browseForAnnotationFile()
{
    this->annotationController.browse();
}

/**
 * @brief Delegates the creation of annotation file to the AnnotationController.
 */
void MainController::createAnnotationFile()
{
    annotationController.create();
}

void MainController::addPoint(QPoint point)
{
    this->imageController.addPoint(point);
}

void MainController::finishShape() {}

void MainController::cancelShape() {}
