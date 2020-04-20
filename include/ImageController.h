#pragma once

#include <QMessageBox>

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
    QGraphicsScene *scene;
    QList<QPoint> points;
    QString currentFileName;
    int imageHeight;
    int imageWidth;
    void drawLine(QPoint p1, QPoint p2);
    void updateView();
    QPoint mapToImage(QPoint);
public:
    ImageController(Ui_MainView&, ImageModel&);
    void browseFolder();
    void searchLoaded(const QString&);
    void sortLoaded();
    void select(const QString&);
    void open(const QString&);
    void addPoint(const QPoint&);
    void cancelShape();
    QList<QPoint> finishShape(const QString&);
};
