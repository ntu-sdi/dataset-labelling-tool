//
// Created by 22ru on 11/11/19.
//
//Link to Boost
#define BOOST_TEST_DYN_LINK
//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "LinkedListTestModule"
//VERY IMPORTANT - include this last
#include <iostream>
#include "../include/linkedlist.h"
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
