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

    this->pen = QPen();
    this->font = QFont();
    this->pen.setColor(QColor(255, 0, 0));
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
    if(this->scene != nullptr) {
        for(size_t i = 0; i < this->annotations.length(); ++i) {
            this->scene->addPolygon(
                        QPolygonF(this->annotations.at(i).second), this->pen);
            QGraphicsTextItem* text = this->scene->addText(this->annotations.at(i).first, this->font);
            text->setPos(this->annotations.at(i).second.at(0));
        }
    }
}

void ImageController::setDrawingSize()
{
    if(this->scene != nullptr) {
        int lineSize = static_cast<int>(
                    std::ceil((this->scene->width()+this->scene->height())/500));
        int fontHeight = static_cast<int>(
                    std::ceil((this->scene->width()+this->scene->height())/100));
        this->pen.setWidth(lineSize);
        this->font.setPixelSize(fontHeight);
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
    std::cout << pen.width() << " " << font.pixelSize() << std::endl;
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
    std::cout << pen.width() << " " << font.pixelSize() << std::endl;
    this->drawAnnotations();
}

void ImageController::addPoint(const QPoint& point)
{
    if (this->scene == nullptr) return;

    QPointF p(this->mapToImage(point));
    this->points.append(p);

    this->open(this->currentFileName);
    if (this->points.length() > 2) {
        this->scene->addPolygon(points, this->pen);
    }
    else if (points.length() == 2) {
        this->scene->addLine(QLineF(this->points.at(0), this->points.at(1)), this->pen);
    }
    std::cout << "Got here!" << std::endl;
    std::cout << "Length of this->points: " << this->points.length() << std::endl;
}

void ImageController::cancelShape()
{
    this->points = {};
    this->open(this->currentFileName);
}

QVector<QPointF> ImageController::finishShape(const QString& className)
{
    if(this->points.length() < 3)
        throw DrawingIncomplete();
    QGraphicsTextItem* text = this->scene->addText(className, this->font);
    text->setPos(this->points.first().x(),
                 this->points.first().y());
    QVector<QPointF> ret = this->points;
    this->points = {};
    return ret;
}

void ImageController::setAnnotations(LinkedList<QPair<QString, LinkedList<QPair<int, int>>>> a)
{
    this->annotations = LinkedList<QPair<QString, QVector<QPointF>>>();
    for(size_t i = 0; i < a.length(); i++) {
        QPair<QString, QVector<QPointF>> pair =
                QPair<QString, QVector<QPointF>>(a.at(i).first, QVector<QPointF>());
        for(size_t j = 0; j < a.at(i).second.length(); j++) {
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
