#include "gui.h"
#include <string>

//------GUI initialization functions------//
gui::gui(QWidget* parent)
        : QMainWindow(parent)
        , ui(new Ui::gui)
{
    ui->setupUi(this);
    controller = new MainController();
    controller->passViewToController(ui);
    clearGui();

}

gui::~gui()
{
    delete ui;
}

void gui::clearGui() {
    ui->ImageList->clear();
    ui->ImageInfoLabel->clear();
    //TODO add clear of other UI elements once they are implemented
}

//------On Buttons Click Callbacks------//
void gui::on_ImageBrowseButton_clicked()
{
    clearGui();
    controller->loadImagesFromFolder();
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

//------On click on a item in a list pane------//
void gui::on_ImageList_itemClicked(QListWidgetItem* item)
{

}

void gui::on_ImageList_itemDoubleClicked(QListWidgetItem* item)
{
}

void gui::on_ClassesList_itemClicked(QListWidgetItem* item)
{
}

void gui::on_ClassesList_itemDoubleClicked(QListWidgetItem* item)
{
}




