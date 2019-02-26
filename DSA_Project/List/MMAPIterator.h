#ifndef MMAPIterator_h
#define MMAPIterator_h

#include <iostream>                     //To use standart input(cin) and output(cout) functions.
#include "MultiMap.h"                   //To create MultiMap.

using namespace std;                    //Input and output functions under the std namespace.


template <typename TKey, typename TValue>
class MMAPIterator
{
    typedef Pair<TKey, TValue> TPair;
    
private:
    const MultiMap<TKey,TValue>& map;
    
    const SinglyLinkedList<TPair>* iteratorList;
    int listPosition;
    
    Node<TPair>* CURRENT;
    
    
public:
    
    //Constructor Function with parameter.
    MMAPIterator(const MultiMap<TKey,TValue> &m) : map(m)
    {
        
        int i = map.table.length()-1;
        
        //Finds the first list which is not empty REVERSE.
        for( ; i>=0 ; i--)
            if ( map.table.lists[i].size() != 0 )
                break;
        
        
        //If i is bigger than 0.
        // map.table.lists[i] is not empty.
        if(  i >= 0 )
        {
            iteratorList = &( map.table.lists[i] );
            CURRENT = map.table.lists[i].head();
            listPosition = i;
        }
        else
        {
            iteratorList = nullptr;
            listPosition = i;
            CURRENT = nullptr;
        }
        
    }//end MMAPIterator()
    
    
    //Destructor Function.
    ~MMAPIterator()
    {
        iteratorList = nullptr;
        CURRENT = nullptr;
    }
    
    
    //Returns the reference of current NODE<TPair>.
    Node<TPair>& current()
    {
        return *CURRENT;
    }
    
    
    //Returns "true" if the current NODE<TPair> is not equal to nullptr.
    bool valid()
    {
        return (CURRENT != nullptr) ? true : false;
    }
    
    
    //Iterates to the next NODE<TPair>.
    void next()
    {
        
        if ( valid() )
        {
            
            //If next element of current element is nullptr...
            if ( CURRENT->next() == nullptr )
            {
                //... then go to the first list that is not empty.
                do{
                    listPosition--;
                    
                    if ( map.table.lists[listPosition].size() != 0 )
                    {
                        iteratorList = &(map.table.lists[listPosition]);
                        CURRENT = map.table.lists[listPosition].head();
                        
                        return;
                    }
                } while ( 0 != listPosition );
                
                
                //If "any non empty list" is not found, that means, Iterator reached the final line of HashTable.
                this->~MMAPIterator();
                
            }//end IF ( CURRENT->next() == nullptr )
            
            else
                CURRENT = CURRENT->next();
            
            
        }//IF valid()
        
        
    }//end next()
    
    
    //If it is valid, iterates to the next NODE<TPair>. (Postfix Increment)
    MMAPIterator operator++(int )
    {
        next();
        return *this;
    }
    
};



#endif
