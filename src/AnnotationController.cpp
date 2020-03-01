#include "AnnotationController.h"

/**
 * @brief Constructs an Annotation Controller, which handles logic related to the annotation files.
 *
 * @param ui The Ui_MainView reference, which is used to update the GUI.
 * @param model The AnnotationModel that the AnnotationController accesses.
 */
AnnotationController::AnnotationController(const Ui_MainView& ui, const AnnotationModel& model)
{
    this->ui = ui;
    this->model = model;
}

void AnnotationController::browse() {}

void AnnotationController::addPoint(Point) {}

void AnnotationController::finishShape() {}

void AnnotationController::cancelShape() {}
