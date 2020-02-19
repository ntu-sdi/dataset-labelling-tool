#pragma once

#include "ImageModel.h"
#include "ui_MainView.h"

class ImageController
{
private:
    Ui_MainView ui;
    ImageModel model;
    void updateView();

public:
    ImageController(Ui_MainView&, ImageModel&);
    void browseFolder();
    void searchLoaded(const std::string&);
    void sortLoaded();
    void select(const std::string&);
    void open();
};
