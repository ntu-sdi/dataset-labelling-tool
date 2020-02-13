#ifndef MainView_H
#define MainView_H

#include "MainController.h"
#include "ui_MainView.h"

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainView;
}
QT_END_NAMESPACE

class MainView : public QMainWindow
{
Q_OBJECT

public:
    MainView(MainController*, QWidget* parent = nullptr);
    ~MainView();

private slots:
    void on_ImageBrowseButton_clicked();
    void on_ClassBrowseButton_clicked();
    void on_AnnotationBrowseButton_clicked();
    void on_ImageList_itemClicked(QListWidgetItem*);
    void on_ImageList_itemDoubleClicked(QListWidgetItem*);
    void on_ClassesList_itemClicked(QListWidgetItem*);
    void on_ClassesList_itemDoubleClicked(QListWidgetItem*);
    void on_ImageListSortBox_currentTextChanged(const QString&);
    void on_ClassListSortBox_currentTextChanged(const QString&);

private:
    Ui::MainView* ui;
    void clearMainView();
    MainController* controller;
};

#endif
