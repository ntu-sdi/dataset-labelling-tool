#include "MainController.h"

MainController::MainController(AnnotationController& a,
                               ClassController& c,
                               ImageController& i)
{
    this->annotationController = a;
    this->classController = c;
    this->imageController = i;
}
