#include "gui.h"
#include "./ui_gui.h"
#include <QtCore>
#include <QtGui>

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


void gui::on_ImageBrowseButton_clicked()
{

}

void gui::on_CropSaveButton_clicked()
{

}

void gui::on_ClassBrowseButton_clicked()
{

}

void gui::on_BBoxBrowseButton_clicked()
{

}

void gui::on_SaveYOLOButton_clicked()
{

}

void gui::on_RestoreButton_clicked()
{

}
