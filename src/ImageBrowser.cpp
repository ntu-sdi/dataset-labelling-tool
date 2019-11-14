//
// Created by ivica on 14/11/2019.
//

#include "ImageBrowser.h"

void ImageBrowser::browseFolderForSupportedFiles(std::string folderPath) {
    DIR *dp;
    struct dirent *dirp;
    dp  = opendir(folderPath.c_str());
    while ((dirp = readdir(dp)) != NULL) {
        if(isFileSupported(dirp->d_name)){
            std::string fileName = dirp->d_name;
            std::string separator;
            #ifdef _WIN32
                        separator ='\\';
            #else
                        separator= '/';
            #endif
            std::string filePath = fmt::format("{0}{1}{2}",folderPath,separator,fileName);
            imageFiles.insert({dirp->d_name,filePath});
        }
    }
    closedir(dp);
}

std::string ImageBrowser::getFileExtension(std::string &FileName) {
    if(FileName.find_last_of(".") != std::string::npos)
        return FileName.substr(FileName.find_last_of(".")+1);
    return "";
}

unsigned long ImageBrowser::getFileSize(std::string &filename) {
    return 1;
}

bool ImageBrowser::isFileSupported(std::string fileName) {
    std::string extension = getFileExtension(fileName);
    for (int i = 0; i<sizeof(validExtensions)/sizeof(validExtensions[0]);i++){
        if(extension == validExtensions[i]) return true;
    }
    return false;
}

std::unordered_map<std::string, std::string> ImageBrowser::listImageFiles() {
    return imageFiles;
}


