#pragma once

#include "exceptions.h"

/*
 * The function definitions have to be defined in the header file
 * because C++ doesn't allow for templates to be used in method
 * definitions in the .cpp file
 */

/**
 * Custom implementation of a singly-linked list.
 */
template <class T> class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
    };
    Node* head;
    int len {0};

    Node* nodeAt(int index)
    {
        Node* currentNode = head;
        int currentIndex = 0;
        while(currentIndex < index) {
            if(currentNode->next == nullptr) {
                throw IndexOutOfBoundsError();
            }
            currentNode = currentNode->next;
            ++currentIndex;
        }
        return currentNode;
    }

    /**
     * @brief An internal implementation of the quicksort algorithm.
     *
     * @param left Starting left bound of the algorithm.
     * @param right Starting right bound of the algorithm.
     */
    void quicksort(int left, int right)
    {
        int i = left;
        int j = right;
        T pivot = this->at((i + j) / 2);
        T temp;
        while(i <= j) {
            while(this->at(i) < pivot) {
                ++i;
            }
            while(this->at(j) > pivot) {
                --j;
            }
            if(i <= j) {
                temp = this->at(i);
                this->replace(i, this->at(j));
                this->replace(j, temp);
                ++i;
                --j;
            }
        }
        if(j > left) {
            this->quicksort(left, j);
        }
        if(i < right) {
            this->quicksort(i, right);
        }
    }

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList() = default;

    /**
     * @brief Chceks if the list is empty.
     *
     * @return bool True if the list is empty, otherwise false.
     */
    bool isEmpty()
    {
        return head == nullptr;
    }

    /**
     * @brief Gets the data of the node at the index specified.
     *
     * This method overrides the [] operator, simply calling LinkedList::at.
     *
     * @param index Index of the node to get.
     * @return T Data of the node at the given index.
     */
    T &operator[] (int index)
    {
        return at(index);
    }

    /**
     * @brief Inserts a new node.
     *
     * @param index Index to insert at.
     * @param data Data of the new node.
     * @return Node* Pointer to the new node.
     */
    Node* insert(int index, T data)
    {
        if(index < 0) {
            throw IndexOutOfBoundsError();
        }
        Node* currentNode = this->nodeAt(index - 1);
        if(index > 0 && currentNode == nullptr) {
            throw IndexOutOfBoundsError();
        }
        Node* newNode = new Node;
        newNode->data = data;
        if(index == 0) {
            newNode->next = this->head;
            this->head = newNode;
        }
        else {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
        ++len;
        return newNode;
    }
    /**
     * @brief Gets the data of the node at the index specified.
     *
     * @param index The index of the node to get the data.
     * @return T Data of the node at the index specified.
     */
    T at(int index)
    {
        Node* currentNode = head;
        int currentIndex {0};
        while(currentIndex < index) {
            if(currentNode->next == nullptr) {
                throw IndexOutOfBoundsError();
            }
            currentNode = currentNode->next;
            ++currentIndex;
        }
        return currentNode->data;
    }

    /**
     * @brief Gets the length of the list.
     *
     * @return int The lenght of the list.
     */
    int length()
    {
        return len;
    }

    /**
     * @brief Returns the index of the first node with the given data.
     *
     * @param data Data of node to get the index of.
     * @return int Index of the first node with the given data.
     */
    int getIndex(T data)
    {
        int currentIndex = 0;
        Node* currentNode = head;
        while(currentNode != nullptr) {
            if(currentNode->data == data) {
                return currentIndex;
            }
            ++currentIndex;
            currentNode = currentNode->next;
        }
        throw ValueNotFoundError();
    }

    /**
     * @brief Checks if the list contains a node with the given data.
     *
     * @param data Data to check.
     * @return bool True if the list contains a node with the data, otherwise false.
     */
    bool contains(T data)
    {
        int currentIndex = 0;
        Node* currentNode = head;
        while(currentNode != nullptr) {
            if(currentNode->data == data) {
                return true;
            }
            ++currentIndex;
            currentNode = currentNode->next;
        }
        return false;
    }



    /**
     * @brief Removes the node at the given index.
     *
     * @param index Index of the node to be removed.
     */
    void removeAt(int index)
    {
        Node* currentNode = head;
        Node* prevNode = nullptr;
        int currentIndex {0};
        if(len == 0) {
            throw ArrayEmptyError();
        }
        while(currentIndex < index) {
            if(currentNode->next == nullptr) {
                throw IndexOutOfBoundsError();
            }
            prevNode = currentNode;
            currentNode = currentNode->next;
            ++currentIndex;
        }
        if(index == 0) {
            head = currentNode->next;
            --len;
        }
        else if(prevNode != nullptr) {
            prevNode->next = currentNode->next;
            --len;
        }
        else {
            throw std::exception();
        }
        delete currentNode;
    }

    /**
     * @brief Removes the first node with the given data.
     *
     * @param data Data of the node to remove.
     */
    void remove(T data)
    {
        int currentIndex = 0;
        Node* currentNode = head;
        Node* prevNode = nullptr;
        while(currentNode != nullptr) {
            if(currentNode->data == data) {
                break;
            }
            ++currentIndex;
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        if(currentNode == nullptr) {
            throw ValueNotFoundError();
        }
        else if(currentIndex == 0) {
            head = currentNode->next;
            --len;
        }
        else if(prevNode != nullptr) {
            prevNode->next = currentNode->next;
            --len;
        }
        else {
            throw std::exception();
        }
        delete currentNode;
    }

    void replace(int index, T data)
    {
        Node* node = this->nodeAt(index);
        node->data = data;
    }

    /**
     * @brief Inserts a new node to the end of the list.
     *
     * @param data Data of the node to insert.
     * @return Node* Pointer to the new node.
     */
    Node* push(T data)
    {
        int insertIdx;
        if(this->isEmpty()) {
            insertIdx = 0;
        }
        else {
            insertIdx = this->length();
        }
        Node* n = this->insert(insertIdx, data);
        return n;
    }

    /**
     * @brief Sorts the linked list in-place.
     */
    void sort()
    {
        if(this->len > 1) {
            this->quicksort(0, this->len -1);
        }
    }
};
