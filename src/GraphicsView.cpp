#include "../include/GraphicsView.h"

GraphicsView::GraphicsView(QWidget* parent): QGraphicsView(parent) {}

void GraphicsView::mousePressEvent(QMouseEvent* event)
{
    QPoint point = event->pos();
    emit sendMousePosition(point);
}
