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
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ImageBrowserTests)

   BOOST_AUTO_TEST_CASE(OpeningInvalidFolder)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestDataINVALID"; //invalid path on purpose
        BOOST_CHECK_THROW(browser.browseFolderForSupportedFiles(path), FolderNotFoundError);
    }
    BOOST_AUTO_TEST_CASE(OpeningValidFolder)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        browser.browseFolderForSupportedFiles(path);
        BOOST_CHECK_EQUAL(browser.returnImages().length(), 2);
    }
    BOOST_AUTO_TEST_CASE(OpeningEmptyFolder)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestData/emptyfolder";
        browser.browseFolderForSupportedFiles(path);
        BOOST_CHECK_EQUAL(browser.returnImages().length(), 0);
    }

    BOOST_AUTO_TEST_CASE(CheckReturningImageNames)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        browser.browseFolderForSupportedFiles(path);
        LinkedList<std::string> imgs = browser.returnImages();
        LinkedList<std::string> imgNames;
        imgNames.push("img1.jpg");
        imgNames.push("img2.bmp");
        for (int i = 0; i < imgs.length(); i++) {
            std::string imgName = imgs.at(i);
            BOOST_CHECK_EQUAL(browser.returnImageName(imgName), imgNames.at(i));
        }
    }

    BOOST_AUTO_TEST_CASE(CheckReturningImagesPaths)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        browser.browseFolderForSupportedFiles(path);
        LinkedList<std::string> files;
		#if defined (WIN32)
		files.push("../../test/folderTestData\\img1.jpg");
		files.push("../../test/folderTestData\\img2.bmp");
		#else
		files.push("../../test/folderTestData/img1.jpg");
		files.push("../../test/folderTestData/img2.bmp");
		#endif
        
        BOOST_CHECK_EQUAL(browser.returnImages().length(), files.length());
        for (int i = 0; i < files.length(); i++)
            BOOST_CHECK_EQUAL(files.at(i), browser.returnImages().at(i));
    }

    BOOST_AUTO_TEST_CASE(CheckReturningImagesPaths_FromNames)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        browser.browseFolderForSupportedFiles(path);
        LinkedList<std::string> imgs = browser.returnImages();
        LinkedList<std::string> imgNames;
        imgNames.push("img1.jpg");
        imgNames.push("img2.bmp");
        for (int i = 0; i < imgs.length(); i++) {
            std::string imagePathObtainedFromClass = imgs.at(i);
            std::string imageName = imgNames.at(i);
            std::string imagePathObtainedFromClassViaImageName(browser.returnImagePath(imageName));
            BOOST_CHECK_EQUAL(imagePathObtainedFromClass, imagePathObtainedFromClassViaImageName);
        }
    }
    BOOST_AUTO_TEST_CASE(CheckReturningImageExtension)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        browser.browseFolderForSupportedFiles(path);
        LinkedList<std::string> imgs = browser.returnImages();
        LinkedList<std::string> imgsExtensions;
        imgsExtensions.push("jpg");
        imgsExtensions.push("bmp");
        for (int i = 0; i < imgs.length(); i++) {
            std::string imagePath = imgs.at(i);
            std::string extensionObtainedFromClass = browser.returnImageExtension(imagePath);
            std::string expectedExtension = imgsExtensions.at(i);
            BOOST_CHECK_EQUAL(extensionObtainedFromClass, expectedExtension);
        }
    }

    BOOST_AUTO_TEST_CASE(CheckReturningImageFileSize)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        browser.browseFolderForSupportedFiles(path);
        LinkedList<std::string> imgs = browser.returnImages();
        LinkedList<int> img_sizes;
        img_sizes.push(80843);
        img_sizes.push(4264316);
        for (int i = 0; i < imgs.length(); i++) {
            std::string imgPath = imgs.at(i);
            BOOST_CHECK_EQUAL(browser.returnImageFilesize(imgPath), img_sizes.at(i));
        }
    }
    BOOST_AUTO_TEST_CASE(CheckReturningImageResoultion)
    {
        ImageBrowser browser;
        std::string path = "../../test/folderTestData";
        browser.browseFolderForSupportedFiles(path);
        LinkedList<std::string> imgs = browser.returnImages();
        LinkedList<int> imgsResolutions;
        imgsResolutions.insert(0, 1000);
        imgsResolutions.insert(1, 833);

        std::string imgPath = imgs.at(0);
        int res_x = browser.returnResolution(imgPath).at(0);
        int res_y = browser.returnResolution(imgPath).at(1);
        int x = imgsResolutions.at(0);
        int y = imgsResolutions.at(1);
        BOOST_CHECK_EQUAL(res_x, x);
        BOOST_CHECK_EQUAL(res_y, y);
    }
	

BOOST_AUTO_TEST_SUITE_END()
