#include "AnnotationController.h"
#include "ClassController.h"
#include "ImageController.h"
#include "MainView.h"
#include "MainController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    AnnotationController annotationController;
    ClassController classController;
    ImageController imageController;
    MainController mainController(annotationController, classController, imageController);
    MainView mainView(mainController);
    mainView.show();
    return application.exec();
}
