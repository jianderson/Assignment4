#include"DoublyListNode.h"
using namespace std;
template <class T>
class DoublyLinkedList
{
public:
    //declare variables
    DoublyListNode<T> *front;
    DoublyListNode<T> *back;
    unsigned int size;

//methods
//constructor
    DoublyLinkedList()
    {
        front = NULL; //nullptr
        back = NULL;
        size = 0;
    }
    //detructor
    ~DoublyLinkedList()
    {
        //nothing
    }
//insertfront method
    void insertFront(T d)
    {
        //create new node
        DoublyListNode<T> *node = new DoublyListNode<T>(d);
        if(isEmpty())
        {
            back = node;
        }
        else
        {
            front -> prev = node;
            node -> next = front;
        }
        front = node;
        //increment the size
        size++;
    }

//insert back function
    void insertBack(T d)
    {
        //create new node
        DoublyListNode<T> *node = new DoublyListNode<T>(d);
        if(isEmpty())
        {

            front = node;
            back = node;
        }
        else
        {

            back-> next = node;
            node-> prev = back;
        }

        back = node;
        //increment size
        size++;
    }
//remove front method
    T removeFront()
    {
        //crate new node
        DoublyListNode<T> *ft = front;
        //check if there is a single element
        if(front->next == NULL)
        {
            back = NULL;
        }
        else
        {
            front->next->prev = NULL;
        }
        //update where the front is
        front = front->next;
        //get data from temp
        T temp = ft->data;
        //null out the next link
        ft->next = NULL;
        //decrease the size
        size--;
        //delete original
        delete ft;
        //return temp
        return temp;
    }



//method to delete a position
    T deletePos(T pos)
    {
        //create index
        int idx = 0;
        DoublyListNode<T> *curr = front;
        DoublyListNode<T> *prev = front;
        //while it is not the position you want
        while (idx != pos)
        {
            prev = curr; //make sure previous stays back 1
            curr = curr->next;
            idx++;
        }
        //make sure to add check for valid pos and curr != nullpointer

        prev->next = curr-> next;
        curr->next = NULL;
        T temp = curr->data;
        delete curr;
        size--;
        return temp;
    }
//find a certain data
    T find(T d)
    {
        //create index
        int idx = 0;
        DoublyListNode<T> *curr = front;
//while current is not null
        while(curr != NULL)
        {
            if(curr -> data == d)
            {
                break;
            }
            idx++;
            curr = curr -> next;
        }
//if current is equal to null
        if(curr == NULL)
        {
            idx = -1;
        }
        return idx;
    }
//check if empty
    bool isEmpty()
    {
        if(size == 0)
            return true;
        else
            return false;
    }
//print the entire list
    void printList()
    {
        DoublyListNode<T> *curr = front;
        while (*curr != NULL)
        {
            cout << curr->data << endl;
            curr = curr->next;

        }
    }
    //get the size
    unsigned int getSize()
    {
        return size;
    }
//get the certain index
    T getIndex(int idx)
    {
        DoublyListNode<T> *curr = front;
        for(int i = 0; i < idx; ++i)
        {
            curr = curr -> next;
        }

        return curr->data;
    }

};
