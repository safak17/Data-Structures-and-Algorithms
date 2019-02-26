#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

#include "Node.h"           //To have Node variables.


template <class TElem>
class SinglyLinkedList
{
private:
    Node<TElem>* HEAD;
    Node<TElem>* TAIL;
    
    
    int SIZE;
    int MAX_SIZE;
    
public:
    
    //Constructor Function.
    SinglyLinkedList();
    
    //Destructor Function.
    ~SinglyLinkedList();
    
    
    
    
    
    
    /*          GETTERS         */
    //Returns the "size".
    int size() const;
    //Returns the "max_size".
    int max_size() const;
    
    //Returns "head".
    Node<TElem>* head() const;
    
    //Returns the reference of first element in the list.
    TElem& pop_front() const;
    
    //Returns the reference of last element in the list.
    TElem& pop_back() const;
    
    
    
    
    
    /*          EMPTY-FULL         */
    //Checks whether SinglyLinkedList is empty or not.
    bool empty() const;
    
    //Checks whether SinglyLinkedList is full or not.
    bool full() const;
    
    
    
    
    
    /*          ADD         */
    //Adds the givenElement to the beginning of SinglyLinkedList.
    bool push_front(const TElem& givenElement);
    
    //Adds the givenElement to the end of SinglyLinkedList.
    bool push_back(const TElem& givenElement);
    
    //Adds the givenElement to the specified position.
    bool push_at(const TElem& givenElement, int position);
    
    //Adds the givenElement after the specifiedElement.
    bool push_after (const TElem& givenElement, const TElem& specifiedElement );
    
    
    
    
    
    /*          FIND         */
    Node<TElem>* find(const TElem& givenElement);
    
    Node<TElem>* findPreviousFrom(const TElem& givenElement);
    
    
    
    
    
    
    /*          REMOVE         */
    //Removes the first element in the list.
    bool remove_front();
    
    //Removes the last element in the list.
    bool remove_back();
    
    //Removes the givenElement from list.
    bool remove(const TElem& givenElement);
    
};

#endif
