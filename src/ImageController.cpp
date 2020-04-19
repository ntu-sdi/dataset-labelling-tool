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
    this->scene = nullptr;
}

void ImageController::drawLine(QPoint p1, QPoint p2)
{
    if (this->scene == nullptr) return;
    this->scene->addLine(p1.x(), p1.y(), p2.x(), p2.y());
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
    this->currentFileName = fileName;
    this->scene = new QGraphicsScene;
    this->points = {};
    QImage image = model.getImage(fileName);
    scene->addPixmap(QPixmap::fromImage(image));
    ui.imageView->setScene(this->scene);
    ui.imageView->show();
}

void ImageController::addPoint(const QPoint& point)
{
    if (this->scene == nullptr) return;

    points.append(point);
    if (points.length() > 1)
    {
        this->drawLine(this->points.last(),
                       this->points.at(this->points.length()-2));
    }
}

void ImageController::cancelShape()
{
    this->open(this->currentFileName);
}

QList<QPoint> ImageController::finishShape(const QString& className)
{
    if(this->points.length() < 3)
        throw DrawingIncomplete();
    this->drawLine(this->points.first(), this->points.last());
    QGraphicsTextItem* text = this->scene->addText(className);
    text->setPos(this->points.first().x(),
                 this->points.first().y());
    QList<QPoint> ret = this->points;
    this->points = {};
    return ret;
}
