#include "ClassModel.h"

/**
 * Internal method to write a single line to a file.
 * @param filename File name to write to.
 * @param line Line to write.
 */
void ClassModel::writeLineToFile(const QString &filename, const QString &line)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << line << '\n';
        file.close();
    } else {
        file.close();
        throw std::fstream::failure("Could not open file");
    }
}

/**
 * Internal method to write multiple lines to a file.
 * @param filename File name to write to.
 * @param lines Lines to write.
 */
void ClassModel::writeLinesToFile(const QString &filename, const QStringList &lines)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        for (auto i: lines)
            stream << i << '\n';
        file.close();
    } else {
        file.close();
        throw std::fstream::failure("Could not open file");
    }
}

QFileSystemModel ClassModel::fileSystemModel() {}

void ClassModel::save() {}

/**
 * Opens a file system dialog window and prompts the user to select a class file.
 */
void ClassModel::browse()
{
    this->currentFilePath = QFileDialog::getOpenFileName(nullptr, "Select Class File",
                                                         "./", "Class files (*.class)");
    if (!this->currentFilePath.isEmpty()) {
        QFile file(this->currentFilePath);
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream stream(&file);
            while (!stream.atEnd())
                this->classes.append(stream.readLine());
        } else throw std::ifstream::failure("Could not open file");
    }
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
    this->currentFilePath = fileName;
}

/**
 * Adds a line to the current class file. If there is no currently selected class file,
 * the user is prompted by the browse method to select one.
 * @param classname Name of the class to add.
 */
void ClassModel::addClass(QString classname)
{
    if (this->currentFilePath.isEmpty()) {
        this->browse();
    }
    if (this->currentFilePath.isEmpty())
        throw std::invalid_argument("Error: class name cannot be empty");
    else {
        classname = classname.trimmed();
        this->classes.append(classname);
        this->writeLinesToFile(this->currentFilePath, this->classes);
    }
    // If the file path is empty, user chooses class file.
    // If the user chooses a class file, append the class to the file
}

/**
 * Removes a line from the current class file. If there is no currently selected class file,
 * the user is promted by the browse method to select one.
 * @param classname Name of the class to remove.
 */
void ClassModel::removeClass(const QString& classname)
{
    if (this->currentFilePath.isEmpty()) {
        this->browse();
    }
    if (this->currentFilePath.isEmpty())
        throw std::fstream::failure("No file selected");
    else {
        this->classes.removeAll(classname);
        this->writeLinesToFile(this->currentFilePath, this->classes);
    }
    // If the file path is empty, user must choose class file.
    // If the user chooses a class file, append the class to the file
}

void ClassModel::select(const std::string&) {}

std::string ClassModel::getSelected() {}

/**
 * Gets a QStringList of all the classes in the current class file.
 */
QStringList ClassModel::getAll()
{
    if (this->currentFilePath.isEmpty())
        throw std::ifstream::failure("No file selected");
    else return this->classes;
}

QString ClassModel::getCurrentFilePath()
{
    return this->currentFilePath;
}
