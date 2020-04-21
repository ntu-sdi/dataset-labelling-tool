#pragma once

#include <cmath>
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
    QVector<QPointF> points;
    QString currentFileName;
    QPen pen;
    QFont font;
    int imageHeight;
    int imageWidth;
    LinkedList<QPair<QString, QVector<QPointF>>> annotations;
    void updateView();
    QPoint mapToImage(QPoint);
    void drawAnnotations();
    void setDrawingSize();
public:
    ImageController(Ui_MainView&, ImageModel&);
    void browseFolder();
    void searchLoaded(const QString&);
    void sortLoaded();
    void select(const QString&);
    void open(const QString&);
    void addPoint(const QPoint&);
    void cancelShape();
    QVector<QPointF> finishShape(const QString&);
    void setAnnotations(LinkedList<QPair<QString, LinkedList<QPair<int, int>>>>);
    QString getCurrentFileName();
};
