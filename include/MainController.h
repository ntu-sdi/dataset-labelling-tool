#pragma once

#include "AnnotationController.h"
#include "ClassController.h"
#include "ImageController.h"

class MainController
{
private:
    AnnotationController annotationController;
    ClassController classController;
    ImageController imageController;

public:
    MainController(AnnotationController&, ClassController&, ImageController&);
};
