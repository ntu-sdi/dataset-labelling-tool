#define BOOST_TEST_DYN_LINK
//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "ImageBrowserTests"
//VERY IMPORTANT - include this last
#include <unordered_map>
#include "../include/ImageBrowser.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(SearchFolderForFiles)
{
    ImageBrowser* imageBrowser = new ImageBrowser;
    imageBrowser->browseFolderForSupportedFiles("../../test/folderTestData");
    std::unordered_map<std::string,std::string>b = imageBrowser->listImageFiles();
    std::unordered_map<std::string,std::string>a = {{"img2.bmp","../../test/folderTestData/img2.bmp"},{"img1.jpg","../../test/folderTestData/img1.jpg"}};
    BOOST_TEST(a == b);
}