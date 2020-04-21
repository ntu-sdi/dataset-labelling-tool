#include "MainView.h"

/**
 * @brief Creates a new internal Ui::MainView object and sets up the GUI.
 *
 * @param parent
 */
MainView::MainView(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainView)
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

/**
 * @brief Callback function, triggered by user clicking on add class button.
 */
void MainView::on_ClassAddButton_clicked()
{
    bool ok;
    QString className;
    className = QInputDialog::getText(this, "New Class", "Class name",
        QLineEdit::Normal, className, &ok);
    this->controller->addClass(className);
}

/**
 * @brief Callback function, triggered when user clicks on browse class file button.
 */
void MainView::on_ClassBrowseButton_clicked()
{
    this->controller->browseForClassFile();
}

/**
 * @brief Callback function, triggered when user clicks on create class button
 */
void MainView::on_ClassCreateButton_clicked()
{
    this->controller->createClassFile();
}

/**
 * @brief Callback function, triggered when users clicks on browse annotation file button.
 */
void MainView::on_AnnotationBrowseButton_clicked()
{
    controller->browseForAnnotationFile();
}

void MainView::on_ShapesCancelButton_clicked()
{
    this->controller->cancelShape();
}

void MainView::on_ShapesFinishButton_clicked()
{
    this->controller->finishShape();
}

/**
 * @brief Callback function, which is triggered by user clicking on create annotation file button.
 */
void MainView::on_AnnotationCreateButton_clicked()
{
    controller->createAnnotationFile();
}

/**
 * @brief Callback function, triggered by user single clicking image name in image list pane.
 *
 * @param imageName Name of the image clicked on.
 */
void MainView::on_ImageList_itemClicked(QListWidgetItem* imageName)
{
    controller->selectImage(imageName->text());
}

/**
 * @brief Callback function, which is triggered by user double clicking on the image file name in the image pannel.
 *
 * Then passes request to open image to MainController.
 *
 * @param filename
 */
void MainView::on_ImageList_itemDoubleClicked(QListWidgetItem* fileName)
{
    controller->openImage(fileName->text());
}

/**
 * @brief Callback function, triggered when user single clicks on a class in class  pane.
 *
 * @param className Name of the class clicked
 */
void MainView::on_ClassesList_itemClicked(QListWidgetItem* className)
{
    controller->selectClass(className->text());
}

/**
 * @brief Creates a context menu on right-click of the classes pane.
 *
 * @param pos Position of the cursor.
 */
void MainView::ProvideContextMenu(const QPoint& position)
{
    QPoint globalPosition = this->ui->ClassesList->viewport()->mapToGlobal(position);
    QModelIndex index = this->ui->ClassesList->indexAt(position);
    if (!index.isValid()) {
        return;
    }
    QMenu submenu;
    submenu.addAction("Delete");
    QAction* rightClickItem = submenu.exec(globalPosition);
    if (rightClickItem && rightClickItem->text().contains("Delete")) {
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
    this->controller->addPoint(point);
}

/**
 * @brief Callback function, triggered when user clicks on class list sort box.
 *
 * @param arg1 Sort option.
 */
void MainView::on_ClassListSortBox_activated(const QString& arg1)
{
    controller->sortLoadedClasses(arg1);
}

/**
 * @brief Callback function, triggered when user clicks on image list sort box.
 *
 * @param arg1 Sort option.
 */
void MainView::on_ImageListSortBox_activated(const QString& arg1)
{
    controller->sortLoadedImages(arg1);
}

/**
 * @brief Callback function, triggered when user types a new letter in image seach box.
 *
 * @param arg1 Search query.
 */
void MainView::on_SearchBox_textChanged(const QString& arg1)
{
    if (arg1.isEmpty()) {
        controller->sortLoadedImages(ui->ImageListSortBox->currentText());
    }
    else {
        controller->sortLoadedImages(arg1, true);
    }
}

void MainView::on_SaveAnnotationFileButton_clicked()
{

}
