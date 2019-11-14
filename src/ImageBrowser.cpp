//
// Created by ivica on 14/11/2019.
//

#include "ImageBrowser.h"

void ImageBrowser::browseFolderForSuportedFiles(std::string folderPath) {
    DIR *dp;
    struct dirent *dirp;
    dp  = opendir(folderPath.c_str());
    while ((dirp = readdir(dp)) != NULL) {
        std::string fileName(dirp->d_name);
        if(isFileSuported(fileName)){
            std::cout<<fileName<<std::endl;
        }
    }
    closedir(dp);
}

std::string ImageBrowser::getFileExtension(std::string &FileName) {
    if(FileName.find_last_of(".") != std::string::npos)
        return FileName.substr(FileName.find_last_of(".")+1);
    return "";
}

bool ImageBrowser::isFileSuported(std::string fileName) {
    std::string extension = getFileExtension(fileName);
    std::cout<<validExtensions[1]<<std::endl;
    return false;
}
