#pragma once

#include <QMessageBox>

#include "ClassModel.h"
#include "ui_MainView.h"

/**
 * Sub-controller which gets delegated tasks related to creating, adding and removing classes.
 * Communicates directly with the ClassModel.
 */
class ClassController
{
private:
    Ui_MainView ui;
    ClassModel model;

public:
    ClassController(const Ui_MainView&, const ClassModel&);
    void browse();
    void create();
    void sortLoaded();
    void add(const QString&);
    void select(const QString&);
    void remove(const QString&);
    void updateView();
    void updateView(const QString&);
    QString getSelected();

};
