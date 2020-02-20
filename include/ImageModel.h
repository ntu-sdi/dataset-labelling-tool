#pragma once

#include <map>
#include <string>
#include <utility>
#include <QFileSystemModel>
#include <QImage>
#include <QPixmap>

#include "LinkedList.h"

const QStringList SUPPORTED_FORMATS = {
    "*.jpg",
    "*.bmp",
    "*.png",
    "*.tiff",
    "*.tif",
    "*.pbm",
    "*.pgm",
    "*.ppm",
    "*.sr",
    "*.ras",
    "*.jp2",
    "*.jpeg"
};

/**
 * Model, which is responsible for file handling of images. Maintains an internal list of the
 * currently loaded images.
 */
class ImageModel
{
private:
    QMap <QString,QFileInfo> loadedImages;
    QFileSystemModel fileSystemModel();

public:
    void browseFolder();
    LinkedList<std::string> searchLoaded(const QString&);
    std::pair<int, int> getResolution(const QString&);
    long getFileSize(const QString&);
    QStringList getAll();
    QPixmap getImage(const QString&);
};
