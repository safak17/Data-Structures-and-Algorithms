#include "HashTable.h"                  //To know HashTable's functions.

//Constructor Function.
template <typename TPair>
HashTable<TPair>::HashTable():LENGTH(52)
{
    lists = new SinglyLinkedList< TPair >[LENGTH];
    
}


//Destructor Function.
template <typename TPair>
HashTable<TPair>::~HashTable()
{
    
    delete[] lists;
    
    LENGTH = -1;
}


//Returns the index which is calculated by using itemKey.
template <typename TPair>
int HashTable<TPair>::HashFunction(string itemKey) const
{
    
    if(itemKey.length() < 2)
        return -1;
    
    //CONTROL English Alphabet.
    string controlString = itemKey;
    for(int i=0; i < controlString.length(); i++)
        controlString[i] = toupper(controlString[i]);
    
    for(int i=0, asciiControl = 0; i<controlString.length(); i++)
    {
        asciiControl = controlString[i] % 65;
        if( asciiControl < 0 || asciiControl > 25)
            return -1;
    }
    //END CONTROL English Alphabet.
    
    
    //First two letters of itemKey should be UpperCase in case we hash it according to the ASCII TABLE.
    itemKey[0] = toupper(itemKey[0]);
    itemKey[1] = toupper(itemKey[1]);
    
    int zerothLetter = itemKey[0] % 65;
    int firstLetter = itemKey[1] % 65;
    
    return (firstLetter < 13 ) ? 2*zerothLetter : 2*zerothLetter+1;
    
}


//Puts the given pair specified index which is provided by HashFunction.
template <typename TPair>
bool HashTable<TPair>::put( TPair& p)
{
    
    int index = HashFunction( p.key() );
    
    if ( index != -1 )
    {
        
        //If same pair has already put into the map, then return.
        
        if (lists[index].find(p))
            return false;
        
        //If there is a pair whose key also same with given "p".
        
        SSLIterator<TPair> it(&lists[index]);
        
        while(it.valid() && it.current().info().key() != p.key() )
            it++;
        
        if (it.valid() && it.current().info().key() == p.key() )
            lists[index].push_after( p, it.current().info() );
        else
            lists[index].push_front(p);
        
        return true;
        
    }//end IF
    
    cout<<endl<<"The name of the word should have at least two letters! (English Alphabet)"<<endl;
    
    return false;
    
}


//Gets the given pair specified index which is provided by HashFunction.
template <typename TPair>
TPair* HashTable<TPair>::get(TPair &p)
{
    int index = HashFunction( p.key() );
    
    Node<TPair>* found = lists[index].find(p);
    
    return ( index != -1 &&
            found != nullptr )? &found->info() : nullptr;
    
}



//Returns "LENGTH".
template <typename TPair>
int HashTable<TPair>::length() const
{
    return LENGTH;
}


