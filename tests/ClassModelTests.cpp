#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif

#include <boost/test/unit_test.hpp>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <stdexcept>

#include "ui_MainView.h"
#include "../include/ClassModel.h"

std::string TESTFILEPATH = "../testFiles/ClassModelTests/test.class";

BOOST_AUTO_TEST_SUITE(ClassModelTests)

// Tests that creating a new class file is successful.
BOOST_AUTO_TEST_CASE(CreateClassFile)
{
    ClassModel c;
    BOOST_CHECK_NO_THROW(c.create(QString::fromStdString(TESTFILEPATH)));
    std::fstream f(TESTFILEPATH);
    BOOST_CHECK_EQUAL(false, f.fail());
    f.close();
}

// Tests that adding a valid class is successful.
BOOST_AUTO_TEST_CASE(AddValidClass)
{
    ClassModel c;
    c.browse(QString::fromStdString(TESTFILEPATH));
    c.addClass("test1");
    std::fstream f(TESTFILEPATH);
    std::string check;
    std::getline(f, check);
    BOOST_CHECK_EQUAL("test1", check);
    f.close();
}

// Tests that trying to add a class with padded whitespace results
// in the whitespace being trimmed.
BOOST_AUTO_TEST_CASE( AddClassWithPaddedWhitespace )
{
    ClassModel c;
    c.create(QString::fromStdString(TESTFILEPATH));
    c.browse(QString::fromStdString(TESTFILEPATH));
    c.addClass("     test1     ");
    std::fstream f(TESTFILEPATH);
    std::string check;
    std::getline(f, check);
    BOOST_CHECK_EQUAL("test1", check);
    f.close();
}

// Tests that trying to add an all-whitespace class fails.
BOOST_AUTO_TEST_CASE( AddWhiteSpaceClass )
{
    ClassModel c;
    c.create(QString::fromStdString(TESTFILEPATH));
    c.browse(QString::fromStdString(TESTFILEPATH));
    BOOST_CHECK_THROW(c.addClass("           ");, std::invalid_argument);
}

// Testing that trying to add a class with no class file selected
// results in an error being thrown.
BOOST_AUTO_TEST_CASE( AddClassWithNoFile )
{
    ClassModel c;
    BOOST_CHECK_THROW(c.addClass("test"), std::invalid_argument);
}

// Tests that removing a valid class is successful.
BOOST_AUTO_TEST_CASE(RemoveValidClass)
{
    ClassModel c;
    c.create(QString::fromStdString(TESTFILEPATH));
    c.addClass("test1");
    c.addClass("test2");
    c.removeClass("test2");
    std::string check;
    std::fstream f(TESTFILEPATH);
    std::getline(f, check);
    BOOST_CHECK_EQUAL("test1", check);
}

// Tests that removing an invalid class is not successful.
BOOST_AUTO_TEST_CASE(RemoveInvalidClass)
{
    ClassModel c;
    c.create(QString::fromStdString(TESTFILEPATH));
    c.addClass("test1");
    c.addClass("test2");
    c.removeClass("invalid");
    std::string check;
    std::fstream f(TESTFILEPATH);
    std::getline(f, check);
    BOOST_CHECK_EQUAL("test1", check);
    std::getline(f, check);
    BOOST_CHECK_EQUAL("test2", check);
}

// Tests that trying to remove a class with no class file selected
// is not successful.
BOOST_AUTO_TEST_CASE(RemoveClassWithNoFile)
{
    ClassModel c;
    BOOST_CHECK_THROW(c.removeClass("test"), std::invalid_argument);
}

// Tests that getting all classes is successful.
BOOST_AUTO_TEST_CASE(GetAll)
{
    ClassModel c;
    c.create(QString::fromStdString(TESTFILEPATH));
    c.addClass("test1");
    c.addClass("test2");
    std::string test1Compare = c.getAll()[0].toStdString();
    std::string test2Compare = c.getAll()[1].toStdString();
    BOOST_CHECK_EQUAL("test1", test1Compare);
    BOOST_CHECK_EQUAL("test2", test2Compare);
}

// Tests that tring to get all classes with no class file selected is
// unsuccessful.
BOOST_AUTO_TEST_CASE(GetAllWithNoFilePath)
{
    ClassModel c;
    BOOST_CHECK_THROW(c.getAll(), std::invalid_argument);
}

// Test trying to set a valid class as the selected class for annotating.
BOOST_AUTO_TEST_CASE(SelectAndRetreiveClass)
{
    ClassModel c;
    c.create(QString::fromStdString(TESTFILEPATH));
    c.addClass("test1");
    BOOST_CHECK_NO_THROW(c.select("test1"));
    BOOST_CHECK(c.getSelected() == "test1");
}

// Test trying to select class which is not present among classes from class file.
BOOST_AUTO_TEST_CASE(SelectNonExistingClass)
{
    ClassModel c;
    c.create(QString::fromStdString(TESTFILEPATH));
    BOOST_CHECK_THROW(c.select("NONEXISTINGINVALIDCLASSNAME"), ClassNotFoundError);
}

// Test trying to get selected class before it has been set.
BOOST_AUTO_TEST_CASE(RetreiveClassBeforeSetting)
{
    ClassModel c;
    c.create(QString::fromStdString(TESTFILEPATH));
    BOOST_CHECK_THROW(c.getSelected(), ClassNotSelectedError);
}

BOOST_AUTO_TEST_SUITE_END()
