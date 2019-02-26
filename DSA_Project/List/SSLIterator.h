#ifndef SSLIterator_h
#define SSLIterator_h

#include <iostream>                     //To use standart input(cin) and output(cout) functions.
#include "SinglyLinkedList.h"           //To create SinglyLinkedList.
#include "Node.h"                       //To have Node variables.

using namespace std;                    //Input and output functions under the std namespace.


template <class TElem>
class SSLIterator
{
private:
    const SinglyLinkedList<TElem>* SLL;
    Node<TElem>* CURRENT;
    int POSITION;
    
public:
    
    //Constructor Function with parameter.
    SSLIterator (const SinglyLinkedList<TElem>* sll)
    {
        SLL = sll;
        CURRENT = SLL->head();
        POSITION = 0;
    }
    
    //Destructor Function.
    ~SSLIterator()
    {
        SLL = nullptr;
        CURRENT = nullptr;
        POSITION = 0;
    }
    
    //Returns reference of the current element.
    Node<TElem>& current()
    {
        return *CURRENT;
    }
    
    //Returns true if the current element is not equal to nullptr.
    bool valid()
    {
        return (CURRENT != nullptr) ? true : false;
    }
    
    //Returns the "position".
    int position() const
    {
        return POSITION;
    }
    
    //If it is valid, iterates to the next element.
    void next()
    {
        if ( valid() )
        {
            CURRENT = CURRENT->next();
            POSITION++;
        }
        
    }
    
    //If it is valid, iterates to the next element. (Postfix Increment)
    SSLIterator operator++(int )
    {
        next();
        return *this;
    }
};

#endif
