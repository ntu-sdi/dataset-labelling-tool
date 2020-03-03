#include <QFileSystemModel>
#include <QFileDialog>

#include "AnnotationModel.h"

/**
 * @brief Prompts user to navigate to a annotation file on the system
 *
 * If entered path is empty, or file could not be oppened, std::invalid_argument
 * exception  is thrown.
 *
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class
 */
void AnnotationModel::browse()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Select Annotation File",
        "./", "Annotation files (*.annotation)");
    if (filePath.isEmpty())
        throw std::invalid_argument("File path cannot be empty");
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        this->currentFilePath = filePath;
        file.close();
    }
    else {
        throw std::invalid_argument("Could not open file");
    }
}

/**
 * @brief Provides a way to enter path to annotation file as a parameter (QString)
 *
 * If entered path is empty, or file could not be oppened, std::invalid_argument
 * exception  is thrown.
 *
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class
 */
void AnnotationModel::browse(const QString& filePath)
{
    if (filePath.isEmpty())
        throw std::invalid_argument("File path cannot be empty");
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        this->currentFilePath = filePath;
        file.close();
    }
    else
        throw std::invalid_argument("Could not open file");
}
/**
 * @brief Prompts the user for a annotation file name. Creates a file using this name and path.
 *
 * If filePath is empty, or file could not be created at wanted location
 * std::invalid argument exception is thrown
 *
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class
 */
void AnnotationModel::create()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Create New Annotation File",
        "./",
        "Annotation files (*.annotation)");
    if (filePath.isEmpty())
        throw std::invalid_argument("File path cannot be empty");
    filePath = filePath.trimmed();
    if (!filePath.contains(".annotation"))
        filePath.append(".annotation");
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite))
        std::invalid_argument("Could not create file");
    file.close();
    this->currentFilePath = filePath;
}

/**
 * @brief Provides a way to create annotation file by providing file path as a parameter (QString)
 *
 * If filePath is empty, or file could not be created at wanted location
 * std::invalid argument exception is thrown
 *
 * Location of opened file is saved to a private currentFilePath attribute
 * in this class
 */
void AnnotationModel::create(const QString& filePath)
{
    if (filePath.isEmpty())
        throw std::invalid_argument("File path cannot be empty");
    QString path = filePath;
    if (!path.contains(".annotation"))
        path.append(".annotation");
    QFile file(path);
    if (!file.open(QIODevice::ReadWrite))
        std::invalid_argument("Could not create file");
    file.close();
    this->currentFilePath = path;
}

void AnnotationModel::add(const QString&, const int, const LinkedList<Shape>&) {}

/**
 * @brief Returns path of currently active annotation file
 * @return Path to a annotation file
 */
QString AnnotationModel::getCurrentFilePath()
{
    return this->currentFilePath;
}
