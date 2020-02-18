#include <string>

#include "MainView.h"

MainView::MainView(const MainController& controller, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainView), controller(controller)
{
    ui->setupUi(this);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_ImageBrowseButton_clicked()
{
    controller.browseImages();
}

void MainView::on_ClassBrowseButton_clicked() {}

void MainView::on_AnnotationBrowseButton_clicked() {}

void MainView::on_ImageList_itemClicked(QListWidgetItem*) {}

void MainView::on_ImageList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ImageListSortBox_currentTextChanged(const QString&) {}

void MainView::on_ClassListSortBox_currentTextChanged(const QString&) {}
