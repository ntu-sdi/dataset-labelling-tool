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
            std::string separator;
            #ifdef _WIN32
                        separator ='\\';
            #else
                        separator= '/';
            #endif
            std::string filePath = fmt::format("{0}{1}{2}",folderPath,separator,fileName);
            imageFiles.insert({fileName,filePath});
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
    for (int i = 0; i<sizeof(validExtensions)/sizeof(validExtensions[0]);i++){
        if(extension == validExtensions[i]) return true;
    }
    return false;
}

std::unordered_map<std::string, std::string> ImageBrowser::listImageFiles() {
    return imageFiles;
}
