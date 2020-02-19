#include <string>

#include "MainView.h"

MainView::MainView(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainView)
{
    ui->setupUi(this);
}

MainView::~MainView()
{
    delete ui;
}

Ui::MainView MainView::returnReferenceOfUi()
{
    return *ui;
}

void MainView::useController(MainController * cnt)
{
    controller = cnt;
}

void MainView::on_ImageBrowseButton_clicked()
{
    controller->browseImages();
}

void MainView::on_ClassAddButton_clicked()
{
    bool ok;
    QString className;
    className = QInputDialog::getText(this, "New Class", "Class name",
                                      QLineEdit::Normal, className, &ok);
    this->controller.addClass(className.toStdString());
}

void MainView::on_ClassBrowseButton_clicked()
{
    this->controller.browseForClassFile();
}

void MainView::on_ClassCreateButton_clicked()
{
    this->controller.createClassFile();
}

void MainView::on_AnnotationBrowseButton_clicked() {}

void MainView::on_ImageList_itemClicked(QListWidgetItem*) {}

void MainView::on_ImageList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ImageListSortBox_currentTextChanged(const QString&) {}

void MainView::on_ClassListSortBox_currentTextChanged(const QString&) {}
