#include "ClassModel.h"

QFileSystemModel ClassModel::fileSystemModel() {}

void ClassModel::removeLine(const std::string& line)
{

}

void ClassModel::save() {}

void ClassModel::browse()
{
    this->currentFilePath = QFileDialog::getOpenFileName(nullptr, "Select Class File",
                                                         "./", "Class files (*.class)").toStdString();
}

void ClassModel::create()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Create New Class File",
                                                    "./data/",
                                                    "Class files (*.class)");
    std::ofstream file(fileName.toStdString());
    file.close();

    this->currentFilePath = fileName.toStdString();
}

void ClassModel::addClass(const std::string& classname)
{
    if (this->currentFilePath.empty()) {
        this->browse();
    }
    if (!this->currentFilePath.empty()) {
        std::ofstream file(this->currentFilePath, std::ios_base::app);
        file << classname << std::endl;
        file.close();
    }
    // If the file path is empty, user chooses class file.
    // If the user chooses a class file, append the class to the file
}

void ClassModel::removeClass(const std::string& classname)
{
    if (this->currentFilePath.empty()) {
        this->browse();
    }
    if (!this->currentFilePath.empty()) {
        std::ofstream file(this->currentFilePath, std::ios_base::app);
        file << classname << std::endl;
        file.close();
    }
    // If the file path is empty, user chooses class file.
    // If the user chooses a class file, append the class to the file

}

void ClassModel::select(const std::string&) {}

std::string ClassModel::getSelected() {}

LinkedList<std::string> ClassModel::getAll() {}
