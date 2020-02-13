#ifndef MAINController_H
#define MAINController_H
#include "ui_MainView.h"

class MainController
{
public:
    MainController();
    void passViewToController(Ui::MainView *ui);
    void loadImagesFromFolder();
    Ui::MainView * userInterfaceView;

private:

};

#endif // MAINController_H
