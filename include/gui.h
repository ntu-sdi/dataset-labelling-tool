#ifndef GUI_H
#define GUI_H
#include <iostream>
#include <string>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QMainWindow
{
Q_OBJECT

public:
    gui(QWidget *parent = nullptr);
    ~gui();
private:
    void setImageFolderLabel(const QString &text);
    void imageListAdd(const QString &text);
    void imageListAdd(std::string &text);
    //todo create function which takes LinkedList developed by Cian as input
    void setImageInfoLabel(std::string &text);
    void setImageInfoLabel(std::string &resolution, std::string &size);
    void setImageInfoLabel(unsigned short &resoultion_x, unsigned short &resoultion_y, unsigned short &size, std::string &size_units);


private slots:
    void on_ImageBrowseButton_clicked();

    void on_CropSaveButton_clicked();

    void on_ClassBrowseButton_clicked();

    void on_BBoxBrowseButton_clicked();

    void on_SaveYOLOButton_clicked();

    void on_RestoreButton_clicked();

private:
    Ui::gui *ui;

};
#endif // GUI_H
