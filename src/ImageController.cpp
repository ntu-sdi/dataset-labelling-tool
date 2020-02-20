#include "ImageController.h"
#include "QPixmap"
#include "QGraphicsItem"

/**
 * Constructs an ImageController, which handles business logic, related to the image files.
 *
 * @param ui The Ui_MainView reference, which is used to update the GUI.
 * @param model
 */
ImageController::ImageController(Ui_MainView& ui, ImageModel& model)
{
    this->ui = ui;
    this->model = model;
}

/**
 * Clears the selection, focus and list of loaded images in the GUI and refills them from the
 * currently loaded images in the model.
 */
void ImageController::updateView()
{
    QStringList images = model.getAll();
    ui.ImageList->clearSelection();
    ui.ImageList->clearFocus();
    ui.ImageList->clear();
    ui.ImageList->addItems(images);
}

/**
 * Browses for a new folder containing images, then updates the view to reflect that.
 */
void ImageController::browseFolder()
{
    model.browseFolder();
    updateView();
}

void ImageController::searchLoaded(const std::string&) {}

void ImageController::sortLoaded() {}

void ImageController::select(const std::string&) {}

void ImageController::open(const QString& filename) {
      QGraphicsScene *scene =  new QGraphicsScene;
      QPixmap pixmap = model.getImage(filename);
      scene->addPixmap(pixmap);
      ui.imageView->setScene(scene);
      ui.imageView->show();

}

