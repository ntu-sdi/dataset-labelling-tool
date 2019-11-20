#ifndef DATASET_LABELING_TOOL_IMAGEBROWSER_H
#define DATASET_LABELING_TOOL_IMAGEBROWSER_H
#include <iostream>
#include <string>
#include <filesystem>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fstream>
#include <unordered_map>
#include <fmt/format.h>
#include <LinkedList.h>
#include <vector>

class ImageBrowser {
public:

    void browseFolderForSupportedFiles(const std::string& folderPath);
    std::vector<std::string> returnImages();
    std::string returnImageName(const std::string& a);
    std::string returnImageExtension(const std::string& a);
    long returnImageFilesize(const std::string& a);

private:
    struct imageContainer{
        std::string imageName;
        std::string extension;
        long filesize;
    };
    std::unordered_map<std::string, imageContainer> loadedImages;
    std::string validExtensions[3] = {"jpg","bmp","png"};
    static std::string getFileExtension(const std::string& fileName);
    bool isFileSupported(const std::string& fileName);
    long returnFilesize(const std::string &a);

};

#endif //DATASET_LABELING_TOOL_IMAGEBROWSER_H
