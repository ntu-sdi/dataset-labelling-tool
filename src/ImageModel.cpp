#include <QFileDialog>

#include "ImageModel.h"

QFileSystemModel ImageModel::fileSystemModel() {}

/**
 * Opens a system file dialog window and promps the user for an image folder,
 * then loads from it any compatible image files.
 */
void ImageModel::browseFolder()
{
    QString directoryPath = QFileDialog::getExistingDirectory(nullptr,
                                                              "Find Folders",
                                                              QDir::currentPath(),
                                                              QFileDialog::ShowDirsOnly);
    QDir directory = QDir(directoryPath);
    directory.setNameFilters(SUPPORTED_FORMATS);
    loadedImages = directory.entryList();
}

LinkedList<std::string> ImageModel::searchLoaded(const std::string&) {}

std::pair<int, int> ImageModel::getResolution(const std::string&) {}

long ImageModel::getFileSize(const std::string&) {}

/**
 * Returns the names of all loaded images in the ImageModel.
 *
 * @return QStringList of the names of all loaded images.
 */
QStringList ImageModel::getAll()
{
    return loadedImages;
}

QImage ImageModel::getImage(const std::string&) {}
