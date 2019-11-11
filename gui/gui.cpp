#include "gui.h"
#include "./ui_gui.h"

gui::gui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gui)
{
    ui->setupUi(this);
}

gui::~gui()
{
    delete ui;
}

