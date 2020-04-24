#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif

#include <string>
#include <iostream>
#include <boost/test/unit_test.hpp>

#include "../include/ImageModel.h"

BOOST_AUTO_TEST_SUITE(ImageModelTests)

// Testing that opening an empty folder results in no images being listed.
BOOST_AUTO_TEST_CASE(OpenEmptyFolder)
{
    ImageModel i;
    BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/emptyFolder"));
    BOOST_CHECK_EQUAL(i.getAll().size(),0);
}

// Testing that trying to open an invalid folder results in an error being thrown.
BOOST_AUTO_TEST_CASE(OpenInvalidFolder)
{
    ImageModel i;
    BOOST_CHECK_THROW(i.browseFolder("../NOTEXISTINGFOLDERNAME"),std::runtime_error);
}

// Testing that opening a directory with two images results in two images being listed.
BOOST_AUTO_TEST_CASE(OpenFolderWith2Images)
{
    ImageModel i;
    BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/folderWith2Images"));
    BOOST_CHECK_EQUAL(i.getAll().size(),2);
}

// Testing that opening a directory with 4 images and other invalid files
// results in only 4 images being listed.
BOOST_AUTO_TEST_CASE(OpenFolderWith4ImagesAndInvalidFiles)
{
    ImageModel i;
    BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/folderWith4ImagesAndInvalidFiles"));
    BOOST_CHECK_EQUAL(i.getAll().size(),4);
}

// Testing that loaded images have correct names.
BOOST_AUTO_TEST_CASE(CheckLoadedImageNames)
{
    ImageModel i;
    i.browseFolder("../testFiles/folderWith2Images");
    BOOST_CHECK_EQUAL(i.getAll().at(0).toStdString(),"Screenshot1.png");
    BOOST_CHECK_EQUAL(i.getAll().at(1).toStdString(),"Screenshot2.png");
}

// Testing that getting the file size of an image is correct.
BOOST_AUTO_TEST_CASE(CheckImageFileSize)
{
    ImageModel i;
    i.browseFolder("../testFiles/folderWith2Images");
    BOOST_CHECK_EQUAL(i.getFileSize("Screenshot1.png"), 293383);
}

// Testing that checking the image size of an invalid image results in an error being thrown.
BOOST_AUTO_TEST_CASE(CheckImageFileSize_InvalidImage)
{
    ImageModel i;
    i.browseFolder("../testFiles/folderWith2Images");
    BOOST_CHECK_THROW(i.getFileSize("Screenshot1__s_.png"), std::runtime_error);
}

// Testing that getting an image's resolution is successful.
BOOST_AUTO_TEST_CASE(CheckImageResolution)
{
    ImageModel i;
    i.browseFolder("../testFiles/folderWith2Images");
    std::pair <int,int> fhdRes(1920, 1080);
    std::pair <int,int> res;
    res = i.getResolution("Screenshot1.png");
    BOOST_CHECK_EQUAL(res.first,fhdRes.first);
    BOOST_CHECK_EQUAL(res.second,fhdRes.second);
}

// Testing that checking the resolution of an invalid image results in an error being thrown.
BOOST_AUTO_TEST_CASE(CheckImageResolution_InvalidImage)
{
    ImageModel i;
    i.browseFolder("../testFiles/folderWith2Images");
    std::pair <int,int> fhdRes(1920, 1080);
    std::pair <int,int> res;
    BOOST_CHECK_THROW(i.getResolution("Screenshot1___.png"), std::runtime_error);
}

// Testing that getting an image is correct on the bit level.
BOOST_AUTO_TEST_CASE(GetImage)
{
    ImageModel i;
    i.browseFolder("../testFiles/folderWith2Images");
    QImage refImg("../testFiles/folderWith2Images/Screenshot1.png");
    QImage loadedImg = i.getImage("Screenshot1.png");
    if(refImg != loadedImg) {
        BOOST_FAIL("Images are SAME but NOT matching is thrown");
    }
}

// Testing two images are different on the bit level.
BOOST_AUTO_TEST_CASE(GetImage_Equals)
{
    ImageModel i;
    i.browseFolder("../testFiles/folderWith2Images");
    QImage refImg("../testFiles/folderWith2Images/Screenshot2.png");
    QImage loadedImg = i.getImage("Screenshot1.png");
    if(refImg == loadedImg) {
        BOOST_FAIL("Images are NOT SAME but test reported MATCHING");
    }
}

// Testing that trying to get an invalid image results in an error being thrown.
BOOST_AUTO_TEST_CASE(GetImage_InvalidImage)
{
    ImageModel i;
    i.browseFolder("../testFiles/folderWith2Images");
    BOOST_CHECK_THROW(i.getImage("Screenshot1__.png"), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
