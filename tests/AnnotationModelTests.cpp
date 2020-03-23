#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include "../include/AnnotationModel.h"
#include "../include/LinkedList.h"
#include "../include/exceptions.h"
#include <QFileSystemModel>
#include <string>
#include <iostream>
#include <boost/test/unit_test.hpp>

using Point = QPair<int, int>;
using Shape = LinkedList<Point>;

#define TESTFILE "../testFiles/test.annotation"
#define TESTFILENOEXSTENSION "../testFiles/test"
#define TESTFILEINVALIDEXSTENSION "../testFiles/testnoexstension"
#define IMAGEONE "exampleImage.png"
#define CLASSONE "car"
#define CLASSTWO "boat"
#define IMAGETWO "exampleImage2.jpg"

LinkedList<Point> createPoints(){
        LinkedList<Point> cords;
        for (int i = 1; i<5;i++){
            cords.push(std::make_pair(100*i,100*i));
        }
        return cords;
}

BOOST_AUTO_TEST_SUITE( AnnotationModelTests )

    BOOST_AUTO_TEST_CASE(CreatingAnnotationFile){
        //Test that creating annotation file is sucesfull
        AnnotationModel model;
        BOOST_CHECK_NO_THROW(model.create(TESTFILE));
    }

    BOOST_AUTO_TEST_CASE(CreatingAnnotationFile_notFullName){
        //Tests that creating annotation file, without exstension, is sucesfull
        AnnotationModel model;
        BOOST_CHECK_NO_THROW(model.create(TESTFILEINVALIDEXSTENSION));
    }

    BOOST_AUTO_TEST_CASE(CreatingInvalidAnnotationFile){
        //Tests that creating annotation file with invalid name will throw exception
        AnnotationModel model;
        BOOST_CHECK_THROW(model.create(""),std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(CheckCurrentlyActiveFile_OnCreate){
        //Tests that correct active file path is set in internal represenation of 
        //AnnotationModel when creating a new file
        AnnotationModel model;
        model.create(TESTFILE);
        BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(),TESTFILE);
    }

    BOOST_AUTO_TEST_CASE(CheckCurrentlyActiveFile_notFullName){
        //Tests that correct active file path is set in internal represenation of 
        //AnnotationModel when creating a new file whthout proper extension
        AnnotationModel model;
        model.create("../testFiles/test");
        BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(),TESTFILE);
    }

    BOOST_AUTO_TEST_CASE(LoadAnnotationFile){
        //Tests loading of a annotation file, also checks if it is set as active file
        AnnotationModel model;
        BOOST_CHECK_NO_THROW(model.browse(TESTFILE));
        BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(),TESTFILE);
    }

    BOOST_AUTO_TEST_CASE(LoadInvalidAnnotationFile){
        //Tests if invalid argument is thrown if empty file name is inputed
        AnnotationModel model;
        BOOST_CHECK_THROW(model.browse(""),std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(LoadAnnotationFile_nonExistingFile){
        //Tests if file not found exception is thrown if non existing file is provided as parameter
        AnnotationModel model;
        BOOST_CHECK_THROW(model.browse("../testFiles/nonExisting.annotation"),FileNotFoundError);
    }

    BOOST_AUTO_TEST_CASE(WriteAnnotationToFile){
        //Tests if writing annotation to a annotation file is sucesfull
        AnnotationModel model;
        LinkedList<QPair<int,int>> cords;
        for (int i = 1; i<5;i++)
            cords.push(std::make_pair(100*i,100*i));
        BOOST_CHECK_NO_THROW(model.add(TESTFILE,IMAGEONE,CLASSONE,cords));
    }

    BOOST_AUTO_TEST_CASE(WriteAnnotationToFile_FromActiveFile){
        //Tests if writing annotation to a annotation file is sucesfull
        //Annotation file path is not provided, instead it is obtained from browsing for a file
        AnnotationModel model;
        model.browse(TESTFILE);
        LinkedList<QPair<int,int>> cords;
        for (int i = 1; i<5;i++)
            cords.push(std::make_pair(100*i,200*i));
        BOOST_CHECK_NO_THROW(model.add(IMAGETWO,CLASSTWO,cords));
    }

    BOOST_AUTO_TEST_CASE(WriteAnnotationToFile_nonExistingFile){
        //Tests if writting annotation to a non existing file throws file not found error
        AnnotationModel model;
        LinkedList<QPair<int,int>> cords;
        for (int i = 1; i<5;i++)
        cords.push(std::make_pair(100*i,100*i));
        BOOST_CHECK_THROW(model.add("INVALIDFILE","imageExample2.png","classExample2",cords),FileNotFoundError);
    }

    BOOST_AUTO_TEST_CASE(ReadAnnotationFile){
        //Tests if reading annotation file return
        AnnotationModel model;
        model.browse(TESTFILE);
        QMap <QString,Shape> annotations =  model.get("imageExample.png");

    }

BOOST_AUTO_TEST_SUITE_END()
