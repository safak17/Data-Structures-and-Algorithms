#ifndef Word_h
#define Word_h

#include <string>               //To have string variables.
using namespace std;            //String objects under the std namespace.


class Word
{
private:
    string name;
    string definition;
    
    
public:
    
    //Constructor Function.
    Word();
    
    //Constructor Function with parameters.
    Word(const string& givenName, const string& givenDefinition);
    
    //Destructor Function.
    ~Word();
    
    
    
    
    
//NAME
    //Takes string input and assigns it to the "name".
    Word& AddName();
    //Returns "name".
    string GetName() const;
    //Assigns the givenName to the "name".
    Word& SetName(const string& givenName);
    //Prints the "name".
    void PrintName() const;
    
    
    
    
    
//DEFINITION
    //Takes string input and assigns it to the "definition".
    Word& AddDefinition();
    //Returns "definition".
    string GetDefinition() const;
    //Assigns the givenDefinition to the "definition".
    Word& SetDefinition(const string& givenDefinition);
    //Prints the "definition".
    void PrintDefinition() const;
    
    
    
    
    
//PRINT
    //Prints the word's name and definition.
    void PrintWord() const;
    //Prints name, definition, the address of this object and next*.
    void PrintAllProperties() const;
    
    
    
    
    
//OPERATORS
    //Returns true if they are equal.
    bool operator== (const Word& rightHandSide);
    
    //Returns true if they are NOT equal.
    bool operator!= (const Word& rightHandSide);
};

#endif
