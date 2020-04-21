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

void MainController::selectImage(const QString& a) {
    imageController.select(a);
}

/**
 * @brief Gets the image filename from the MainView and passes request to open image to MainController
 *
 * @param filename
 */
void MainController::openImage(const QString& fileName)
{
    if (this->imageController.getCurrentFileName() != fileName &&
        this->imageController.getCurrentFileName() != nullptr) {
        this->cancelShape();
    }
    try {
        this->imageController.setAnnotations(this->annotationController.get(fileName));
    }  catch (ImageNotAnnotatedYet) {
        this->imageController.setAnnotations(
                    LinkedList<QPair<QString, LinkedList<QPair<int, int>>>>());
    }
    catch (IndexOutOfBoundsError) {
        std::cout << "setannotations is fucked" << std::endl;
    }

    this->imageController.open(fileName);
}

/**
 * @brief Delegates class folder browsing event to the ClassController.
 */
void MainController::browseForClassFile()
{
    this->classController.browse();
}

void MainController::sortLoadedClasses(const QString& sortOption) {
    this->classController.updateView(sortOption);
}

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

void MainController::selectClass(const QString& className) {
    this->classController.select(className);
}

QString MainController::getSelectedClass()
{
    return this->classController.getSelected();
}

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
    try {
        this->openImage(this->imageController.getCurrentFileName());
    }  catch (std::exception) {}
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

void MainController::finishShape()
{
    try {
        QString className = this->getSelectedClass();
        QVector<QPointF> points = this->imageController.finishShape(className);
        LinkedList<QPair<int, int>> p;
        for (QPointF i: points) {
            p.push(QPair<int, int>(static_cast<int>(i.x()),
                                   static_cast<int>(i.y())));
        }
        this->annotationController.add(this->imageController.getCurrentFileName(),
                                       className, p);
    }  catch (DrawingIncomplete& e) {
        QMessageBox::warning(nullptr, "Error", e.what(), QMessageBox::Ok);
        this->cancelShape();
    } catch (ClassNotSelectedError& e) {
        QMessageBox::warning(nullptr, "Error", e.what(), QMessageBox::Ok);
        this->cancelShape();
    }
    catch (FileNotFoundError& e) {
        QMessageBox::warning(nullptr, "Error", e.what(), QMessageBox::Ok);
        this->cancelShape();
    }

    this->openImage(this->imageController.getCurrentFileName());
}

void MainController::cancelShape()
{
    this->imageController.cancelShape();
}
