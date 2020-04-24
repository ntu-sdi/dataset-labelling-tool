#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Main
#endif

#include <string>
#include <boost/test/unit_test.hpp>

#include "../include/LinkedList.h"
#include "ui_MainView.h"

/**
 * @brief Helper function, which checks if a list is sorted.
 *
 * @param list
 *
 * @return bool
 */
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

// Testing that calling isEmpty returns true when appropriate.
BOOST_AUTO_TEST_CASE(EmptyListTest)
{
    LinkedList<double> l;
    BOOST_CHECK_EQUAL(l.isEmpty(), true);
}

// Testing that inserting a node at the head is successful.
BOOST_AUTO_TEST_CASE(TestInsertAtHead)
{
    LinkedList<double> l;
    l.insert(0, 1);
    BOOST_CHECK_EQUAL(l.isEmpty(), false);
}

// Tesing that inserting a node at the end is successful.
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

// Testing that inserting a node in the middle is successful.
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

// Testing that getting a node's index by its value is successful.
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

// Testing that deleting a node by its index is successful,
// and throws errors where appropriate.
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

// Testing that removing a node by its value is successful,
// and throws errors where appropriate.
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

// Testing that the linked list works with different types.
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

// Testing that pushing a node to the end is successful.
BOOST_AUTO_TEST_CASE(TestPush)
{
    LinkedList<std::string> l;
    l.push("hello");
    l.push("world");
    BOOST_CHECK_EQUAL(l.at(0), "hello");
    BOOST_CHECK_EQUAL(l.at(1), "world");
}

// Testing that the contains method works.
BOOST_AUTO_TEST_CASE(TestContains)
{
    LinkedList<std::string> l;
    l.push("hello");
    BOOST_CHECK_EQUAL(l.contains("hello"), true);
    BOOST_CHECK_EQUAL(l.contains("world"), false);
}

// Testing whether the list sorts with one item.
BOOST_AUTO_TEST_CASE(SortWithOneItem)
{
    LinkedList<int> l;
    l.push(1);
    l.sort();
    BOOST_CHECK_EQUAL(isSorted(l), true);
}

// Testing whether the unsorted list sorts with two items.
BOOST_AUTO_TEST_CASE(SortUnsortedListWithTwoItems)
{
    LinkedList<int> l;
    l.push(2);
    l.push(1);
    l.sort();
    BOOST_CHECK_EQUAL(isSorted(l), true);
}

// Testing whether the sorted list sorts with two items.
BOOST_AUTO_TEST_CASE(SortSortedListWithTwoItems)
{
    LinkedList<int> l;
    l.push(1);
    l.push(2);
    l.sort();
    BOOST_CHECK_EQUAL(isSorted(l), true);
}

// Testing whether the unsorted list sorts with five items.
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

// Testing whether a list copies.
BOOST_AUTO_TEST_CASE(CreateCopy){
    LinkedList<int> l;
    l.push(5);
    l.push(2);
    l.push(4);
    l.push(1);
    l.push(3);
    LinkedList<int> k = l.copy();
    BOOST_CHECK_EQUAL(k.length(), l.length());
    for(int i = 0; i < k.length(); i++ ) {
        BOOST_CHECK(k.at(i) == l.at(i));
    }
}

BOOST_AUTO_TEST_SUITE_END()
