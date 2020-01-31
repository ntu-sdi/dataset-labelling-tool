#include "maincontroller.h"
#include "ui_gui.h"

MainController::MainController()
{
}

void  MainController::passViewToController(Ui::gui * ui){
    userInterfaceView = ui;
}

void MainController::loadImagesFromFolder(){
    userInterfaceView->ImageList->addItem("I tried my best bro :(");
}
