#include <QPixmap>
#include <QGraphicsItem>
#include <QFileInfo>
#include <QDate>
#include "ImageController.h"

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

void ImageController::updateView(const QString& sortOption, bool search)
{
    this->ui.ImageList->clearSelection();
    this->ui.ImageList->clearFocus();
    this->ui.ImageList->clear();
    if (search) {
        QStringList images = model.getAll();
        if (images.contains(sortOption)) {
            ui.ImageList->addItem(sortOption);
        }
    }
    else {
        if (sortOption == "Default") {
            QStringList images = model.getAll();
            ui.ImageList->addItems(images);
        }
        else {
            if (sortOption == "Name : Ascending") {
                QStringList images = model.getAll();
                images.sort();
                ui.ImageList->addItems(images);
            }
            else if (sortOption == "Name : Descending") {
                QStringList images = model.getAll();
                images.sort();
                QVector<QString> img = images.toVector();
                std::reverse(img.begin(), img.end());
                images = img.toList();
                ui.ImageList->addItems(images);
            }
            else if (sortOption == "Date created : Ascending") {
                QMap<QString, QFileInfo> images = model.getAllWithDetails();
                QMap<QString, QDateTime> sortedData;
                QMap<QString, QFileInfo>::const_iterator i = images.constBegin();
                while (i != images.constEnd()) {
                    sortedData[i.key()] = i.value().birthTime();
                    ++i;
                }
                ui.ImageList->addItems(sortedData.keys());
            }
            else if (sortOption == "Date created : Descending") {
                QMap<QString, QFileInfo> images = model.getAllWithDetails();
                QMap<QString, QDateTime> sortedData;
                QMap<QString, QFileInfo>::const_iterator i = images.constBegin();
                while (i != images.constEnd()) {
                    sortedData[i.key()] = i.value().birthTime();
                    ++i;
                }
                QMap<QString, QDateTime>::const_iterator j = sortedData.constEnd();
                while (j != sortedData.constBegin()) {
                    j--;
                    ui.ImageList->addItem(j.key());
                }
            }
            else if (sortOption == "Size : Ascending") {
                QMap<QString, QFileInfo> images = model.getAllWithDetails();
                QMap<QString, qint64> sortedData;
                QMap<QString, QFileInfo>::const_iterator i = images.constBegin();
                while (i != images.constEnd()) {
                    sortedData[i.key()] = i.value().size();
                    ++i;
                }
                ui.ImageList->addItems(sortedData.keys());
            }
            else if (sortOption == "Size : Descending") {
                QMap<QString, QFileInfo> images = model.getAllWithDetails();
                QMap<QString, qint64> sortedData;
                QMap<QString, QFileInfo>::const_iterator i = images.constBegin();
                while (i != images.constEnd()) {
                    sortedData[i.key()] = i.value().size();
                    ++i;
                }
                QMap<QString, qint64>::const_iterator j = sortedData.constEnd();
                while (j != sortedData.constBegin()) {
                    j--;
                    ui.ImageList->addItem(j.key());
                }
            }
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
