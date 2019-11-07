#ifndef GENQUEUE_H
#define GENQUEUE_H
#include "DoublyLinkedList.h"
#include <iostream>
template <class T>
//queue of characters
class GenQueue
{
public:
    //contructor
    GenQueue()
    {
        myQueue = new DoublyLinkedList<T>();

    }
    //destructor
    ~GenQueue()
    {
        // delete myQueue;
    }
    //insert data in the back
    void insert(T data)
    {
        // if(tail == mSize-1)
        // {
        //     tail = -1;
        // }

        myQueue->insertBack(data);
        // myQueue->++tail = data;

    }
//remove data from the front
    T remove()
    {

        T c = myQueue->removeFront();

        return c;
    }
//peek the top of the queue
    T peek()
    {
        return myQueue-> front->data;
    }

//dont need it will never be full
    // bool isFull()
    // {
    //     return (numElements == mSize);
    // }

//check if the queue is empty
    bool isEmpty()
    {
        return (myQueue->getSize() == 0);
    }
//get the size of the queue
    int getSize()
    {
        return myQueue->getSize();
    }

private:

//declare the actual queue
    DoublyLinkedList<T> *myQueue;

};

#endif
