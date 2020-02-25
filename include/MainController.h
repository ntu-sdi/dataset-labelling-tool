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
    std::string getSelectedClass();

public:
    MainController(AnnotationController&, ClassController&, ImageController&);
    void browseImages();
    void searchLoadedImages(const std::string&);
    void sortLoadedImages();
    void selectImage(const std::string&);
    void openImage();
    void browseForClassFile();
    void sortLoadedClasses();
    void createClassFile();
    void addClass(const QString&);
    void selectClass(const std::string&);
    void removeClass(const QString&);
    void browseForAnnotationFile();
    void createAnnotationFile(const QString&);
    void addPoint(Point);
    void finishShape();
    void cancelShape();
};
