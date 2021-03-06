#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <iostream>

class GraphicsView : public QGraphicsView
{
Q_OBJECT
public:
    GraphicsView(QWidget*);
    void mousePressEvent(QMouseEvent *event);
signals:
    void sendMousePosition(QPoint);
};

#endif
