#include <QPixmap>
#include <QGraphicsItem>
#include <QFileInfo>
#include <QDate>
#include <iostream>

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
    this->scene = nullptr;
    this->pen = QPen();
    this->font = QFont();
    this->pen.setColor(QColor(255, 0, 0));
}

/**
 * @brief Updates the view based on the sort option selected in the gui
 */
void ImageController::updateView()
{
    this->updateView(ui.ImageListSortBox->currentText());
}

/**
 * @brief ImageController::updateView Updates the view with the sorted and searched list of images.
 *
 * @param sortOption
 * @param search
 */
void ImageController::updateView(const QString& sortOption, bool search)
{
    this->ui.ImageList->clearSelection();
    this->ui.ImageList->clearFocus();
    this->ui.ImageList->clear();
    if(search) {
        QStringList images = model.getAll();
        QStringList filtered = images.filter(sortOption);
        ui.ImageList->addItems(filtered);
    }
    else {
        if(sortOption == "Default") {
            QStringList images = model.getAll();
            ui.ImageList->addItems(images);
        }
        else {
            if(sortOption == "Name : Ascending") {
                QStringList images = model.getAll();
                images.sort(Qt::CaseInsensitive);
                ui.ImageList->addItems(images);
            }
            else if(sortOption == "Name : Descending") {
                QStringList images = model.getAll();
                images.sort(Qt::CaseInsensitive);
                QVector<QString> img = images.toVector();
                std::reverse(img.begin(), img.end());
                images = img.toList();
                ui.ImageList->addItems(images);
            }
            else if(sortOption == "Date : Ascending") {
                QMap<QString, QFileInfo> images = model.getAllWithDetails();
                QList<QPair<QString,QDateTime>> data;
                QMap<QString, QFileInfo>::const_iterator i = images.constBegin();
                while (i != images.constEnd()) {
                    QPair<QString,QDateTime> temp;
                    temp.first = i.key();
                    temp.second = i.value().lastModified();
                    data.append(temp);
                    ++i;
                }
                std::sort(data.begin(),data.end(),[](QPair<QString, QDateTime> a , QPair<QString, QDateTime> b ) -> bool
                {
                    return a.second > b.second;
                });
                for(auto i:data){
                    ui.ImageList->addItem(i.first);
                }
            }
            else if(sortOption == "Date : Descending") {
                QMap<QString, QFileInfo> images = model.getAllWithDetails();
                QList<QPair<QString,QDateTime>> data;
                QMap<QString, QFileInfo>::const_iterator i = images.constBegin();
                while (i != images.constEnd()) {
                    QPair<QString,QDateTime> temp;
                    temp.first = i.key();
                    temp.second = i.value().lastModified();
                    data.append(temp);
                    ++i;
                }
                std::sort(data.begin(),data.end(),[](QPair<QString, QDateTime> a , QPair<QString, QDateTime> b ) -> bool
                {
                    return a.second < b.second;
                });
                for(auto i:data){
                    ui.ImageList->addItem(i.first);
                }
            }
        }
    }
}

/**
 * @brief ImageController::mapToImage Map GraphicsView coordinates to image coordinates.
 *
 * @param point
 *
 * @return QPoint
 */
QPoint ImageController::mapToImage(QPoint point)
{
    double xFactor = this->scene->width() / this->ui.imageView->width();
    double yFactor = this->scene->height() / this->ui.imageView->height();
    point.setX(static_cast<int>(point.x() * xFactor));
    point.setY(static_cast<int>(point.y() * yFactor));
    return point;
}

/**
 * @brief ImageController::drawAnnotations Adds annotations to the GraphicsView.
 */
void ImageController::drawAnnotations()
{
    if(this->scene != nullptr) {
        for(size_t i = 0; i < this->annotations.length(); ++i) {
            this->scene->addPolygon(
                QPolygonF(this->annotations.at(i).second), this->pen);
            this->drawLabel(this->annotations.at(i).first,
                            this->annotations.at(i).second);
        }
    }
}

/**
 * @brief ImageController::setDrawingSize Set annotation drawing width proportional to the image size.
 */
void ImageController::setDrawingSize()
{
    if(this->scene != nullptr) {
        int lineSize = static_cast<int>(
            std::ceil((this->scene->width() + this->scene->height()) / 500));
        this->pen.setWidth(lineSize);
    }
}

/**
 * @brief ImageController::getTextPos Calculates a position for the label.
 *
 * @param points
 * @param textWidth
 * @param textHeight
 *
 * @return QPointF
 */
QPointF ImageController::getTextPos(QVector<QPointF> points, qreal textWidth, qreal textHeight)
{
    QPointF textPoint;
    double midPoint = this->scene->width() / 2;
    double distance = this->scene->width();
    for(QPointF i: points) {
        if(std::abs(midPoint - i.x()) < distance) {
            distance = std::abs(midPoint - i.x());
            textPoint = i;
        }
    }
    if(textPoint.x() + textWidth > this->scene->width()) {
        textPoint.setX(textPoint.x() - textWidth);
    }
    if(textPoint.y() + textHeight > this->scene->height()) {
        textPoint.setY(textPoint.y() - textHeight);
    }
    return textPoint;
}

