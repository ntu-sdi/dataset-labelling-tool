#include "MainView.h"
#include "MainController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainController mainController;
    MainView mainView(mainController);
    mainView.show();
    return application.exec();
}
