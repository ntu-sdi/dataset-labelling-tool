#include "ClassController.h"

void ClassController::browse()
{
    this->model.browse();
}

void ClassController::create()
{
    this->model.create();
}

void ClassController::sortLoaded() {}

void ClassController::add(const std::string& classname)
{
   this->model.addClass(classname);
}

void ClassController::select(const std::string&) {}

void ClassController::remove(const std::string&) {}

void ClassController::getSelected() {}

