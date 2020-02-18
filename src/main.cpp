#include <QApplication>

#include "AnnotationController.h"
#include "ClassController.h"
#include "ImageController.h"
#include "MainView.h"
#include "MainController.h"
#include "../include/ui_MainView.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    MainView mainView;
    Ui_MainView ui_MainView = mainView.returnReferenceOfUi();
    ImageModel imageModel;
    ClassModel classModel;
    AnnotationModel annotationModel;
    AnnotationController annotationController(ui_MainView, annotationModel);
    ClassController classController(ui_MainView, classModel);
    ImageController imageController(ui_MainView, imageModel);
    MainController mainController(annotationController, classController, imageController);
    mainView.useController(&mainController);


    mainView.show();
    return application.exec();
}
