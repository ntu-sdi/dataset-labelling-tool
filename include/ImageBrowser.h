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
#include <vector>
#include <exception>
#include <exceptions.h>
#include <fmt/format.h>
#include <LinkedList.h>

#include <opencv2/core/types.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

class ImageBrowser {
public:

    void browseFolderForSupportedFiles(std::string folderPath);
    LinkedList<std::string> returnImages();
    std::string returnImageName(std::string &a);
    std::string returnImagePath(std::string &imageName);
    std::string returnImageExtension( std::string& a);
    long returnImageFilesize( std::string& a);
    LinkedList<int> returnResolution(const std::string &filename);



private:
    struct imageContainer{
        std::string imageName;
        std::string extension;
        long filesize;
    };

    std::unordered_map<std::string, imageContainer> loadedImages;
    std::string validExtensions[13] = {"jpg","bmp","png","tiff","tif","pbm", "pgm", "ppm","sr", "ras","jp2","jpg", "jpe"};
    static std::string getFileExtension(const std::string& fileName);
    bool isFileSupported( const std::string& fileName);
    long getFilesize(const std::string &a);

};

#endif //DATASET_LABELING_TOOL_IMAGEBROWSER_H
