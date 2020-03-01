#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include "../include/ImageModel.h"
#include <string>
#include <iostream>
#include "ui_MainView.h"
#include<boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE( ImageModelTests )

    BOOST_AUTO_TEST_CASE(OpenEmptyFolder){
        ImageModel i;
        BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/emptyFolder"));
        BOOST_CHECK_EQUAL(i.getAll().size(),0);
    }

    BOOST_AUTO_TEST_CASE(OpenInvalidFolder){
    ImageModel i;
    BOOST_CHECK_THROW(i.browseFolder("../NOTEXISTINGFOLDER"),std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(OpenFolderWith2Images){
        ImageModel i;
        BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/folderWith2Images"));
        BOOST_CHECK_EQUAL(i.getAll().size(),2);
    }

    BOOST_AUTO_TEST_CASE(OpenFolderWith4ImagesAndInvalidFiles){
        ImageModel i;
        BOOST_CHECK_NO_THROW(i.browseFolder("../testFiles/folderWith4ImagesAndInvalidFiles"));
        BOOST_CHECK_EQUAL(i.getAll().size(),4);
    }

    BOOST_AUTO_TEST_CASE(CheckLoadedImageNames){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        BOOST_CHECK_EQUAL(i.getAll().at(0).toStdString(),"Screenshot1.png");
        BOOST_CHECK_EQUAL(i.getAll().at(1).toStdString(),"Screenshot2.png");
    }

    BOOST_AUTO_TEST_CASE(CheckImageFileSize){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        BOOST_CHECK_EQUAL(i.getFileSize("Screenshot1.png"),293383);
    }

    BOOST_AUTO_TEST_CASE(CheckImageFileSize_InvalidImage){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        BOOST_CHECK_THROW(i.getFileSize("Screenshot1__s_.png"),std::runtime_error);
    }


    BOOST_AUTO_TEST_CASE(CheckImageResolution){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        std::pair <int,int> fhdRes(1920,1080);
        std::pair <int,int> res;
        res = i.getResolution("Screenshot1.png");
        BOOST_CHECK_EQUAL(res.first,fhdRes.first);
        BOOST_CHECK_EQUAL(res.second,fhdRes.second);
    }

    BOOST_AUTO_TEST_CASE(CheckImageResolution_InvalidImage){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        std::pair <int,int> fhdRes(1920,1080);
        std::pair <int,int> res;
        BOOST_CHECK_THROW(i.getResolution("Screenshot1___.png"),std::runtime_error);
    }

    BOOST_AUTO_TEST_CASE(GetImage){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        QImage refImg("../testFiles/folderWith2Images/Screenshot1.png");
        QImage loadedImg = i.getImage("Screenshot1.png");
        if(refImg != loadedImg){
            BOOST_FAIL("Images are SAME but NOT matching is thrown");
        }
    }

    BOOST_AUTO_TEST_CASE(GetImage_Equals){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        QImage refImg("../testFiles/folderWith2Images/Screenshot2.png");
        QImage loadedImg = i.getImage("Screenshot1.png");
        if(refImg == loadedImg){
            BOOST_FAIL("Images are NOT SAME but test reported MATCHING");
        }
    }

    BOOST_AUTO_TEST_CASE(GetImage_InvalidImage){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        BOOST_CHECK_THROW(i.getImage("Screenshot1__.png"),std::runtime_error);
    }

BOOST_AUTO_TEST_SUITE_END()
