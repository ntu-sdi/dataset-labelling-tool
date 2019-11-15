//
// Created by 22ru on 11/11/19.
//
//Link to Boost
#define BOOST_TEST_DYN_LINK
//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "LinkedListTestModule"
//VERY IMPORTANT - include this last
#include <iostream>
#include "../include/LinkedList.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(EmptyListTest)
{
    LinkedList<double> l;
    BOOST_CHECK_EQUAL(l.isEmpty(), true);
}

BOOST_AUTO_TEST_CASE(TestInsertAtHead)
{
    LinkedList<double> l;
    l.insertNode(0, 1);
    BOOST_CHECK_EQUAL(l.isEmpty(), false);
}

BOOST_AUTO_TEST_CASE(TestInsertAtEnd)
{
    LinkedList<double> l;
    l.insertNode(0, 1);
    l.insertNode(1, 2);
    BOOST_CHECK_EQUAL(l.at(0), 1);
    BOOST_CHECK_EQUAL(l.at(1), 2);

    BOOST_CHECK_EQUAL(l.insertNode(5, 5), nullptr);
    BOOST_CHECK_EQUAL(l.insertNode(-1, -1), nullptr);
    BOOST_CHECK_EQUAL(l.length(), 2);
}

BOOST_AUTO_TEST_CASE(TestInsertInMiddle)
{
    LinkedList<double> l;
    l.insertNode(0, 1);
    l.insertNode(1, 2);
    l.insertNode(1, 3);
    BOOST_CHECK_EQUAL(l.at(0), 1);
    BOOST_CHECK_EQUAL(l.at(1), 3);
    BOOST_CHECK_EQUAL(l.at(2), 2);
}

BOOST_AUTO_TEST_CASE(TestGetNodeIndex)
{
    LinkedList<double> l;
    l.insertNode(0, 1);
    l.insertNode(1, 2);
    l.insertNode(1, 3);
    BOOST_CHECK_EQUAL(l.getNodeIndex(1), 0);
    BOOST_CHECK_EQUAL(l.getNodeIndex(2), 2);
    BOOST_CHECK_EQUAL(l.getNodeIndex(3), 1);
    
    BOOST_CHECK_EQUAL(l.getNodeIndex(5), -1);
}

BOOST_AUTO_TEST_CASE(TestDeleteNodeByIndex)
{
    LinkedList<double> l;
    l.insertNode(0, 1);
    l.insertNode(1, 2);
    l.insertNode(1, 3);

    BOOST_CHECK_EQUAL(l.removeNodeByIndex(4), -1);
    BOOST_CHECK_EQUAL(l.removeNodeByIndex(4), -1);

    l.removeNodeByIndex(0);
    BOOST_CHECK_EQUAL(l.length(), 2);

    l.insertNode(0, 1);
    l.removeNodeByIndex(1);
    BOOST_CHECK_EQUAL(l.length(), 2);

    l.removeNodeByIndex(1);
    BOOST_CHECK_EQUAL(l.length(), 1);

    l.removeNodeByIndex(0);
    BOOST_CHECK_EQUAL(l.length(), 0);
    
    BOOST_CHECK_EQUAL(l.removeNodeByIndex(0), -1);
}

BOOST_AUTO_TEST_CASE(TestDeleteNodeByData)
{
    LinkedList<double> l;
    l.insertNode(0, 1);
    l.insertNode(1, 2);
    l.insertNode(1, 3);
    
    BOOST_CHECK_EQUAL(l.removeNodeByData(4), -1);

    l.removeNodeByData(1);
    BOOST_CHECK_EQUAL(l.length(), 2);

    l.insertNode(0, 1);
    l.removeNodeByData(2);
    BOOST_CHECK_EQUAL(l.length(), 2);

    l.removeNodeByData(3);
    BOOST_CHECK_EQUAL(l.length(), 1);

    l.removeNodeByData(1);
    BOOST_CHECK_EQUAL(l.length(), 0);
}

