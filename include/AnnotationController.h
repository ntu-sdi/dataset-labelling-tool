#pragma once

#include "AnnotationModel.h"
#include "ui_MainView.h"

/**
 * Sub-controller which gets delegated tasks related to annotation files.
 * Communicates directly with the AnnotationModel.
 */
class AnnotationController
{
private:
    Ui_MainView ui;
    AnnotationModel model;
    std::vector<Point> points;
public:
    AnnotationController(const Ui_MainView&, const AnnotationModel&);
    void browse();
    void addPoint(Point);
    void finishShape();
    void cancelShape();
};
