//
// Created by ivica on 14/11/2019.
//
#include "ImageBrowser.h"
using namespace cv;

void ImageBrowser::browseFolderForSupportedFiles(std::string folderPath)
{

    DIR* dp;
    struct dirent* dirp;
        dp = opendir(folderPath.c_str());
        if(dp == NULL) throw FolderNotFoundError();
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
                a.filesize = getFilesize(filePath);
                loadedImages[filePath] = a;
            }
        }
        closedir(dp);

}

std::string ImageBrowser::getFileExtension(const std::string& filePath)
{
    if (filePath.find_last_of('.') != std::string::npos)
        return filePath.substr(filePath.find_last_of('.') + 1);
    return "";
}

bool ImageBrowser::isFileSupported( const std::string& filePath)
{
    std::string extension = getFileExtension(filePath);
    for ( auto& validExtension : validExtensions) {
        if (extension == validExtension)
            return true;
    }
    return false;
}

long ImageBrowser::getFilesize(const std::string& filePath)
{
    FILE *p_file = NULL;
    p_file = fopen(filePath.c_str(), "rb");
    fseek(p_file,0,SEEK_END);
    long size = ftell(p_file);
    fclose(p_file);
    return size;
}

LinkedList<std::string> ImageBrowser::returnImages()
{
    LinkedList<std::string> a;
    for (auto& loadedImage : loadedImages) {
        a.push(loadedImage.first);
    }
    return a;
}

std::string ImageBrowser::returnImageName(std::string &imagePath)
{
    return (loadedImages.at(imagePath).imageName);
}

std::string ImageBrowser::returnImagePath(std::string &imageName){
    for(auto it:loadedImages){
        if(it.second.imageName == imageName)
            return it.first;
    }
    throw FileNotFoundError();
}

std::string ImageBrowser::returnImageExtension( std::string& imagePath)
{
    return (loadedImages.at(imagePath).extension);
}

long ImageBrowser::returnImageFilesize( std::string& imagePath)
{
    return (loadedImages.at(imagePath).filesize);
}

LinkedList<int> ImageBrowser::returnResolution(const std::string &imagePath) {
    LinkedList<int> res;
    Mat image;
    image = imread(imagePath, 0 ); // Read the file
    Size size;
    size = image.size();
    res.push(size.width);
    res.push(size.height);
    return res;
}


