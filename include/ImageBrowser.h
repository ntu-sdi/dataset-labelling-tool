//
// Created by ivica on 14/11/2019.
//

#ifndef DATASET_LABELING_TOOL_IMAGEBROWSER_H
#define DATASET_LABELING_TOOL_IMAGEBROWSER_H

#include <iostream>
#include <string>
#include <unordered_map>

class ImageBrowser {
private:
    std::unordered_map<std::string, std::string> imageFiles;
    std::string validImageFormats[3] = {".jpg",".png",".bmp"};
public:
};


#endif //DATASET_LABELING_TOOL_IMAGEBROWSER_H
