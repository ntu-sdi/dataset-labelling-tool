#include <QFileDialog>

#include "ImageModel.h"

QFileSystemModel ImageModel::fileSystemModel() {}

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

QStringList ImageModel::getAll()
{
    return loadedImages;
}

QImage ImageModel::getImage(const std::string&) {}
