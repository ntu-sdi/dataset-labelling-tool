#include <QMessageBox>
#include "AnnotationController.h"
#include "exceptions.h"

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

/**
 * @brief Delegates a request to create a new annotation file to model and updates label in the UI accordingly.
 */
void AnnotationController::create()
{
    try {
        model.create();
        ui.AnnotationFileLabel->setText(model.getCurrentFilePath());
    }
    catch (std::invalid_argument& e) {
        QMessageBox::warning(this->ui.ClassesList, "Error", e.what(), QMessageBox::Ok);
    }
    catch (OperationCanceled e) {
        //QMessageBox::warning(this->ui.ClassesList, "Error", e.what(), QMessageBox::Ok);
    }
}

/**
 * @brief Browses for an annotation file and updates label in the UI accordingly.
 */
void AnnotationController::browse()
{
    try {
        model.browse();
        ui.AnnotationFileLabel->setText(model.getCurrentFilePath());
    }
    catch (std::invalid_argument& e) {
        QMessageBox::warning(this->ui.ClassesList, "Error", e.what(), QMessageBox::Ok);
    }
    catch (OperationCanceled e) {
        //QMessageBox::warning(this->ui.ClassesList, "Error", e.what(), QMessageBox::Ok);
    }
}

void AnnotationController::addPoint(Point) {}

void AnnotationController::finishShape() {}

void AnnotationController::cancelShape() {}
