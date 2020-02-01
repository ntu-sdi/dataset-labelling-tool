#include "MainView.h"
#include <string>

//------MainView initialization functions------//
MainView::MainView(QWidget* parent)
        : QMainWindow(parent)
        , ui(new Ui::MainView)
{
    ui->setupUi(this);
    controller = new MainController();
    controller->passViewToController(ui);
    clearMainView();

}

MainView::~MainView()
{
    delete ui;
}

void MainView::clearMainView() {
    ui->ImageList->clear();
    ui->ImageInfoLabel->clear();
    //TODO add clear of other UI elements once they are implemented
}

//------On Buttons Click Callbacks------//
void MainView::on_ImageBrowseButton_clicked()
{
    clearMainView();
    controller->loadImagesFromFolder();
}

void MainView::on_CropSaveButton_clicked()
{
}

void MainView::on_ClassBrowseButton_clicked()
{
}

void MainView::on_BBoxBrowseButton_clicked()
{
}

void MainView::on_SaveYOLOButton_clicked()
{
}

void MainView::on_RestoreButton_clicked()
{
}

//------On click on a item in a list pane------//
void MainView::on_ImageList_itemClicked(QListWidgetItem* item)
{

}

void MainView::on_ImageList_itemDoubleClicked(QListWidgetItem* item)
{
}

void MainView::on_ClassesList_itemClicked(QListWidgetItem* item)
{
}

void MainView::on_ClassesList_itemDoubleClicked(QListWidgetItem* item)
{
}




