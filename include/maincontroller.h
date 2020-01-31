#ifndef MAINController_H
#define MAINController_H
#include "ui_gui.h"

class MainController
{
public:
    MainController();
    void passViewToController(Ui::gui *ui);
    void loadImagesFromFolder();
    Ui::gui * userInterfaceView;

private:

};

#endif // MAINController_H
