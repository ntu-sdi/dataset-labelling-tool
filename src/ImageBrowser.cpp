//
// Created by ivica on 14/11/2019.
//
#include "ImageBrowser.h"

void ImageBrowser::browseFolderForSupportedFiles(std::basic_string<char> folderPath)
{

    DIR* dp;
    struct dirent* dirp;

    dp = opendir(folderPath.c_str());
    while ((dirp = readdir(dp)) != nullptr) {
        if (isFileSupported(dirp->d_name)) {
            std::string fileName = dirp->d_name;
            std::string separator;
            #ifdef _WIN32
                        separator = '\\';
            #else
                        separator = '/';
            #endif
            std::string filePath = fmt::format("{0}{1}{2}", folderPath, separator, fileName);
            imageContainer a;
            a.imageName = fileName;
            a.extension = getFileExtension(filePath);
            a.filesize = returnFilesize(fileName);
            loadedImages[filePath] = a;
        }
    }
    closedir(dp);
}

std::string ImageBrowser::getFileExtension(const std::string& fileName)
{
    if (fileName.find_last_of('.') != std::string::npos)
        return fileName.substr(fileName.find_last_of('.') + 1);
    return "";
}

bool ImageBrowser::isFileSupported( const std::string& fileName)
{
    std::string extension = getFileExtension(fileName);
    for ( auto& validExtension : validExtensions) {
        if (extension == validExtension)
            return true;
    }
    return false;
}

long ImageBrowser::returnFilesize( const std::string& a)
{
    struct stat stat_buf;
    int rc = stat(a.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

LinkedList<std::basic_string<char>> ImageBrowser::returnImages()
{
    LinkedList<std::basic_string<char>> a;
    for (auto& loadedImage : loadedImages) {
        a.push(loadedImage.first);
    }
    return a;
}

std::string ImageBrowser::returnImageName(std::basic_string<char> a)
{
    return (loadedImages.at(a).imageName);
}

std::string ImageBrowser::returnImageExtension( std::string& a)
{
    return (loadedImages.at(a).extension);
}

long ImageBrowser::returnImageFilesize( std::string& a)
{
    return (loadedImages.at(a).filesize);
}
