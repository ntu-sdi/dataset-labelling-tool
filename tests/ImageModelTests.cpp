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

    BOOST_AUTO_TEST_CASE(CheckImageResolution){
        ImageModel i;
        i.browseFolder("../testFiles/folderWith2Images");
        std::pair <int,int> fhdRes(1920,1080);
        std::pair <int,int> res;
        res = i.getResolution("Screenshot1.png");
        BOOST_CHECK_EQUAL(res.first,fhdRes.first);
        BOOST_CHECK_EQUAL(res.second,fhdRes.second);
    }

BOOST_AUTO_TEST_SUITE_END()
