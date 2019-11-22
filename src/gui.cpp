#include "gui.h"
#include "ui_gui.h"
#include <fmt/format.h>
#include <string>

//------GUI initialization functions------//
gui::gui(QWidget* parent)
        : QMainWindow(parent)
        , ui(new Ui::gui)
{
    ui->setupUi(this);
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
    imageBrowser = new ImageBrowser();
    QString directory = QFileDialog::getExistingDirectory(this,
                                                          tr("Find Folders"),QDir::currentPath(),QFileDialog::ShowDirsOnly);
    imageBrowser->browseFolderForSupportedFiles(directory.toStdString());
    auto i =imageBrowser->returnImages();
    imageListAdd(&i);


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
    std::string imageName = item->text().toStdString();
    std::string path = imageBrowser->returnImagePath(imageName);
    std::string extension = imageBrowser->returnImageExtension(path);
    LinkedList<int> res;
    res = imageBrowser->returnResolution(path);
    setImageInfoLabel(res.at(0),res.at(1),imageBrowser->returnImageFilesize(path),"Bytes");
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

//------Functions to change text of labels------//
void gui::imageListAdd(std::string text)
{
    ui->ImageList->addItem(strToQstr(text));
}

void gui::imageListAdd(const QString& text)
{
    ui->ImageList->addItem(text);
}

void gui::imageListAdd(LinkedList<std::string> *a)
{
    for(int i = 0; i<a->length();i++){
        std::string img = a->at(i);
        imageListAdd(imageBrowser->returnImageName(img));
    }
}

void gui::setImageInfoLabel(int resoultion_x, int resoultion_y, long size,
                            std::string size_units)
{
    std::string a = fmt::format("{0}x{1}, {2} {3}", resoultion_x, resoultion_y, size, size_units);
    ui->ImageInfoLabel->setText(strToQstr(a));
}

//------Other helper functions------//
QString gui::strToQstr(std::string& text)
{
    return QString(QString::fromStdString(text));
}




