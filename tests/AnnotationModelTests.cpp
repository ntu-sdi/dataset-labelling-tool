#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif

#include <QFileSystemModel>
#include <string>
#include <iostream>
#include <boost/test/unit_test.hpp>

#include "../include/AnnotationModel.h"
#include "../include/LinkedList.h"
#include "../include/exceptions.h"

using Point = QPair<int, int>;
using Shape = LinkedList<Point>;
using Annotation = QMap<QString, Shape>;

/**
 * @brief Creates a list of points for testing.
 *
 * @param multiplier
 *
 * @return Shape
 */
Shape createPoints(int multiplier)
{
    LinkedList<Point> cords;
    for(int i = 1; i < 5; i++) {
        cords.push(qMakePair(100 * i * multiplier, 100 * i * multiplier));
    }
    return cords;
}

/**
 * @brief Compare two shapes.
 *
 * @param a
 * @param b
 *
 * @return bool
 */
bool compareShapes(Shape& a, Shape& b)
{
    if(a.length() != b.length()) {
        return false;
    }
    for(int i = 0; i < a.length(); i++) {
        if(a.at(i) != b.at(i)) {
            return false;
        }
    }
    return true;
}

BOOST_AUTO_TEST_SUITE(AnnotationModelTests)

// Test that creating annotation file is successful.
BOOST_AUTO_TEST_CASE(CreatingAnnotationFile)
{
    AnnotationModel model;
    BOOST_CHECK_NO_THROW(model.create("../testFiles/test.annotation"));
}

// Tests that creating annotation file with invalid name will throw exception.
BOOST_AUTO_TEST_CASE(CreatingInvalidAnnotationFile)
{
    AnnotationModel model;
    BOOST_CHECK_THROW(model.create(""), std::invalid_argument);
}

// Tests that correct active file path is set in internal represenation of
// AnnotationModel when creating a new file.
BOOST_AUTO_TEST_CASE(CheckCurrentlyActiveFile_OnCreate)
{
    AnnotationModel model;
    model.create("../testFiles/test.annotation");
    BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(), "../testFiles/test.annotation");
}

// Tests that correct active file path is set in internal represenation of
// AnnotationModel when creating a new file whthout proper extension.
BOOST_AUTO_TEST_CASE(CheckCurrentlyActiveFile_notFullName)
{
    AnnotationModel model;
    model.create("../testFiles/test1");
    BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(), "../testFiles/test1.annotation");
}

// Tests loading of a annotation file, also checks if it is set as active file.
BOOST_AUTO_TEST_CASE(LoadAnnotationFile)
{
    AnnotationModel model;
    BOOST_CHECK_NO_THROW(model.browse("../testFiles/test.annotation"));
    BOOST_CHECK_EQUAL(model.getCurrentFilePath().toStdString(), "../testFiles/test.annotation");
}

// Tests if invalid argument is thrown if empty file name is inputed.
BOOST_AUTO_TEST_CASE(LoadInvalidAnnotationFile)
{
    AnnotationModel model;
    BOOST_CHECK_THROW(model.browse(""), std::invalid_argument);
}

// Tests if invalid argument is thrown if empty file name is inputed.
BOOST_AUTO_TEST_CASE(LoadAnnotationFile_nonExistingFile)
{
    AnnotationModel model;
    BOOST_CHECK_THROW(model.browse("../testFiles/nonExisting.annotation"), FileNotFoundError);
}

// Tests if writing annotation to a annotation file is successful
// Annotation file path is not provided, instead it is obtained from browsing for a file.
BOOST_AUTO_TEST_CASE(WriteAnnotationToFile)
{
    AnnotationModel model;
    model.browse("../testFiles/test.annotation");
    Shape shape = createPoints(1);
    BOOST_CHECK_NO_THROW(model.add("imageExampleOne.png", "classExampleTwo", shape));
    BOOST_CHECK_NO_THROW(model.save());
}

// Tests if reading annotation file return what was written to it.
BOOST_AUTO_TEST_CASE(ReadAnnotationFile)
{
    AnnotationModel model;
    model.browse("../testFiles/test.annotation");
    LinkedList<QPair<QString, Shape>> readAnnotation = model.get("imageExampleOne.png");
    Shape x = readAnnotation.at(0).second;
    Shape y = createPoints(1);
    BOOST_CHECK(compareShapes(x, y));
}

// Tests if reading annotation file return what was written to it.
BOOST_AUTO_TEST_CASE(ReadAnnotationFile_nonAnnotatedImage)
{
    AnnotationModel model;
    model.browse("../testFiles/test.annotation");
    BOOST_CHECK_THROW(model.get("imageExampleThree.png"), ImageNotAnnotatedYet);
}

BOOST_AUTO_TEST_SUITE_END()
