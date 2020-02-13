#ifndef MainView_H
#define MainView_H
#include "MainController.h"
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
#include "ui_MainView.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainView;
}
QT_END_NAMESPACE

class MainView : public QMainWindow {
Q_OBJECT

public:
    //------MainView initialization functions------//
    MainView(QWidget* parent = nullptr);
    ~MainView();

private slots:
    //------On Buttons Click Callbacks------//
    void on_ImageBrowseButton_clicked();
    void on_ClassBrowseButton_clicked();
    void on_AnnotationBrowseButton_clicked();
    //------On click on a item in a list pane------//
    void on_ImageList_itemClicked(QListWidgetItem* item);
    void on_ImageList_itemDoubleClicked(QListWidgetItem* item);
    void on_ClassesList_itemClicked(QListWidgetItem *item);
    void on_ClassesList_itemDoubleClicked(QListWidgetItem *item);

    void on_ImageListSortBox_currentTextChanged(const QString &arg1);

    void on_ClassListSortBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainView* ui;
    void clearMainView();
    MainController *controller;

};
#endif // MainView_H
