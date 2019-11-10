#include "gui.h"
#include "./ui_gui.h"
#include <QMessageBox>
#include <QDialog>
#include <QtGui>


gui::gui(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::gui)
{
    ui->setupUi(this);
}

gui::~gui()
{
    delete ui;
}


void gui::on_btn1_clicked()
{
    QMessageBox::information(this,"Message","You hit mee :(");
    ui->btn1->setText("Fuck you man :(");
}
