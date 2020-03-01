#include "ImageController.h"
#include "QPixmap"
#include "QGraphicsItem"

/**
 * @brief Constructs an ImageController, which handles business logic, related to the image files.
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
 * @brief Clears the list of loaded images in the GUI and refills them from the currently loaded images.
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
 * @brief Browses for a new folder containing images, then updates the view to reflect that.
 */
void ImageController::browseFolder()
{
    model.browseFolder();
    updateView();
}

void ImageController::searchLoaded(const QString&) {}

void ImageController::sortLoaded() {}

void ImageController::select(const QString&) {}

/**
 * @brief Gets a filename from the MainControler, opens image and displays it in the MainView.
 *
 * @param filename
 */
void ImageController::open(const QString& filename) {
      QGraphicsScene *scene =  new QGraphicsScene;
      QImage img = model.getImage(filename);
      scene->addPixmap(QPixmap::fromImage(img));
      ui.imageView->setScene(scene);
      ui.imageView->show();
}

