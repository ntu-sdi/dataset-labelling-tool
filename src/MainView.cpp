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
    ui->ImageList->addItem("Image1.jpg");
    ui->ImageList->addItem("Image2.png");
    ui->ImageList->addItem("Image3.jpg");
    ui->ImageList->addItem("Image24.png");
    ui->ImageList->addItem("Image1231.jpg");
    ui->ImageList->addItem("Image32.png");
    ui->ClassesList->addItem("Car");
    ui->ClassesList->addItem("Boat");
    ui->ClassesList->addItem("Plane");
    ui->ImageInfoLabel->setText("1920x1080, 5131.21 kB");
    ui->ClassFileLabel->setText("someclasses.class");
    ui->AnnotationFileLabel->setText("annots.annotation");


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

void MainView::on_ClassBrowseButton_clicked()
{
}

void MainView::on_AnnotationBrowseButton_clicked()
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



void MainView::on_ImageListSortBox_currentTextChanged(const QString &arg1)
{

}

void MainView::on_ClassListSortBox_currentTextChanged(const QString &arg1)
{

}
