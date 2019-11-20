//
// Created by ivica on 14/11/2019.
//
#include "ImageBrowser.h"

void ImageBrowser::browseFolderForSupportedFiles(const std::string& folderPath){

        DIR *dp;
        struct dirent *dirp;
        try {
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
                    loadedImages[filePath] = a;
                }
            }
            closedir(dp);
        }
        catch (const char *msg) {
            std::cout << msg << std::endl;
        }

}

std::string ImageBrowser::getFileExtension(const std::string& fileName)
{
    if (fileName.find_last_of('.') != std::string::npos)
        return fileName.substr(fileName.find_last_of('.') + 1);
    return "";
}

bool ImageBrowser::isFileSupported(const std::string& fileName)
{
    std::string extension = getFileExtension(fileName);
    for (const auto & validExtension : validExtensions) {
        if (extension == validExtension)
            return true;
    }
    return false;
}

std::vector<std::string> ImageBrowser::returnImages() {
    std::vector<std::string> a;
    for(auto & loadedImage : loadedImages) {
        a.push_back(loadedImage.first);
    }
    return a;
}

std::string ImageBrowser::returnImageName(const std::string& a) {
    return(loadedImages.at(a).imageName);
}

std::string ImageBrowser::returnImageExtension(const std::string& a) {
    return(loadedImages.at(a).extension);
}

long ImageBrowser::returnImageFilesize(const std::string& a) {
    return(loadedImages.at(a).filesize);
}


