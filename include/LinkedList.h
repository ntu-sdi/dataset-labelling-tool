//
// Created by 22ru on 11/11/19.
//

#ifndef DATASET_LABELING_TOOL_LINKEDLIST_H
#define DATASET_LABELING_TOOL_LINKEDLIST_H

#include "LinkedListNode.h"

template <class T>
class LinkedList
{
private:
    Node<T>* head;

public:
    LinkedList() { head = nullptr; }
    ~LinkedList() = default; // TODO: actually write the destructor
    // Con/de/structors

    bool isEmpty() { return head == nullptr; }
    Node<T>* insertNode(int index, T data)
    {
        if (head == nullptr)
        {
            auto* newNode = new Node<T>;
            newNode->data = data;
            newNode->next = nullptr;

            head = newNode;

            return newNode;
        }
        return nullptr;
    }

    int getNodeIndex(T data);
    T getNodeData(int index);
    T removeNodeByIndex(int index);
    int removeNodeByData(T data);
};


#endif //DATASET_LABELING_TOOL_LINKEDLIST_H
