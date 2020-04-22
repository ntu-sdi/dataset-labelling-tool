#include <QPixmap>
#include <QGraphicsItem>
#include <QFileInfo>
#include <QDate>
#include "ImageController.h"

/**
 * @brief Constructs an ImageController, which handles business logic, related to the image files.
 *
 * @param ui The Ui_MainView reference, which is used to update the GUI.
 * @param modela
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
 * @brief ImageController::updateView
 * @param sortOption
 * @param search
 */
void ImageController::updateView(const QString& sortOption, bool search)
{
    this->ui.ImageList->clearSelection();
    this->ui.ImageList->clearFocus();
    this->ui.ImageList->clear();
    if (search) {
        QStringList images = model.getAll();
        QStringList filtered = images.filter(sortOption);
        ui.ImageList->addItems(filtered);
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

QPoint ImageController::mapToImage(QPoint point)
{
    double xFactor = this->scene->width() / this->ui.imageView->width();
    double yFactor = this->scene->height() / this->ui.imageView->height();
    point.setX(static_cast<int>(point.x() * xFactor));
    point.setY(static_cast<int>(point.y() * yFactor));
    return point;
}

void ImageController::drawAnnotations()
{
    if (this->scene != nullptr) {
        for (size_t i = 0; i < this->annotations.length(); ++i) {
            this->scene->addPolygon(
                QPolygonF(this->annotations.at(i).second), this->pen);
            this->drawLabel(this->annotations.at(i).first,
                            this->annotations.at(i).second);
        }
    }
}

void ImageController::setDrawingSize()
{
    if (this->scene != nullptr) {
        int lineSize = static_cast<int>(
            std::ceil((this->scene->width() + this->scene->height()) / 500));
        this->pen.setWidth(lineSize);
    }
}

QPointF ImageController::getTextPos(QVector<QPointF> points, qreal textWidth, qreal textHeight)
{
    QPointF textPoint;
    double midPoint = this->scene->width() / 2;
    double distance = this->scene->width();
    for (QPointF i: points) {
        if (std::abs(midPoint - i.x()) < distance) {
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
    this->ui.imageView->resize(871, 711);
    this->currentFileName = fileName;
    this->scene = new QGraphicsScene;
    if (this->currentFileName != fileName) {
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

void ImageController::addPoint(const QPoint& point)
{
    if (this->scene == nullptr)
        return;

    QPointF p(this->mapToImage(point));
    this->points.append(p);

    this->open(this->currentFileName);
    if (this->points.length() > 2) {
        this->scene->addPolygon(points, this->pen);
    }
    else if (points.length() == 2) {
        this->scene->addLine(QLineF(this->points.at(0), this->points.at(1)), this->pen);
    }
}

void ImageController::cancelShape()
{
    this->points = {};
    this->open(this->currentFileName);
}

QVector<QPointF> ImageController::finishShape(const QString& className)
{
    if (this->points.length() < 3)
        throw DrawingIncomplete();
    this->drawLabel(className, this->points);
    QVector<QPointF> ret = this->points;
    this->points = {};
    return ret;
}

void ImageController::setAnnotations(LinkedList<QPair<QString, LinkedList<QPair<int, int> > > > a)
{
    this->annotations = LinkedList<QPair<QString, QVector<QPointF> > >();
    for (size_t i = 0; i < a.length(); i++) {
        QPair<QString, QVector<QPointF> > pair = QPair<QString, QVector<QPointF> >(a.at(i).first, QVector<QPointF>());
        for (size_t j = 0; j < a.at(i).second.length(); j++) {
            QPointF point(a.at(i).second.at(j).first, a.at(i).second.at(j).second);
            pair.second.append(point);
        }
        this->annotations.push(pair);
    }
}

QString ImageController::getCurrentFileName()
{
    return this->currentFileName;
}
