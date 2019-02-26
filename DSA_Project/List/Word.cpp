#include <iostream>             //To use standart input(cin) and output(cout) functions.
#include <iomanip>              //To use setfill() and setw() functions.
#include "Word.h"               //To know Word Class' functions.

//Constructor Function without parameters.
Word::Word()
{
    name = "";
    definition = "";
}


//Constructor Function with parameters.
Word::Word(const string& givenName, const string& givenDefinition)
{
    name = givenName;
    definition = givenDefinition;
}


//Destructor Function.
Word::~Word()
{
    name = "";
    definition = "";
}





/*****      NAME    *****/
//Takes string input and assigns it to the "name".
Word& Word::AddName()
{
    cout<<endl<<"Please, enter the name!"<<endl;
    getline(cin, name );

    return *this;
}//end AddName()

//Returns "name".
string Word::GetName() const
{
    return name;
}//end GetName()

//Assigns the givenName to the "name".
Word& Word::SetName(const string& givenName)
{
    name = givenName;
    
    return *this;
}

//Prints the "name".
void Word::PrintName() const
{
    cout<<left<<setfill(' ')<<setw(40)<<"Name:"<<name<<endl;
}





/*****      DEFINITION      *****/
//Takes string input and assigns it to the "definition".
Word& Word::AddDefinition()
{
    cout<<endl<<"Please, enter the definition!"<<endl;
    getline(cin, definition);
    
    return *this;
}//end AddDefinition()

//Returns "definition".
string Word::GetDefinition() const
{
    return definition;
}

//Assigns the givenDefinition to the "definition".
Word& Word::SetDefinition(const string& givenDefinition)
{
    definition = givenDefinition;
    
    return *this;
}

//Prints the "definition".
void Word::PrintDefinition() const
{
    cout<<left<<setfill(' ')<<setw(40)<<"Definition:"<<definition<<endl;
}





/*****      PRINT      *****/
//Prints the word's name and definition.
void Word::PrintWord() const{
    
    cout
    <<"+------"<<endl
    <<left<<setfill(' ')<<setw(40)<<"| Name:"<<name<<endl
    <<left<<setfill(' ')<<setw(40)<<"| Definition:"<<definition<<endl
    <<"+------"<<endl;
}//end PrintWord()

//Prints name, definition, the address of this object.
void Word::PrintAllProperties() const
{
    cout
    <<"+------"<<endl
    <<left<<setfill(' ')<<setw(40)<<"| Name:"<<setw(50)<<name<<endl
    <<left<<setfill(' ')<<setw(40)<<"| Definition:"<<setw(200)<<definition<<endl
    <<left<<setfill(' ')<<setw(40)<<"| Address:"<<setw(50)<<this<<endl
    <<"+------"<<endl;
}





/*****      OPERATORS      *****/
//Returns true if they are equal.
bool Word::operator== (const Word& rightHandSide)
{
    return ( name == rightHandSide.name && definition == rightHandSide.definition) ? true : false;
}

//Returns true if they are NOT equal.
bool Word::operator!= (const Word& rightHandSide)
{
    return !(operator==(rightHandSide));
}
