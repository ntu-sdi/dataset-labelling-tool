#ifndef DATASET_LABELING_TOOL_IMAGEBROWSER_H
#define DATASET_LABELING_TOOL_IMAGEBROWSER_H

#include <iostream>
#include <string>
#include <filesystem>
#include <sys/types.h>
#include <dirent.h>
#include <unordered_map>

class ImageBrowser {
public:
    void browseFolderForSuportedFiles(std::string folderPath);
    std::string validExtensions[3] = {".jpg",".bmp",".png"};

private:
    std::unordered_map<std::string, std::string> imageFiles;
    std::string getFileExtension(std::string& FileName);
    bool isFileSuported(std::string fileName);

};


#endif //DATASET_LABELING_TOOL_IMAGEBROWSER_H
