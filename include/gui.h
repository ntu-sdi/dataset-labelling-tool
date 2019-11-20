#ifndef GUI_H
#define GUI_H
#include <iostream>
#include <string>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QLineEdit>
#include <ImageBrowser.h>
#include <LinkedList.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class gui;
}
QT_END_NAMESPACE

class gui : public QMainWindow {
Q_OBJECT

public:
    //------GUI initialization functions------//
    gui(QWidget* parent = nullptr);
    ~gui();

private slots:
    //------On Buttons Click Callbacks------//
    void on_ImageBrowseButton_clicked();
    static void on_CropSaveButton_clicked();
    static void on_ClassBrowseButton_clicked();
    static void on_BBoxBrowseButton_clicked();
    static void on_SaveYOLOButton_clicked();
    static void on_RestoreButton_clicked();
    //------On click on a item in a list pane------//
    static void on_ImageList_itemClicked(QListWidgetItem* item);
    static void on_ImageList_itemDoubleClicked(QListWidgetItem* item);
    static void on_ClassesList_itemClicked(QListWidgetItem *item);
    static void on_ClassesList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::gui* ui;
    ImageBrowser* imageBrowser{};
    LinkedList<std::string> loadedFiles;
    //------On Buttons Click Callbacks------//
    void setImageFolderLabel(const QString& text);
    void imageListAdd(const QString& text);
    void imageListAdd(std::string text);
    void imageListAdd(LinkedList<std::basic_string<char>> *a);
    //TODO: create function which takes LinkedList as input
    void setImageInfoLabel(std::string& text);
    void setImageInfoLabel(std::string& resolution, std::string& size);
    void setImageInfoLabel(unsigned short& resoultion_x, unsigned short& resoultion_y, unsigned short& size, std::string& size_units);
    //------Helper Functions------//
    static QString strToQstr(std::string& text);


};
#endif // GUI_H
