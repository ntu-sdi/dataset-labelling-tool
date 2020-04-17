#include "ClassController.h"

/**
 * @brief Constructs a ClassController which handles logic related to the class files.
 *
 * @param ui The Ui_MainView reference, which is used to update the GUI.
 * @param model The ClassModel that the ClassController accesses.
 */
ClassController::ClassController(const Ui_MainView& ui, const ClassModel& model)
{
    this->ui = ui;
    this->model = model;
}

/**
 * @brief Clears the list of classes in the GUI and refills them from the currently loaded classes.
 */
void ClassController::updateView()
{
    LinkedList<QString> classes = this->model.getAll();
    this->ui.ClassesList->clearSelection();
    this->ui.ClassesList->clearFocus();
    this->ui.ClassesList->clear();
    if(!classes.isEmpty()){
        for(size_t i = 0; i<classes.length();i++){
            this->ui.ClassesList->addItem(classes.at(i));
            //std::cout<<"Reading class: "<<classes.at(i).toStdString();
        }
    }
    QString currentFilePath = this->model.getCurrentFilePath();
    if(!currentFilePath.isEmpty()) {
        this->ui.ClassFileLabel->setText(currentFilePath);
    }
}

/**
 * @brief Browses for a new class file, then updates the view to reflect that.
 */
void ClassController::browse()
{
    this->model.browse();
    try {
        this->updateView();
    }
    catch (std::invalid_argument& e) {
        QMessageBox::warning(this->ui.ClassesList, "Error", e.what(), QMessageBox::Ok);
    }
}

/**
 * @brief Creates a new class file, and updates the view to reflect that.
 */
void ClassController::create()
{
    try {
        this->model.create();
        this->updateView();
    }
    catch (std::invalid_argument& e) {
        QMessageBox::warning(this->ui.ClassesList, "Error", e.what(), QMessageBox::Ok);
    }
    catch (std::runtime_error) {
    }
}

void ClassController::sortLoaded() {}

/**
 * @brief Adds a new class, and updates the view to reflect that.
 *
 * @param classname Name of the class to add.
 */
void ClassController::add(const QString& className)
{
    try {
        this->model.addClass(className);
        this->updateView();
    }
    catch (std::invalid_argument& e) {
        QMessageBox::warning(this->ui.ClassesList, "Error", e.what(), QMessageBox::Ok);
    }
}

void ClassController::select(const std::string&) {}

/**
 * @brief Removes a class, and updates the view to reflect that.
 *
 * @param classname Name of the class to remove.
 */
void ClassController::remove(const QString& className)
{
    try {
        this->model.removeClass(className);
        this->updateView();
    }
    catch (std::invalid_argument& e) {
        QMessageBox::warning(this->ui.ClassesList, "Error", e.what(), QMessageBox::Ok);
    }
}

void ClassController::getSelected() {}
