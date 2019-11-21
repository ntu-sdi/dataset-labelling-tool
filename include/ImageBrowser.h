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

class ImageBrowser {
public:
    void browseFolderForSupportedFiles(std::string folderPath); //loads compatible files from folder to internal storage
    LinkedList<std::string> returnImages(); //returns paths to files stored via function above
    std::string returnImageName(std::string& imagePath); //returns image name from image path
    std::string returnImagePath(std::string& imageName); //returns full path to image from image name
    std::string returnImageExtension(std::string& imagePath); //returns file extension of the image
    long returnImageFilesize(std::string& imagePath); //returns filesize of image in bytes
    LinkedList<int> returnResolution(const std::string& imagePath); //returns resolution of the image in linked list format: x,y

private:
    struct imageContainer {
        std::string imageName;
        std::string extension;
        long filesize;
    }; //container for storing all required data of compatible images

    std::unordered_map<std::string, imageContainer> loadedImages; //hash map for storing compatible files
    std::string validExtensions[13] = { "jpg", "bmp", "png", "tiff", "tif", "pbm", "pgm", "ppm", "sr", "ras", "jp2", "jpg", "jpe" }; //compatible image types
    std::string getFileExtension(const std::string& filePath);
    bool isFileSupported(const std::string& filePath);
    long getFilesize(const std::string& filePath);
};

#endif //DATASET_LABELING_TOOL_IMAGEBROWSER_H
