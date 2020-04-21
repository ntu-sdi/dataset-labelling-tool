#pragma once

#include <QMainWindow>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QMenu>

#include "MainController.h"
#include "ui_MainView.h"
#include "GraphicsView.h"

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
    MainView(QWidget* parent = nullptr);
    ~MainView();
    Ui::MainView getUi();
    void useController(MainController *);

public slots:
    void setMousePosition(QPoint);

private slots:
    void on_AnnotationCreateButton_clicked();

private slots:
    void on_ImageBrowseButton_clicked();
    void on_ClassAddButton_clicked();
    void on_ClassBrowseButton_clicked();
    void on_ClassCreateButton_clicked();
    void on_AnnotationBrowseButton_clicked();
    void on_ShapesCancelButton_clicked();
    void on_ShapesFinishButton_clicked();
    void on_ImageList_itemClicked(QListWidgetItem*);
    void on_ImageList_itemDoubleClicked(QListWidgetItem*);
    void on_ClassesList_itemClicked(QListWidgetItem*);
    void ProvideContextMenu(const QPoint&);
    void on_ClassListSortBox_activated(const QString &arg1);

    void on_ImageListSortBox_activated(const QString &arg1);

    void on_SearchBox_textChanged(const QString &arg1);

private:
    Ui::MainView* ui;
    MainController* controller;
    void clearMainView();
};
