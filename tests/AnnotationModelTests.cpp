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
using Annotation = QMap<QString, Shape>;

Shape createPoints(int multiplier)
{
    LinkedList<Point> cords;
    for (int i = 1; i < 5; i++) {
        cords.push(qMakePair(100 * i * multiplier, 100 * i * multiplier));
    }
    return cords;
}

bool compareShapes(Shape& a, Shape& b)
{
    if (a.length() != b.length()) {
        return false;
    }
    for (int i = 0; i < a.length(); i++) {
        if (a.at(i) != b.at(i)) {
            return false;
        }
    }
    return true;
}

BOOST_AUTO_TEST_SUITE(AnnotationModelTests)

BOOST_AUTO_TEST_CASE(CreatingAnnotationFile)
{
    //Test that creating annotation file is sucesfull
    AnnotationModel model;
    BOOST_CHECK_NO_THROW(model.create("../testFiles/test.annotation"));
}

BOOST_AUTO_TEST_CASE(CreatingInvalidAnnotationFile)
{
    //Tests that creating annotation file with invalid name will throw exception
    AnnotationModel model;
    BOOST_CHECK_THROW(model.create(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(CheckCurrentlyActiveFile_OnCreate)
{
    //Tests that correct active file path is set in internal represenation of
    //AnnotationModel when creating a new file
    AnnotationModel model;
    model.create("../testFiles/test.annotation");
    BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(), "../testFiles/test.annotation");
}

BOOST_AUTO_TEST_CASE(CheckCurrentlyActiveFile_notFullName)
{
    //Tests that correct active file path is set in internal represenation of
    //AnnotationModel when creating a new file whthout proper extension
    AnnotationModel model;
    model.create("../testFiles/test1");
    BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(), "../testFiles/test1.annotation");
}

BOOST_AUTO_TEST_CASE(LoadAnnotationFile)
{
    //Tests loading of a annotation file, also checks if it is set as active file
    AnnotationModel model;
    BOOST_CHECK_NO_THROW(model.browse("../testFiles/test.annotation"));
    BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(), "../testFiles/test.annotation");
}

BOOST_AUTO_TEST_CASE(LoadInvalidAnnotationFile)
{
    //Tests if invalid argument is thrown if empty file name is inputed
    AnnotationModel model;
    BOOST_CHECK_THROW(model.browse(""), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(LoadAnnotationFile_nonExistingFile)
{
    //Tests if file not found exception is thrown if non existing file is provided as parameter
    AnnotationModel model;
    BOOST_CHECK_THROW(model.browse("../testFiles/nonExisting.annotation"), FileNotFoundError);
}

BOOST_AUTO_TEST_CASE(WriteAnnotationToFile)
{
    //Tests if writing annotation to a annotation file is sucesfull
    //Annotation file path is not provided, instead it is obtained from browsing for a file
    AnnotationModel model;
    model.browse("../testFiles/test.annotation");
    Shape shape = createPoints(2);
    BOOST_CHECK_NO_THROW(model.add("imageExampleTwo.png", "classExampleTwo", shape));
}

BOOST_AUTO_TEST_CASE(WriteAnnotationToFile_ExternalFile)
{
    //Tests if writing annotation to a annotation file is sucesfull
    AnnotationModel model;
    Shape shape = createPoints(1);
    BOOST_CHECK_NO_THROW(model.add("../testFiles/test.annotation", "imageExampleOne.png", "exampleClassOne", shape));
}

BOOST_AUTO_TEST_CASE(WriteAnnotationToFile_nonExistingFile)
{
    //Tests if writting annotation to a non existing file throws file not found error
    AnnotationModel model;
    Shape shape = createPoints(1);
    BOOST_CHECK_THROW(model.add("INVALIDFILE", "imageExampleThree.png", "classExampleTwo", shape), FileNotFoundError);
}

BOOST_AUTO_TEST_CASE(ReadAnnotationFile)
{
    //Tests if reading annotation file return what was written to it
    AnnotationModel model;
    model.browse("../testFiles/test.annotation");
    Annotation readAnnotation = model.get("imageExampleOne.png");
    Shape x = readAnnotation["exampleClassOne"];
    Shape y = createPoints(1);
    BOOST_CHECK(compareShapes(x, y));
}

BOOST_AUTO_TEST_CASE(ReadAnnotationFile_ExternalFile)
{
    //Tests if reading annotation file return what was written to it
    AnnotationModel model;
    Annotation readAnnotation = model.get("imageExampleTwo.png", "../testFiles/test.annotation");
    Shape x = readAnnotation["classExampleTwo"];
    Shape y = createPoints(2);
    BOOST_CHECK(compareShapes(x, y));
}

BOOST_AUTO_TEST_CASE(ReadAnnotationFile_nonAnnotatedImage)
{
    //Tests if reading annotation file return what was written to it
    AnnotationModel model;
    model.browse("../testFiles/test.annotation");
    BOOST_CHECK_THROW(model.get("imageExampleThree.png"), ImageNotAnnotatedYet);
}

BOOST_AUTO_TEST_CASE(ReadAnnotationFile_ExternalFile_nonAnnotatedImage)
{
    //Tests if reading annotation file return what was written to it
    AnnotationModel model;
    BOOST_CHECK_THROW(model.get("imageExampleThree.png", "../testFiles/test.annotation"), ImageNotAnnotatedYet);
}

BOOST_AUTO_TEST_SUITE_END()
