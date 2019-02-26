#include "MultiMap.h"               //To know MultiMap Class' functions.
#include "MMAPIterator.h"           //To create MMAPIterator.

//Constructor Function.
template <typename TKey, typename TValue>
MultiMap<TKey, TValue>::MultiMap()
    :containerSize(0)
{
    
};


//Destructor Function.
template <typename TKey, typename TValue>
MultiMap<TKey, TValue>::~MultiMap()
{
    containerSize = 0;   
}



//Creates a new pair using given "key" and "value" and puts it into the HashTable.
template <typename TKey, typename TValue>
void MultiMap<TKey, TValue>::insert(const TKey &key, const TValue &value)
{
    TPair* p = new TPair(key,value);
    if ( table.put(*p) )
        containerSize++;
    else
        delete p;
    
}




//Finds the associated pairs according to the given "key", and returns a list that contains those pairs.
template <typename TKey, typename TValue>
SinglyLinkedList<Pair<TKey, TValue>> MultiMap<TKey, TValue>::find(const TKey &key) const
{
    SinglyLinkedList<TPair> sll;
    int index = table.HashFunction(key);
    
    
    if (index != -1)
    {
        MMAPIterator<TKey, TValue> it(*this);
        
        while ( it.valid() &&
                it.current().info().key() != key )
            it++;
        
        while ( it.valid() &&
                it.current().info().key() == key)
        {
            sll.push_front( it.current().info() );
            it++;
        }
        
    }
    
    return sll;
    
}



//Removes the pair according to the given "key" and "value".
template <typename TKey, typename TValue>
bool MultiMap<TKey, TValue>::remove(const TKey &key, const TValue &value)
{
    int index = table.HashFunction(key);
    
    if(index != -1)
    {
        TPair p(key,value);
        
        if ( table.lists[index].remove(p) )
        {
            containerSize--;
            return true;
        }
        
    }
    
    return false;
    
}



//Returns the container size.
template <typename TKey, typename TValue>
int MultiMap<TKey, TValue>::size() const
{
    return containerSize;
}



//Tests whether the container is empty.
template <typename TKey, typename TValue>
bool MultiMap<TKey, TValue>::empty() const
{
    return ( containerSize == 0)? true : false;
}



//Clears content.
template <typename TKey, typename TValue>
void MultiMap<TKey, TValue>::clear()
{
    
    for( int i=0; i<table.length(); i++ )
        table.lists[i].~SinglyLinkedList();
    
    containerSize = 0;
    
}



//Counts pairs with a specific key.
template <typename TKey, typename TValue>
int MultiMap<TKey, TValue>::count(const TKey &key) const
{
    SinglyLinkedList<TPair> sll = find(key);
    
    return sll.size();
}
