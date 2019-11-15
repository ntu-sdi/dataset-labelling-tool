#ifndef DATASET_LABELING_TOOL_IMAGEBROWSER_H
#define DATASET_LABELING_TOOL_IMAGEBROWSER_H

#include <iostream>
#include <string>
#include <filesystem>
#include <sys/types.h>
#include <dirent.h>
#include <fstream>
#include <unordered_map>
#include <fmt/format.h>

class ImageBrowser {
public:
    void browseFolderForSupportedFiles(std::string folderPath);
    std::unordered_map<std::string,std::string>listImageFiles();

private:
    std::string getFileExtension(std::string& FileName);
    bool isFileSupported(std::string fileName);
    std::string validExtensions[3] = {"jpg","bmp","png"};
    std::unordered_map<std::string, std::string> imageFiles; //hash map, filename,filepath
};

#endif //DATASET_LABELING_TOOL_IMAGEBROWSER_H
