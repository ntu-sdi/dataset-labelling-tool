#pragma once

#include "ClassModel.h"
#include "ui_MainView.h"

class ClassController
{
private:
    Ui_MainView* ui;
    ClassModel model;

public:
    void browse();
    void create();
    void sortLoaded();
    void add(const std::string&);
    void select(const std::string&);
    void remove(const std::string&);
    void getSelected();
};
