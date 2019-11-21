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

long ImageBrowser::getFilesize(const std::string& a)
{
    FILE *p_file = NULL;
    p_file = fopen(a.c_str(),"rb");
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

std::string ImageBrowser::returnImageName(std::string &a)
{
    return (loadedImages.at(a).imageName);
}

std::string ImageBrowser::returnImagePath(std::string &imageName){
    for(auto it:loadedImages){
        if(it.second.imageName == imageName)
            return it.first;
    }
    throw FileNotFoundError();
}

std::string ImageBrowser::returnImageExtension( std::string& a)
{
    return (loadedImages.at(a).extension);
}

long ImageBrowser::returnImageFilesize( std::string& a)
{
    return (loadedImages.at(a).filesize);
}

LinkedList<int> ImageBrowser::returnResolution(const std::string &filename) {
    LinkedList<int> res;
    Mat image;
    image = imread( filename, IMREAD_GRAYSCALE ); // Read the file
    Size size;
    size = image.size();
    res.push(size.width);
    res.push(size.height);
    return res;
}


