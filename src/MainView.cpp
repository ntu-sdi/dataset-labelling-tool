#include <string>

#include "MainView.h"

/**
 * Creates a new internal Ui::MainView object and sets up the GUI.
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
}

MainView::~MainView()
{
    delete ui;
}

/**
 * Returns a pointer to the internal Ui::MainView object, which is used for processing callbacks.
 */
Ui::MainView MainView::getUi()
{
    return *ui;
}

/**
 * Passes a MainController pointer to the MainView, which it uses to process callbacks.
 *
 * @param controller
 */
void MainView::useController(MainController * controller)
{
    this->controller = controller;
}

/**
 * Callback function, which is triggered by the user clicking the "Browse"
 * button in the image panel.
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
    this->controller->addClass(className.toStdString());
}

void MainView::on_ClassBrowseButton_clicked()
{
    this->controller->browseForClassFile();
}

void MainView::on_ClassCreateButton_clicked()
{
    this->controller->createClassFile();
}

void MainView::on_AnnotationBrowseButton_clicked() {}

void MainView::on_ImageList_itemClicked(QListWidgetItem*) {}

void MainView::on_ImageList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemClicked(QListWidgetItem*) {}

void MainView::on_ClassesList_itemDoubleClicked(QListWidgetItem*) {}

void MainView::on_ImageListSortBox_currentTextChanged(const QString&) {}

void MainView::on_ClassListSortBox_currentTextChanged(const QString&) {}

void MainView::ProvideContextMenu(const QPoint& pos)
{
    QPoint globalpos = this->ui->ClassesList->mapToGlobal(pos);
    QModelIndex index = this->ui->ClassesList->indexAt(globalpos);
    QMenu submenu;
    submenu.addAction("Delete");
    QAction* rightClickItem = submenu.exec(globalpos);
    if(rightClickItem && rightClickItem->text().contains("Delete")) {
        try {
        this->controller->removeClass(
                        this->ui->ClassesList->itemAt(pos)->text().toStdString()
                    );
        this->ui->ClassesList->takeItem(index.row());
        }  catch (std::exception& e) {
            QMessageBox::warning(this, "Error", e.what(), QMessageBox::Ok);
        }
    }
}
