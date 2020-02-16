#pragma once

#include "AnnotationController.h"
#include "ClassController.h"
#include "ImageController.h"

/*
 * TODO: seeing as the controllers just update the view, do controller
 * methods even need return types? The class diagram does not specify,
 * so for now all controller methods have return types but this may be changed
 * to void later.
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
    LinkedList<std::string> searchLoadedImages(const std::string&);
    LinkedList<std::string> sortLoadedImages();
    std::string selectImage(const std::string&);
    void openImage();

    void browseForClassFile();
    LinkedList<std::string> sortLoadedClasses();
    void createClassFile(const std::string&);
    void addClass(const std::string&);
    void selectClass(const std::string&);
    void removeClass(const std::string&);

    void browseForAnnotationFile();
    void createAnnotationFile(const std::string&);
    void addPoint(Point);
    void finishShape();
    void cancelShape();
};
