#ifndef MultiMap_h
#define MultiMap_h

#include <iostream>                     //To use standart input(cin) and output(cout) functions.
#include "HashTable.cpp"                //To have HashTable variable.
#include "Pair.h"                       //To create Pair.

template <typename TKey, typename TValue>
class MultiMap
{
    typedef Pair<TKey,TValue> TPair;
    
private:
    int containerSize;
    
public:
    

    HashTable<TPair> table;
    
    
    //Constructor Function.
    MultiMap();
    
    //Destructor Function.
    ~MultiMap();
    
    
    //Creates a new pair using given "key" and "value" and puts it to the HashTable.
    void insert(const TKey &key, const TValue &value);
    
    
    //Finds the associated pairs according to the given "key", and returns a list that contains those pairs.
    SinglyLinkedList<TPair> find(const TKey &key) const;
    
    
    //Removes the pair according to the given "key" and "value".
    bool remove(const TKey &key, const TValue &value);
    
    
    //Returns the container size.
    int size() const;
    
    
    //Tests whether the container is empty.
    bool empty() const;
    
    
    //Clears content.
    void clear();
    
    
    //Counts pairs with a specific key.
    int count(const TKey &key) const;
    
};


#endif
