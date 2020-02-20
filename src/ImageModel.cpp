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
    if(!directoryPath.isEmpty()&& !directoryPath.isNull()){
        QDir directory = QDir(directoryPath);
        directory.setNameFilters(SUPPORTED_FORMATS);
        QFileInfoList loaded = directory.entryInfoList();

        for (int i =0; i< loaded.size();i ++){
              loadedImages[loaded[i].fileName()] = loaded[i];
        }
    }
}

LinkedList<std::string> ImageModel::searchLoaded(const QString&) {}

std::pair<int, int> ImageModel::getResolution(const QString&) {}

long ImageModel::getFileSize(const QString&) {}

/**
 * Returns the names of all loaded images in the ImageModel.
 *
 * @return QStringList of the names of all loaded images.
 */
QStringList ImageModel::getAll()
{
    return loadedImages.keys();
}

/**
 * Gets name of the image from ImageController, searches for file path usin image file name
 * from internal map. After that it creates Image object and returns it to ImageController
 * @param filename
 * @return QPixmap of image provided via image filename
 */
QPixmap ImageModel::getImage(const QString& filename) {
    QPixmap img(loadedImages[filename].filePath());
    return img;
}
