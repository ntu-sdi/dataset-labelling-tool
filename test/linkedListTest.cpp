//
// Created by 22ru on 11/15/19.
//

#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include "../include/LinkedList.h"
#include <string>
#include<boost/test/unit_test.hpp>

// TODO: rename the test cases

BOOST_AUTO_TEST_SUITE( LinkedListTest )

    BOOST_AUTO_TEST_CASE(EmptyListTest)
    {
        LinkedList<double> l;
        BOOST_CHECK_EQUAL(l.isEmpty(), true);
    }

    BOOST_AUTO_TEST_CASE(TestInsertAtHead)
    {
        LinkedList<double> l;
        l.insert(0, 1);
        BOOST_CHECK_EQUAL(l.isEmpty(), false);
    }

    BOOST_AUTO_TEST_CASE(TestInsertAtEnd)
    {
        LinkedList<double> l;
        l.insert(0, 1);
        l.insert(1, 2);
        BOOST_CHECK_EQUAL(l.at(0), 1);
        BOOST_CHECK_EQUAL(l.at(1), 2);

        BOOST_CHECK_THROW(l.insert(5, 5), IndexOutOfBoundsError);
        BOOST_CHECK_THROW(l.insert(-1, -1), IndexOutOfBoundsError);

        BOOST_CHECK_EQUAL(l.length(), 2);
    }

    BOOST_AUTO_TEST_CASE(TestInsertInMiddle)
    {
        LinkedList<double> l;
        l.insert(0, 1);
        l.insert(1, 2);
        l.insert(1, 3);
        BOOST_CHECK_EQUAL(l.at(0), 1);
        BOOST_CHECK_EQUAL(l.at(1), 3);
        BOOST_CHECK_EQUAL(l.at(2), 2);
    }

    BOOST_AUTO_TEST_CASE(TestGet)
    {
        LinkedList<double> l;
        l.insert(0, 1);
        l.insert(1, 2);
        l.insert(1, 3);
        BOOST_CHECK_EQUAL(l.getIndex(1), 0);
        BOOST_CHECK_EQUAL(l.getIndex(2), 2);
        BOOST_CHECK_EQUAL(l.getIndex(3), 1);

        BOOST_CHECK_THROW(l.getIndex(5), ValueNotFoundError);
    }

    BOOST_AUTO_TEST_CASE(TestDeleteByIndex)
    {
        LinkedList<double> l;
        l.insert(0, 1);
        l.insert(1, 2);
        l.insert(1, 3);

        BOOST_CHECK_THROW(l.removeAt(4), IndexOutOfBoundsError);

        l.removeAt(0);
        BOOST_CHECK_EQUAL(l.length(), 2);

        l.insert(0, 1);
        l.removeAt(1);
        BOOST_CHECK_EQUAL(l.length(), 2);

        l.removeAt(1);
        BOOST_CHECK_EQUAL(l.length(), 1);

        l.removeAt(0);
        BOOST_CHECK_EQUAL(l.length(), 0);

        BOOST_CHECK_THROW(l.removeAt(0), ArrayEmptyError);
    }

    BOOST_AUTO_TEST_CASE(TestDelete)
    {
        LinkedList<double> l;
        l.insert(0, 1);
        l.insert(1, 2);
        l.insert(1, 3);

        BOOST_CHECK_THROW(l.remove(4), ValueNotFoundError);

        l.remove(1);
        BOOST_CHECK_EQUAL(l.length(), 2);

        l.insert(0, 1);
        l.remove(2);
        BOOST_CHECK_EQUAL(l.length(), 2);

        l.remove(3);
        BOOST_CHECK_EQUAL(l.length(), 1);

        l.remove(1);
        BOOST_CHECK_EQUAL(l.length(), 0);
    }
<<<<<<< HEAD
=======
    BOOST_AUTO_TEST_CASE(TestDifferentTypes)
    {
        LinkedList<std::string> l;
        l.insert(0, "hello");
        l.insert(1, "world");

        BOOST_CHECK_EQUAL(l.at(0), "hello");
        BOOST_CHECK_EQUAL(l.at(1), "world");

        BOOST_CHECK_EQUAL(l.getIndex("hello"), 0);
        BOOST_CHECK_EQUAL(l.getIndex("world"), 1);

        l.remove("world");
        l.removeAt(0);
        BOOST_CHECK_EQUAL(l.length(), 0);
    }
    BOOST_AUTO_TEST_CASE(TestPush)
    {
        LinkedList<std::string> l;
        l.push("hello");
        l.push("world");

        BOOST_CHECK_EQUAL(l.at(0), "hello");
        BOOST_CHECK_EQUAL(l.at(1), "world");
    }
    
    BOOST_AUTO_TEST_CASE(TestContains)
    {
        LinkedList<std::string> l;
        l.push("hello");
        
        BOOST_CHECK_EQUAL(l.contains("hello"), true);
        BOOST_CHECK_EQUAL(l.contains("world"), false);
    }
>>>>>>> master

BOOST_AUTO_TEST_SUITE_END()