/**
 * @brief ImageController::drawLabel Add a styled label to the scene.
 *
 * @param content
 * @param shape
 */
void ImageController::drawLabel(QString content, QVector<QPointF> shape)
{
    QGraphicsTextItem* text = new QGraphicsTextItem();
    int fontHeight = static_cast<int>(
    std::ceil((this->scene->width() + this->scene->height()) / 75));
    text->setHtml("<div style='background-color:#666666; font-size: " +
              QString::fromStdString(std::to_string(fontHeight)) +
              "px;'>" + content + "</div>");
    QRectF boundingRect = text->boundingRect();
    while(boundingRect.width() > this->scene->width() && content.length() > 4) {
        content.truncate(content.length() - 1);
        content.append("...");
        text->setHtml("<div style='background-color:#666666; font-size: " +
                  QString::fromStdString(std::to_string(fontHeight)) +
                  "px;'>" + content + "</div>");
    }
    text->setPos(
            this->getTextPos(shape, boundingRect.width(), boundingRect.height()));
    this->scene->addItem(text);
}

/**
 * @brief Browses for a new folder containing images, then updates the view to reflect that.
 */
void ImageController::browseFolder()
{
    model.browseFolder();
    updateView();
}

/**
 * @brief ImageController::select Updates the information for the selected file.
 *
 * @param fileName
 */
void ImageController::select(const QString& fileName)
{
    QString text;
    text = QString::number(model.getFileSize(fileName) / 1000);
    text += " kB ";
    text += QString::number(model.getResolution(fileName).first);
    text += " x ";
    text += QString::number(model.getResolution(fileName).second);
    ui.ImageInfoLabel->setText(text);
}

/**
 * @brief Gets a filename from the MainControler, opens image and displays it in the MainView.
 *
 * @param fileName
 */
void ImageController::open(const QString& fileName)
{
    this->ui.imageView->resize(871, 711);
    this->currentFileName = fileName;
    this->scene = new QGraphicsScene;
    if(this->currentFileName != fileName) {
        this->points = {};
    }
    QImage image = model.getImage(fileName);
    this->imageHeight = image.height();
    this->imageWidth = image.width();
    scene->addPixmap(QPixmap::fromImage(image));
    ui.imageView->setScene(scene);
    ui.imageView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    this->ui.imageView->adjustSize();
    ui.imageView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    ui.imageView->show();
    this->setDrawingSize();
    this->drawAnnotations();
}

/**
 * @brief ImageController::addPoint Adds a point to the annotation.
 *
 * @param point
 */
void ImageController::addPoint(const QPoint& point)
{
    if(this->scene == nullptr) {
        return;
    }
    QPointF p(this->mapToImage(point));
    this->points.append(p);
    this->open(this->currentFileName);
    if(this->points.length() > 2) {
        this->scene->addPolygon(points, this->pen);
    }
    else if(points.length() == 2) {
        this->scene->addLine(QLineF(this->points.at(0), this->points.at(1)), this->pen);
    }
}

/**
 * @brief ImageController::cancelShape Cancels the currently drawn shape.
 */
void ImageController::cancelShape()
{
    this->points = {};
    try {
        this->open(this->currentFileName);
    }
    catch (std::runtime_error) {}
}

/**
 * @brief ImageController::finishShape Finishes the current shape by adding the last side.
 *
 * @param className
 *
 * @return QVector<QPointF>
 */
QVector<QPointF> ImageController::finishShape(const QString& className)
{
    if(this->points.length() < 3) {
        throw DrawingIncomplete();
    }
    this->drawLabel(className, this->points);
    QVector<QPointF> ret = this->points;
    this->points = {};
    return ret;
}

/**
 * @brief ImageController::setAnnotations
 *
 * @param annotations
 */
void ImageController::setAnnotations(LinkedList<QPair<QString, LinkedList<QPair<int, int>>>> annotations)
{
    this->annotations = LinkedList<QPair<QString, QVector<QPointF>>>();
    for(size_t i = 0; i < annotations.length(); i++) {
        QPair<QString, QVector<QPointF>> pair = QPair<QString, QVector<QPointF>>(annotations.at(i).first, QVector<QPointF>());
        for(size_t j = 0; j < annotations.at(i).second.length(); j++) {
            QPointF point(annotations.at(i).second.at(j).first, annotations.at(i).second.at(j).second);
            pair.second.append(point);
        }
        this->annotations.push(pair);
    }
}

/**
 * @brief ImageController::getCurrentFileName Returns the currently opened file name.
 *
 * @return QString
 */
QString ImageController::getCurrentFileName()
{
    return this->currentFileName;
}
