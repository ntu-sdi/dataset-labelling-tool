#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include "../include/ImageModel.h"
#include <string>
#include <iostream>
#include<boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE( ImageModelTests )

    BOOST_AUTO_TEST_CASE(OpenEmptyFolder){
        // Testing that opening an empty folder results in no images being listed.
        ImageModel i;
        BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/emptyFolder"));
        BOOST_CHECK_EQUAL(i.getAll().size(),0);
    }

    BOOST_AUTO_TEST_CASE(OpenInvalidFolder){
        // Testing that trying to open an invalid folder results in an error being thrown.
        ImageModel i;
        BOOST_CHECK_THROW(i.browseFolder("../NOTEXISTINGFOLDERNAME"),std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(OpenFolderWith2Images){
        // Testing that opening a directory with two images results in two images being listed.
        ImageModel i;
        BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/folderWith2Images"));
        BOOST_CHECK_EQUAL(i.getAll().size(),2);
    }

    BOOST_AUTO_TEST_CASE(OpenFolderWith4ImagesAndInvalidFiles){
        // Testing that opening a directory with 4 images and other invalid files 
        // results in only 4 images being listed.
        ImageModel i;
        BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/folderWith4ImagesAndInvalidFiles"));
        BOOST_CHECK_EQUAL(i.getAll().size(),4);
    }

    BOOST_AUTO_TEST_CASE(CheckLoadedImageNames){
        // Testing that loaded images have correct names.
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        BOOST_CHECK_EQUAL(i.getAll().at(0).toStdString(),"Screenshot1.png");
        BOOST_CHECK_EQUAL(i.getAll().at(1).toStdString(),"Screenshot2.png");
    }

    BOOST_AUTO_TEST_CASE(CheckImageFileSize){
        // Testing that getting the file size of an image is correct.
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        BOOST_CHECK_EQUAL(i.getFileSize("Screenshot1.png"),293383);
    }

    BOOST_AUTO_TEST_CASE(CheckImageFileSize_InvalidImage){
        // Testing that checking the image size of an invalid image results in an error being thrown.
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        BOOST_CHECK_THROW(i.getFileSize("Screenshot1__s_.png"),std::runtime_error);
    }


    BOOST_AUTO_TEST_CASE(CheckImageResolution){
        // Testing that getting an image's resolution is successful.
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        std::pair <int,int> fhdRes(1920,1080);
        std::pair <int,int> res;
        res = i.getResolution("Screenshot1.png");
        BOOST_CHECK_EQUAL(res.first,fhdRes.first);
        BOOST_CHECK_EQUAL(res.second,fhdRes.second);
    }

    BOOST_AUTO_TEST_CASE(CheckImageResolution_InvalidImage){
        // Testing that checking the resolution of an invalid image results in an error being thrown.
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        std::pair <int,int> fhdRes(1920,1080);
        std::pair <int,int> res;
        BOOST_CHECK_THROW(i.getResolution("Screenshot1___.png"),std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(GetImage){
        // Testing that getting an image is correct on the bit level.
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        QImage refImg("../testFiles/folderWith2Images/Screenshot1.png");
        QImage loadedImg = i.getImage("Screenshot1.png");
        if(refImg != loadedImg){
            BOOST_FAIL("Images are SAME but NOT matching is thrown");
        }
    }

    BOOST_AUTO_TEST_CASE(GetImage_Equals){
        // Testing two images are different on the bit level.
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        QImage refImg("../testFiles/folderWith2Images/Screenshot2.png");
        QImage loadedImg = i.getImage("Screenshot1.png");
        if(refImg == loadedImg){
            BOOST_FAIL("Images are NOT SAME but test reported MATCHING");
        }
    }

    BOOST_AUTO_TEST_CASE(GetImage_InvalidImage){
        // Testing that trying to get an invalid image results in an error being thrown.
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        BOOST_CHECK_THROW(i.getImage("Screenshot1__.png"),std::runtime_error);
    }

BOOST_AUTO_TEST_SUITE_END()
