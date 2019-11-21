//
// Created by ivica on 20/11/2019.
//
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include "ImageBrowser.h"
#include <LinkedList.h>
#include <exceptions.h>
#include <string>
#include<boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( ImageBrowserTests )
    BOOST_AUTO_TEST_CASE(OpeningInvalidFolder){
        ImageBrowser browser;
        std::string path = "../../test/folderTestDataINVALID"; //invalid path on purpose
        BOOST_CHECK_THROW(browser.browseFolderForSupportedFiles(path),FolderNotFoundError);
    }
    BOOST_AUTO_TEST_CASE(OpeningValidFolder){
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        BOOST_CHECK_NO_THROW(browser.browseFolderForSupportedFiles(path));
}
    BOOST_AUTO_TEST_CASE(LoadingAndReturningImages){
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        browser.browseFolderForSupportedFiles(path);
        LinkedList<std::string> files;
        files.push("../../test/folderTestData/img1.jpg");
        files.push("../../test/folderTestData/img2.bmp");
        BOOST_CHECK_EQUAL(browser.returnImages().length(),files.length());
        for (int i = 0; i<files.length();i++)
            BOOST_CHECK_EQUAL(files.at(i),browser.returnImages().at(i));
}

BOOST_AUTO_TEST_SUITE_END()
