#ifndef HashTable_h
#define HashTable_h

#include <iostream>                     //To use standart input(cin) and output(cout) functions.
#include "SinglyLinkedList.cpp"         //To create SinglyLinkedList.
#include "Pair.h"                       //To create pair.

using namespace std;                    //Input and output functions under the std namespace.





template <typename TPair>
class HashTable{
private:
    
    int LENGTH;
    
public:
    SinglyLinkedList< TPair >* lists;
    
    //Constructor Function.
    HashTable();
    
    //Destructor Function.
    ~HashTable();
    
    
    //Returns the index which is calculated by using itemKey.
    int HashFunction(string itemKey) const;
    
    
    
    //Puts the given pair specified index which is provided by HashFunction.
    bool put( TPair &p );
    
    
    
    //Gets the given pair specified index which is provided by HashFunction.
    TPair* get( TPair &p );
    
    
    
    //Returns "LENGTH".
    int length() const;
    
};


#endif
