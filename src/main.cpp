#include "MainView.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w(nullptr);
    w.show();
    return a.exec();
}
