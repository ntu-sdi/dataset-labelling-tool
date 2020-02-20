#include "ClassController.h"

ClassController::ClassController(const Ui_MainView& ui, const ClassModel& model)
{
    this->ui = ui;
    this->model = model;
}

void ClassController::browse() {}

void ClassController::create(const QString&) {}

void ClassController::sortLoaded() {}

void ClassController::add(const QString&) {}

void ClassController::select(const QString&) {}

void ClassController::remove(const QString&) {}

void ClassController::getSelected() {}

