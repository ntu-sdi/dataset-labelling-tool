#include <string>
#include <QDebug>

#include "MainView.h"

/**
 * @brief Creates a new internal Ui::MainView object and sets up the GUI.
 *
 * @param parent
 */
MainView::MainView(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainView)
{
    ui->setupUi(this);
    this->ui->ClassesList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this->ui->ClassesList, &QListWidget::customContextMenuRequested,
            this, &MainView::ProvideContextMenu);
    connect(this->ui->imageView, SIGNAL(sendMousePosition(QPoint)),
            this, SLOT(setMousePosition(QPoint)));
}

/**
 * @brief Destructs the internal Ui::MainView object.
 */
MainView::~MainView()
{
    delete ui;
}

/**
 * @brief Returns a pointer to the internal Ui::MainView object, which is used for processing callbacks.
 */
Ui::MainView MainView::getUi()
{
    return *ui;
}

/**
 * @brief Passes a MainController pointer to the MainView, which it uses to process callbacks.
 *
 * @param controller
 */
void MainView::useController(MainController* controller)
{
    this->controller = controller;
}

/**
 * @brief Callback function, which is triggered by the user clicking the "Browse" button in the image panel.
 */
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
    this->controller->addClass(className);
}

void MainView::on_ClassBrowseButton_clicked()
{
    this->controller->browseForClassFile();
}

void MainView::on_ClassCreateButton_clicked()
{
    this->controller->createClassFile();
}

void MainView::on_AnnotationBrowseButton_clicked() {
    controller->browseForAnnotationFile();
}

/**
 * @brief Callback function, which is triggered by user clicking on create annotation file button
 */
void MainView::on_AnnotationCreateButton_clicked()
{
    controller->createAnnotationFile();
}

void MainView::on_ImageList_itemClicked(QListWidgetItem*) {}

/**
 * @brief Callback function, which is triggered by user double clicking on the image file name in the image pannel.
 *
 * Then passes request to open image to MainController.
 *
 * @param filename
 */
void MainView::on_ImageList_itemDoubleClicked(QListWidgetItem* fileName) {
    controller->openImage(fileName->text());
}

void MainView::on_ClassesList_itemClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ImageListSortBox_currentTextChanged(const QString&) {}

void MainView::on_ClassListSortBox_currentTextChanged(const QString&) {}

/**
 * @brief Creates a context menu on right-click of the classes pane.
 *
 * @param pos Position of the cursor.
 */
void MainView::ProvideContextMenu(const QPoint& position)
{
    QPoint globalPosition = this->ui->ClassesList->viewport()->mapToGlobal(position);
    QModelIndex index = this->ui->ClassesList->indexAt(position);
    if(!index.isValid()) {
        return;
    }
    QMenu submenu;
    submenu.addAction("Delete");
    QAction* rightClickItem = submenu.exec(globalPosition);
    if(rightClickItem && rightClickItem->text().contains("Delete")) {
        try {
            this->controller->removeClass(this->ui->ClassesList->itemAt(position)->text());
        }
        catch (std::exception& exception) {
            QMessageBox::warning(this, "Error", exception.what(), QMessageBox::Ok);
        }
    }
}

void MainView::setMousePosition(QPoint point)
{
    std::cout << "Got the point!" << std::endl;
    std::cout << point.x() << " " << point.y() << std::endl;
    this->controller->addPoint(point);
}
