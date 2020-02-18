#include "ImageController.h"

ImageController::ImageController(Ui_MainView& ui, ImageModel& model)
{
    this->ui = ui;
    this->model = model;
}

void ImageController::updateView()
{
    QStringList images = model.getAll();
    ui.ImageList->clearSelection();
    ui.ImageList->clearFocus();
    ui.ImageList->clear();
    ui.ImageList->addItems(images);
}

void ImageController::browseFolder()
{
    model.browseFolder();
    updateView();
}

void ImageController::searchLoaded(const std::string&) {}

void ImageController::sortLoaded() {}

void ImageController::select(const std::string&) {}

void ImageController::open() {}

