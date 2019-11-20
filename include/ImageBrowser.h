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

    void browseFolderForSupportedFiles(std::basic_string<char> folderPath);
    LinkedList<std::basic_string<char>> returnImages();
    std::string returnImageName(std::basic_string<char> a);
    std::string returnImageExtension( std::string& a);
    long returnImageFilesize( std::string& a);

private:
    struct imageContainer{
        std::string imageName;
        std::string extension;
        long filesize;
    };
    std::unordered_map<std::string, imageContainer> loadedImages;
    std::string validExtensions[3] = {"jpg","bmp","png"};
    static std::string getFileExtension(const std::string& fileName);
    bool isFileSupported( const std::string& fileName);
    long returnFilesize( const std::string &a);

};

#endif //DATASET_LABELING_TOOL_IMAGEBROWSER_H
