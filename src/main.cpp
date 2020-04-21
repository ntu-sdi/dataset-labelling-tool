#include <QApplication>

#include "AnnotationController.h"
#include "ClassController.h"
#include "ImageController.h"
#include "MainView.h"
#include "MainController.h"
#include "../include/ui_MainView.h"

void annotationSaver(MainController *controller){
    while(1){
        controller->saveAnnotations();
        std::this_thread::sleep_for(std::chrono::milliseconds(60000));
    }
}

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainView mainView;
    Ui_MainView ui_MainView = mainView.getUi();
    ImageModel imageModel;
    ClassModel classModel;
    AnnotationModel annotationModel;
    AnnotationController annotationController(ui_MainView, annotationModel);
    ClassController classController(ui_MainView, classModel);
    ImageController imageController(ui_MainView, imageModel);
    MainController mainController(annotationController, classController, imageController);
    std::thread saver(annotationSaver,&mainController);
    mainView.useController(&mainController);
    mainView.show();
    return application.exec();
}
