#include "ImageController.h"
#include "QPixmap"
#include "QGraphicsItem"
#include "iostream"

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


void ImageController::updateView()
{
    this->updateView(ui.ImageListSortBox->currentText());
}

void ImageController::updateView(const QString& sortOption)
{
    this->ui.ImageList->clearSelection();
    this->ui.ImageList->clearFocus();
    this->ui.ImageList->clear();
    if(sortOption == "Default"){
        QStringList images = model.getAll();
        ui.ImageList->clearSelection();
        ui.ImageList->clearFocus();
        ui.ImageList->clear();
        ui.ImageList->addItems(images);
    }
    else {
        if(sortOption == "Name : Ascending"){
            QStringList images = model.getAll();
            images.sort();
            ui.ImageList->addItems(images);
        }
        else if(sortOption == "Name : Descending"){
            QStringList images = model.getAll();
            images.sort();
            QVector<QString> img = images.toVector();
            std::reverse(img.begin(),img.end());
            images = img.toList();
            ui.ImageList->addItems(images);
        }
    }

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

void ImageController::select(const QString& a)
{
    QString text;
    text = QString::number(model.getFileSize(a) / 1000);
    text += " kB ";
    text += QString::number(model.getResolution(a).first);
    text += " x ";
    text += QString::number(model.getResolution(a).second);
    ui.ImageInfoLabel->setText(text);
}

/**
 * @brief Gets a filename from the MainControler, opens image and displays it in the MainView.
 *
 * @param filename
 */
void ImageController::open(const QString& fileName)
{
    QGraphicsScene* scene = new QGraphicsScene;
    QImage image = model.getImage(fileName);
    scene->addPixmap(QPixmap::fromImage(image));
    ui.imageView->setScene(scene);
    ui.imageView->show();
}
