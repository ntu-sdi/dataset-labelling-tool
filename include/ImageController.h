#pragma once

#include "ImageModel.h"
#include "ui_MainView.h"

class ImageController
{
private:
    Ui_MainView ui;
    ImageModel model;

public:
    void browse();
    LinkedList<std::string> searchLoaded(const std::string&);
    LinkedList<std::string> sortLoaded();
    std::string select(const std::string&);
    void open();
};
