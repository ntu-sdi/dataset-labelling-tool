#pragma once

#include <string>
#include <QFileSystemModel>
#include <QImage>

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
public:
    void browseFolder();
    void browseFolder(const QString&);
    std::pair<int, int> getResolution(const QString&);
    long getFileSize(const QString&);
    QStringList getAll();
    QMap <QString,QFileInfo> getAllWithDetails();
    QImage getImage(const QString&);
};
