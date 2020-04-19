#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif
#include "../include/LinkedList.h"
#include <string>
#include "ui_MainView.h"
#include<boost/test/unit_test.hpp>

template<class T>
bool isSorted(LinkedList<T>& list)
{
    if(list.length() < 2) {
        return true;
    }
    T prev;
    for(int i = 0; i <= list.length() - 1; ++i) {
        if(i == 0) {
            prev = list.at(i);
            continue;
        }
        if(list.at(i) < prev) {
            return false;
        }
        prev = list.at(i);
    }
    return true;
}

BOOST_AUTO_TEST_SUITE( LinkedListTest )

    BOOST_AUTO_TEST_CASE(EmptyListTest)
    // Testing that calling isEmpty returns true when appropriate.
    {
        LinkedList<double> l;
        BOOST_CHECK_EQUAL(l.isEmpty(), true);
    }

    BOOST_AUTO_TEST_CASE(TestInsertAtHead)
    // Testing that inserting a node at the head is successful.
    {
        LinkedList<double> l;
        l.insert(0, 1);
        BOOST_CHECK_EQUAL(l.isEmpty(), false);
    }

    BOOST_AUTO_TEST_CASE(TestInsertAtEnd)
    // Tesing that inserting a node at the end is successful.
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
    // Testing that inserting a node in the middle is successful.
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
    // Testing that getting a node's index by its value is successful.
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
    // Testing that deleting a node by its index is successful,
    // and throws errors where appropriate.
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
    // Testing that removing a node by its value is successful,
    // and throws errors where appropriate.
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

    BOOST_AUTO_TEST_CASE(TestDifferentTypes)
    // Testing that the linked list works with different types.
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
    // Testing that pushing a node to the end is successful.
    {
        LinkedList<std::string> l;
        l.push("hello");
        l.push("world");

        BOOST_CHECK_EQUAL(l.at(0), "hello");
        BOOST_CHECK_EQUAL(l.at(1), "world");
    }
    
    BOOST_AUTO_TEST_CASE(TestContains)
    // Testing that the contains method works.
    {
        LinkedList<std::string> l;
        l.push("hello");
        
        BOOST_CHECK_EQUAL(l.contains("hello"), true);
        BOOST_CHECK_EQUAL(l.contains("world"), false);
    }

    BOOST_AUTO_TEST_CASE(SortWithOneItem)
    {
        LinkedList<int> l;
        l.push(1);
        l.sort();
        BOOST_CHECK_EQUAL(isSorted(l), true);
    }

    BOOST_AUTO_TEST_CASE(SortUnsortedListWithTwoItems)
    {
        LinkedList<int> l;
        l.push(2);
        l.push(1);
        l.sort();
        BOOST_CHECK_EQUAL(isSorted(l), true);
    }

    BOOST_AUTO_TEST_CASE(SortSortedListWithTwoItems)
    {
        LinkedList<int> l;
        l.push(1);
        l.push(2);
        l.sort();
        BOOST_CHECK_EQUAL(isSorted(l), true);

    }

    BOOST_AUTO_TEST_CASE(SortUnsortedListWithFiveItems)
    {
        LinkedList<int> l;
        l.push(5);
        l.push(2);
        l.push(4);
        l.push(1);
        l.push(3);
        l.sort();
        BOOST_CHECK_EQUAL(isSorted(l), true);
    }

    BOOST_AUTO_TEST_CASE(CreateCopy){
        LinkedList<int> l;
        l.push(5);
        l.push(2);
        l.push(4);
        l.push(1);
        l.push(3);
        LinkedList<int> k = l.copy();
        BOOST_CHECK_EQUAL(k.length(), l.length());
        for(int i = 0; i < k.length(); i++ ){
            BOOST_CHECK(k.at(i) == l.at(i));
        }
    }

BOOST_AUTO_TEST_SUITE_END()