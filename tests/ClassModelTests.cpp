#include <cstdio>
#include <fstream>
#include <stdexcept>
#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include "../include/ClassModel.h"
#include <string>
#include <iostream>
#include "ui_MainView.h"
#include<boost/test/unit_test.hpp>

std::string TESTFILEPATH = "../testFiles/ClassModelTests/test.class";

BOOST_AUTO_TEST_SUITE( ClassModelTests )

    BOOST_AUTO_TEST_CASE( CreateClassFile ) {
         // Tests that creating a new class file is successful.
        ClassModel c;
        BOOST_CHECK_NO_THROW(c.create(QString::fromStdString(TESTFILEPATH)));
        std::fstream f(TESTFILEPATH);
        BOOST_CHECK_EQUAL( false, f.fail() );
        f.close();
    }

    BOOST_AUTO_TEST_CASE( AddValidClass ) {
        // Tests that adding a valid class is successful.
        ClassModel c;
        c.browse(QString::fromStdString(TESTFILEPATH));
        c.addClass("test1");
        std::fstream f(TESTFILEPATH);
        std::string check;
        std::getline(f, check);
        BOOST_CHECK_EQUAL( "test1", check);
        f.close();
    }

    BOOST_AUTO_TEST_CASE( AddClassWithPaddedWhitespace ) {
        // Tests that trying to add a class with padded whitespace results
        // in the whitespace being trimmed.
        ClassModel c;
        c.create(QString::fromStdString(TESTFILEPATH));
        c.browse(QString::fromStdString(TESTFILEPATH));
        c.addClass("     test1     ");
        std::fstream f(TESTFILEPATH);
        std::string check;
        std::getline(f, check);
        BOOST_CHECK_EQUAL( "test1", check);
        f.close();
    }

    BOOST_AUTO_TEST_CASE( AddWhiteSpaceClass ) {
        // Tests that trying to add an all-whitespace class fails.
        ClassModel c;
        c.create(QString::fromStdString(TESTFILEPATH));
        c.browse(QString::fromStdString(TESTFILEPATH));
        BOOST_CHECK_THROW( c.addClass("           ");, std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE( AddClassWithNoFile ) {
        // Testing that trying to add a class with no class file selected
        // results in an error being thrown.
        ClassModel c;
        BOOST_CHECK_THROW(c.addClass("test"), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(RemoveValidClass) {
        // Tests that removing a valid class is successful.
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

    BOOST_AUTO_TEST_CASE(RemoveInvalidClass) {
        // Tests that removing an invalid class is not successful.
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

    BOOST_AUTO_TEST_CASE(RemoveClassWithNoFile) {
        // Tests that trying to remove a class with no class file selected
        // is not successful.
        ClassModel c;
        BOOST_CHECK_THROW(c.removeClass("test"), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(GetAll) {
        // Tests that getting all classes is successful.
        ClassModel c;
        c.create(QString::fromStdString(TESTFILEPATH));
        c.addClass("test1");
        c.addClass("test2");
        std::string test1Compare = c.getAll()[0].toStdString();
        std::string test2Compare = c.getAll()[1].toStdString();
        BOOST_CHECK_EQUAL("test1", test1Compare);
        BOOST_CHECK_EQUAL("test2", test2Compare);
    }

    BOOST_AUTO_TEST_CASE(GetAllWithNoFilePath) {
        // Tests that tring to get all classes with no class file selected is
        // unsuccessful.
        ClassModel c;
        BOOST_CHECK_THROW(c.getAll(), std::invalid_argument);
    }

BOOST_AUTO_TEST_SUITE_END()

