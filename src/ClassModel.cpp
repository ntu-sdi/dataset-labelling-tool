#include "ClassModel.h"

QFileSystemModel ClassModel::fileSystemModel() {}

/**
 * Internal method to remove a line from a file.
 * @param line Line to be removed.
 * @param filename File name the line is to be removed from.
 */
void ClassModel::removeLine(const std::string& line, const std::string& filename)
{
    std::ifstream in(this->currentFilePath);
    std::ofstream out("tmp.class");
    if (!in) {
        in.close();
        throw std::fstream::failure("Could not open file");
    }
    std::string readLine;
    while (std::getline(in, readLine)) {
        if (readLine != line)
            out << readLine << std::endl;
    }
    in.close();
    out.close();
    std::remove(filename.c_str());
    std::rename("tmp.class", filename.c_str());
}

void ClassModel::save() {}

/**
 * Opens a file system dialog window and prompts the user to select a class file.
 */
void ClassModel::browse()
{
    this->currentFilePath = QFileDialog::getOpenFileName(nullptr, "Select Class File",
                                                         "./", "Class files (*.class)").toStdString();
}

/**
 * Opens a file system dialog window and prompts the user for a class file name. Creates a class file using this name.
 */
void ClassModel::create()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Create New Class File",
                                                    "./",
                                                    "Class files (*.class)");
    if (!fileName.contains(".class")) fileName.append(".class");
    std::ofstream file(fileName.toStdString()); if (!file) {
        file.close();
        throw std::ofstream::failure("Could not create file");
    }

    file.close();
    this->currentFilePath = fileName.toStdString();
}

/**
 * Adds a line to the current class file. If there is no currently selected class file,
 * the user is prompted by the browse method to select one.
 * @param classname Name of the class to add.
 */
void ClassModel::addClass(std::string classname)
{
    if (this->currentFilePath.empty()) {
        this->browse();
    }
    if (!this->currentFilePath.empty()) {
        if (classname.find_first_not_of(' ') != std::string::npos) {
            size_t startpos = classname.find_first_not_of(" \t");
            if(std::string::npos != startpos) {
                classname = classname.substr(startpos);
            }
            std::ofstream file(this->currentFilePath, std::ios_base::app);
            file << classname << std::endl;
            file.close();
        } else {
            throw std::invalid_argument("Error: class name cannot be empty");
        }
    }
    // If the file path is empty, user chooses class file.
    // If the user chooses a class file, append the class to the file
}

/**
 * Removes a line from the current class file. If there is no currently selected class file,
 * the user is promted by the browse method to select one.
 * @param classname Name of the class to remove.
 */
void ClassModel::removeClass(const std::string& classname)
{
    if (this->currentFilePath.empty()) {
        this->browse();
    }
    if (!this->currentFilePath.empty()) {
        this->removeLine(classname, this->currentFilePath);
    } else {
        throw std::fstream::failure("No file selected");
    }
    // If the file path is empty, user must choose class file.
    // If the user chooses a class file, append the class to the file
}

void ClassModel::select(const std::string&) {}

std::string ClassModel::getSelected() {}

/**
 * Gets a QStringList of all the classes in the current class file. If there is no currrently
 * selected class file, the user is prompted by the browse method to select one.
 * @return
 */
QStringList ClassModel::getAll()
{
    if (this->currentFilePath.empty()) {
        this->browse();
    }
    if (!this->currentFilePath.empty()) {
        std::ifstream file(this->currentFilePath);
        if (!file) {
            file.close();
            throw std::ifstream::failure("Could not open file");
        }
        QStringList ret;
        std::string str;
        while (getline(file, str)) ret.append(QString::fromStdString(str));
        file.close();
        return ret;
    }
    // If the file path is empty, user chooses class file.
    // If the user chooses a class file, append the class to the file
    throw std::ifstream::failure("No file selected");
}

std::string ClassModel::getCurrentFilePath()
{
    return this->currentFilePath;
}
