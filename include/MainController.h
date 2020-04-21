#pragma once

#include "AnnotationController.h"
#include "ClassController.h"
#include "ImageController.h"

/**
 * Processes callbacks from the GUI by delegating to the specific sub-controllers. Servers as
 * an added layer of separation between the views and controllers to decrease coupling and
 * handle business logic, which spans multiple controllers and models.
 */
class MainController
{
private:
    AnnotationController annotationController;
    ClassController classController;
    ImageController imageController;
    QString getSelectedClass();
public:
    MainController(AnnotationController&, ClassController&, ImageController&);
    void browseImages();
    void searchLoadedImages(const QString&);
    void sortLoadedImages(const QString&,bool = false);
    void selectImage(const QString&);
    void openImage(const QString&);
    void browseForClassFile();
    void sortLoadedClasses(const QString&);
    void createClassFile();
    void addClass(const QString&);
    void selectClass(const QString&);
    void removeClass(const QString&);
    void browseForAnnotationFile();
    void createAnnotationFile();
    void saveAnnotations();
    void addPoint(QPoint);
    void finishShape();
    void cancelShape();
};
