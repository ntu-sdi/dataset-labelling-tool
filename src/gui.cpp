#include "gui.h"
#include "./ui_gui.h"
#include <fmt/format.h>
#include <string>
#include <QtCore>
#include <QtGui>

gui::gui(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::gui) {
    ui->setupUi(this);
}

gui::~gui() {
    delete ui;
}


//------On Buttons Click Callbacks------//
void gui::on_ImageBrowseButton_clicked() {

}

void gui::on_CropSaveButton_clicked() {

}

void gui::on_ClassBrowseButton_clicked() {

}

void gui::on_BBoxBrowseButton_clicked() {

}

void gui::on_SaveYOLOButton_clicked() {

}

void gui::on_RestoreButton_clicked() {

}

void gui::setImageFolderLabel(const QString &text) {
    ui->ImageFolderLabel->setText(text);
}

void gui::imageListAdd(std::string &text) {
    QString qstr = QString::fromStdString(text);
    ui->ImageList->addItem(qstr);
}

void gui::imageListAdd(const QString &text) {
    ui->ImageList->addItem(text);
}

void gui::setImageInfoLabel(std::string &text) {
    QString qstr = QString::fromStdString(text);
    ui->ImageInfoLabel->setText(qstr);
}

void gui::setImageInfoLabel(std::string &resolution, std::string &size) {
    std::string a = fmt::format("{0} {1}", resolution, size);
}

void gui::setImageInfoLabel(unsigned short &resoultion_x, unsigned short &resoultion_y, unsigned short &size,
                            std::string &size_units) {
    std::string a = fmt::format("{0}x{1}, {2} {3}", resoultion_x, resoultion_y, size, size_units);
    QString qstr = QString::fromStdString(a);
}
