#include "ClassController.h"

ClassController::ClassController(const Ui_MainView& ui, const ClassModel& model)
{
    this->ui = ui;
    this->model = model;
}

void ClassController::browse() {}

void ClassController::create(const std::string&) {}

void ClassController::sortLoaded() {}

void ClassController::add(const std::string&) {}

void ClassController::select(const std::string&) {}

void ClassController::remove(const std::string&) {}

void ClassController::getSelected() {}

