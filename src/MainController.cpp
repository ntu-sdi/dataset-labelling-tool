#include "MainController.h"

MainController::MainController()
{
}

void  MainController::passViewToController(Ui::MainView * ui){
    userInterfaceView = ui;
}

void MainController::loadImagesFromFolder(){
    userInterfaceView->ImageList->addItem("I tried my best bro :(");
}
