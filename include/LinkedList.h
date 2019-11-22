//
// Created by 22ru on 11/11/19.
//

#ifndef DATASET_LABELING_TOOL_LINKEDLIST_H
#define DATASET_LABELING_TOOL_LINKEDLIST_H

#include "exceptions.h"

/*
 * The function definitions have to be defined in the header file
 * because C++ doesn't allow for templates to be used in method
 * definitions in the .cpp file
 */
template <class T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
    };
    Node* head;
    int len {0};

public:
    LinkedList() { head = nullptr; }
    ~LinkedList() = default; // TODO: actually write the destructor
    // Con/de/structors

    bool isEmpty() { return head == nullptr; }

    T &operator[] (int index) { return at(index); }

    Node* insert(int index, T data)
    {
        if (index < 0) throw IndexOutOfBoundsError(); // TODO: this should throw IndexOutOfBounds

        int currentIndex = 1;
        Node* currentNode = head;
        while (currentNode && index > currentIndex)
        {
            currentNode = currentNode->next;
            ++currentIndex;
        }

        if (index > 0 && currentNode == nullptr) throw IndexOutOfBoundsError(); // TODO: this should throw IndexOutOfBounds

        Node* newNode = new Node;
        newNode->data = data;
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            ++len;
        }
        else
        {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            ++len;
        }
        return newNode;
    }

    T at(int index)
    {
        Node* currentNode = head;
        int currentIndex {0};

        while (currentIndex < index)
        {
            if (currentNode->next == nullptr) throw IndexOutOfBoundsError(); // TODO: This needs to throw an error
            currentNode = currentNode->next;
            ++currentIndex;
        }
        return currentNode->data;
    }

    int length()
    {
        return len;
    }

    int getIndex(T data)
    {
        int currentIndex = 0;
        Node* currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->data == data) return currentIndex;
            ++currentIndex;
            currentNode = currentNode->next;
        }
        throw ValueNotFoundError(); // TODO: this should throw an error

    }

    bool contains(T data)
    {
        int currentIndex = 0;
        Node* currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->data == data) return true;
            ++currentIndex;
            currentNode = currentNode->next;
        }
        return false;

    }

    void removeAt(int index)
    {
        Node* currentNode = head;
        Node* prevNode = nullptr;
        int currentIndex {0};
        if (len == 0) throw ArrayEmptyError(); // TODO: this needs to throw error

        while (currentIndex < index)
        {
            if (currentNode->next == nullptr) throw IndexOutOfBoundsError(); // TODO: This needs to throw an error
            prevNode = currentNode;
            currentNode = currentNode->next;
            ++currentIndex;
        }
        if (index == 0)
        {
            head = currentNode->next;
            --len;
        }
        else if (prevNode != nullptr)
        {
            prevNode->next = currentNode->next;
            --len;
        }
        else throw std::exception(); // This should never happen

        delete currentNode;
    }

    void remove(T data)
    {
        int currentIndex = 0;
        Node* currentNode = head;
        Node* prevNode = nullptr;

        while (currentNode != nullptr)
        {
            if (currentNode->data == data) break;
            ++currentIndex;
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        if (currentNode == nullptr) throw ValueNotFoundError(); // TODO: this needs to throw an error
        else if (currentIndex == 0)
        {
            head = currentNode->next;
            --len;
        }
        else if (prevNode != nullptr)
        {
            prevNode->next = currentNode->next;
            --len;
        }
        else throw std::exception(); // This should never happen

        delete currentNode;
    }


    Node* push(T data)
    {
        int insertIdx;
        
        if (this->isEmpty()) insertIdx = 0;
        else insertIdx = this->length();

        Node* n = this->insert(insertIdx, data);
        return n;
    }
};


#endif //DATASET_LABELING_TOOL_LINKEDLIST_H
