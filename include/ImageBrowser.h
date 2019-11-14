#ifndef DATASET_LABELING_TOOL_IMAGEBROWSER_H
#define DATASET_LABELING_TOOL_IMAGEBROWSER_H

#include <iostream>
#include <string>
#include <filesystem>
#include <sys/types.h>
#include <dirent.h>
#include <unordered_map>
#include <fmt/format.h>

class ImageBrowser {
public:
    void browseFolderForSuportedFiles(std::string folderPath);
    std::unordered_map<std::string,std::string>listImageFiles();

private:
    std::unordered_map<std::string, std::string> imageFiles; //hash map, filename,filepath
    std::string getFileExtension(std::string& FileName);
    bool isFileSuported(std::string fileName);
    std::string validExtensions[3] = {"jpg","bmp","png"};

};


#endif //DATASET_LABELING_TOOL_IMAGEBROWSER_H
