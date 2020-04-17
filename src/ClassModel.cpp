#include "ClassModel.h"

/**
 * @brief Internal method to write multiple lines to a file.
 *
 * @param filename File name to write to.
 * @param lines Lines to write.
 */
void ClassModel::writeLinesToFile(const QString& fileName,  LinkedList<QString>& lines)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);

        for (size_t i = 0; i < lines.length(); i++) {
            stream << lines.at(i) << '\n';
        }
        file.close();
    }
    else {
        file.close();
        throw std::invalid_argument("Could not open file");
    }
}

void ClassModel::save() {}

/**
 * @brief Opens a file system dialog window and prompts the user to select a class file.
 */
void ClassModel::browse()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Select Class File",
        "./", "Class files (*.class)");
    if (!filePath.isEmpty()) {
        this->browse(filePath);
    }
    else {
        throw std::invalid_argument("Could not open file");
    }
}

void ClassModel::browse(const QString& filepath)
{
    QFile file(filepath);
    if (file.open(QIODevice::ReadOnly)) {
        this->classes.clear();
        QTextStream stream(&file);
        while (!stream.atEnd())
            this->classes.push(stream.readLine());
    }
    else
        throw std::invalid_argument("Could not open file");
    this->currentFilePath = filepath;
}

/**
 * @brief Prompts the user for a class file name. Creates a class file using this name.
 */
void ClassModel::create()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Create New Class File",
        "./",
        "Class files (*.class)");

    if (fileName.isNull())
        throw std::runtime_error("Creating cancelled");
    fileName = fileName.trimmed();
    if (!fileName.contains(".class"))
        fileName.append(".class");
    std::ofstream file(fileName.toStdString());
    if (!file) {
        file.close();
        throw std::invalid_argument("Could not create file");
    }
    file.close();
    this->browse(fileName);
}

void ClassModel::create(const QString& filename)
{
    std::ofstream file(filename.toStdString());
    if (!file) {
        file.close();
        throw std::invalid_argument("Could not create file");
    }
    file.close();
    this->browse(filename);
}

/**
 * @brief Adds a line to the current class file.
 *
 * If there is no currently selected class file,
 * the user is prompted by the browse method to select one.
 *
 * @param classname Name of the class to add.
 */
void ClassModel::addClass(QString className)
{
    className = className.trimmed();
    if (className.isEmpty())
        throw std::invalid_argument("Class name cannot be empty");
    else {
        this->classes.push(className);
        this->writeLinesToFile(this->currentFilePath, this->classes);
    }
}

/**
 * @brief Removes a line from the current class file.
 *
 * If there is no currently selected class file,
 * the user is promted by the browse method to select one.
 *
 * @param classname Name of the class to remove.
 */
void ClassModel::removeClass(const QString& className)
{
    if (this->currentFilePath.isEmpty())
        throw std::invalid_argument("No file selected");
    else {
        this->classes.removeAt(classes.getIndex(className));
        this->writeLinesToFile(this->currentFilePath, this->classes);
    }
}

void ClassModel::select(const std::string&) {}

std::string ClassModel::getSelected()
{
    return "";
}

/**
 * @brief Gets a QStringList of all the classes in the current class file.
 */
LinkedList<QString> ClassModel::getAll()
{
    if (this->currentFilePath.isEmpty()) {
        throw std::invalid_argument("No file selected");
    }
    else {
        return this->classes;
    }
}

/**
 * @brief Returns the currently opened file path.
 */
QString ClassModel::getCurrentFilePath()
{
    return this->currentFilePath;
}
