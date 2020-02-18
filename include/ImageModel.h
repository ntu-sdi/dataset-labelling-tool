#pragma once

#include <map>
#include <string>
#include <utility>
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

class ImageModel
{
private:
    QStringList loadedImages;
    QFileSystemModel fileSystemModel();

public:
    void browseFolder();
    LinkedList<std::string> searchLoaded(const std::string&);
    std::pair<int, int> getResolution(const std::string&);
    long getFileSize(const std::string&);
    QStringList getAll();
    QImage getImage(const std::string&);
};
