#pragma once

#include "ImageModel.h"
#include "ui_MainView.h"

/**
 * Sub-controller, which gets delegated tasks, relating to loading, storing and updating images.
 * Communicates directly with the ImageModel.
 */
class ImageController
{
private:
    Ui_MainView ui;
    ImageModel model;
public:
    ImageController(Ui_MainView&, ImageModel&);
    void updateView();
    void updateView(const QString&,bool = false);
    void browseFolder();
    void searchLoaded(const QString&);
    void sortLoaded();
    void select(const QString&);
    void open(const QString&);
};
