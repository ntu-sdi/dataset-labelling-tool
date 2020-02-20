#pragma once

#include "ClassModel.h"
#include "ui_MainView.h"

class ClassController
{
private:
    Ui_MainView ui;
    ClassModel model;

public:
    ClassController(const Ui_MainView&, const ClassModel&);
    void browse();
    void create(const QString&);
    void sortLoaded();
    void add(const QString&);
    void select(const QString&);
    void remove(const QString&);
    void getSelected();
};
