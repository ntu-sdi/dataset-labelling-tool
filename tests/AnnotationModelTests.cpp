#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include "../include/AnnotationModel.h"
#include <string>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE( ImageModelTests )

    BOOST_AUTO_TEST_CASE(CreatingAnnotationFile){
        //Test that creating annotation file is sucesfull
        AnnotationModel model;
        BOOST_CHECK_NO_THROW(model.create("../testFiles/testmodel.annotation"));
    }

    BOOST_AUTO_TEST_CASE(CreatingAnnotationFile_notFullName){
        //Tests that creating annotation file, without exstension, is sucesfull
        AnnotationModel model;
        BOOST_CHECK_NO_THROW(model.create("../testFiles/testmodel"));
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
        model.create("../testFiles/testmodel.annotation");
        BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(),"../testFiles/testmodel.annotation");
    }

    BOOST_AUTO_TEST_CASE(CheckCurrentlyActiveFile_notFullName){
        //Tests that correct active file path is set in internal represenation of 
        //AnnotationModel when creating a new file whthout proper extension
        AnnotationModel model;
        model.create("../testFiles/testmodel");
        BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(),"../testFiles/testmodel.annotation");
    }

    BOOST_AUTO_TEST_CASE(LoadInnotationFile){
        AnnotationModel model;
        BOOST_CHECK_NO_THROW(model.browse("../testFiles/template.annotation"));
    }

    BOOST_AUTO_TEST_CASE(LoadInvalidAnnotationFile){
        AnnotationModel model;
        BOOST_CHECK_THROW(model.browse(""),std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(LoadNonExistingAnnotationFile){
        AnnotationModel model;
        BOOST_CHECK_THROW(model.browse("../testFiles/templateNOT.annotation"),std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(CheckCurrentlyActiveFile_OnLoad){
        AnnotationModel model;
        model.browse("../testFiles/template.annotation");
        BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(),"../testFiles/template.annotation");
    }


BOOST_AUTO_TEST_SUITE_END()
