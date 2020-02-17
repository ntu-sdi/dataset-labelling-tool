#include "ImageModel.h"

QFileSystemModel ImageModel::fileSystemModel() {}

void ImageModel::browseFolder() {}

LinkedList<std::string> ImageModel::searchLoaded(const std::string&) {}

std::pair<int, int> ImageModel::getResolution(const std::string&) {}

long ImageModel::getFileSize(const std::string&) {}

LinkedList<std::string> ImageModel::getAll() {}

QImage ImageModel::getImage(const std::string&) {}
