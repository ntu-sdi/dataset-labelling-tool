#include <QFileDialog>
#include <iostream>

#include "ImageModel.h"

/**
 * @brief Opens a system file dialog window and promps the user for an image folder
 */
void ImageModel::browseFolder()
{
    QString directoryPath = QFileDialog::getExistingDirectory(nullptr,
        "Find Folders",
        QDir::currentPath(),
        QFileDialog::ShowDirsOnly);
    if (!directoryPath.isEmpty() && !directoryPath.isNull()) {
        QDir directory = QDir(directoryPath);
        directory.setNameFilters(SUPPORTED_FORMATS);
        QFileInfoList loaded = directory.entryInfoList();
        for (int i = 0; i < loaded.size(); i++) {
            loadedImages[loaded[i].fileName()] = loaded[i];
        }
    }
}

/**
 * @brief Provides a way to input folder path to the system without loading up the GUI
 *
 * @param Path to a folder user wants to browse
 */
void ImageModel::browseFolder(const QString& folderPath)
{
    QDir directory = QDir(folderPath);
    if (!directory.exists()) {
        throw std::runtime_error("Could not open folder");
    }
    directory.setNameFilters(SUPPORTED_FORMATS);
    QFileInfoList loaded = directory.entryInfoList();
    for (int i = 0; i < loaded.size(); i++) {
        loadedImages[loaded[i].fileName()] = loaded[i];
    }
}

/**
 * @brief Provides a way to read resolution of a given image file
 *
 * @param Name of a image file
 * @return std::pair of image resolution, in format <x,y>
 */
std::pair<int, int> ImageModel::getResolution(const QString& fileName)
{
    if (!loadedImages.contains(fileName)) {
        throw std::runtime_error("Could not find file");
    }
    QImage image(loadedImages[fileName].filePath());
    return std::make_pair(image.width(), image.height());
}

/**
 * @brief Provides a way to read file size of a given image file
 *
 * @param Name of a image file
 * @return File size of image, in bytes
 */
long ImageModel::getFileSize(const QString& fileName)
{
    if (!loadedImages.contains(fileName)) {
        throw std::runtime_error("Could not find file");
    }
    return loadedImages[fileName].size();
}

/**
 * @brief Returns all loaded images in the ImageModel.
 *
 * @return QStringList for every loaded image
 */
QStringList ImageModel::getAll()
{
    return loadedImages.keys();
}

/**
 * @brief Provides a way to get an actual image from the system
 *
 * Gets name of the image from ImageController, searches for file path using image file name
 * from internal map. After that it creates Image object and returns it to ImageController
 *
 * @param Name of a image file
 * @return QImage of image provided via image filename
 */
QImage ImageModel::getImage(const QString& filename)
{
    if (!loadedImages.contains(filename)) {
        throw std::runtime_error("Could not find file");
    }
    QImage image(loadedImages[filename].filePath());
    return image;
}
