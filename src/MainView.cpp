#include "MainView.h"

#include <string>

MainView::MainView(MainController* controller, QWidget* parent) : QMainWindow(parent), ui(new Ui::MainView)
{
    ui->setupUi(this);
    this->controller = controller;
}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_ImageBrowseButton_clicked() {}

void MainView::on_ClassBrowseButton_clicked() {}

void MainView::on_AnnotationBrowseButton_clicked() {}

void MainView::on_ImageList_itemClicked(QListWidgetItem*) {}

void MainView::on_ImageList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ImageListSortBox_currentTextChanged(const QString&) {}

void MainView::on_ClassListSortBox_currentTextChanged(const QString&) {}
