#include "AnnotationController.h"

AnnotationController::AnnotationController(const Ui_MainView& ui, const AnnotationModel& model)
{
    this->ui = ui;
    this->model = model;
}

void AnnotationController::browse() {}

void AnnotationController::addPoint(Point) {}

void AnnotationController::finishShape() {}

void AnnotationController::cancelShape() {}
