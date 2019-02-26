#include <iostream>                     //To use standart input(cin) and output(cout) functions.
#include <iomanip>                      //To use setfill() and setw() functions.

#include "Program.h"                    //To know Program Class' functions.
#include "Word.h"                       //To create Word variables.

using namespace std;                    //Input and output functions under the std namespace.


void Program::ShowMenu()
{
    do {
        cout
        <<endl
        <<"(A)dd"<<endl
        <<"(F)ind 'Search'"<<endl
        <<"(D)elete"<<endl
        <<"(S)how All"<<endl
        <<"(N)umber Of Elements"<<endl
        <<"(E)xit"<<endl
        <<endl;
        
        cout<<"Please, enter the first letter of the operation!\t\t";
        cin>>choice;
        cin.clear();
        cin.get();
        
        choice = toupper( choice );
        
        
        if(choice == 'A')
            AddWord();
        else if(choice == 'F')
            FindWord();
        else if(choice == 'D')
            DeleteWord();
        else if(choice == 'S')
            ShowAllWords();
        else if(choice == 'N')
            TotalNumberOfWords();
        
    } while (choice != 'E');
    
}

void Program::AddWord()
{
    
    Word w;
    w.AddName().AddDefinition();
    
    map.insert( w.GetName(), w.GetDefinition() );
    
}

void Program::FindWord()
{
    if ( map.size() != 0 )
    {
        Word w;
        w.AddName();
        
        SinglyLinkedList<Pair<string, string>> sll = map.find(w.GetName());
        
        if ( sll.size() != 0)
        {
            cout<<endl<<"Found"<<endl;
            
            SSLIterator<Pair<string, string>> it(&sll);
            
            cout
            <<"+--------------              -------------+"<<endl
            <<"+-----               ITEMS           -----+"<<endl
            <<"+--------------              -------------+"<<endl;
            
            while( it.valid() )
            {
                cout
                <<"+-----"<<endl
                <<left<<setfill(' ')<<setw(40)<<"| Key:"<<setw(50)<<it.current().info().key()<<endl
                <<left<<setfill(' ')<<setw(40)<<"| Info:"<<setw(50)<<it.current().info().value()<<endl
                <<"+-----"<<endl;
                
                it++;
            }
        }
        else
            cout<<endl<<"NOT Found!"<<endl;
        
    }
    else
        cout<<endl<<"There is no item!"<<endl;
    
}

void Program::DeleteWord()
{
    if ( map.size() != 0 )
    {
        Word w;
        w.AddName().AddDefinition();
        
        cout
        <<endl<<endl
        <<( map.remove(w.GetName(), w.GetDefinition()) ? "\nDeleted!\n" :"\nIs Not Deleted!\n")
        <<endl<<endl;
    }
    else
        cout<<endl<<"There is no item!"<<endl;
}

void Program::ShowAllWords()
{
    if( map.size() != 0 )
    {
        MMAPIterator<string, string> it(map);
        
        cout
        <<"+--------------           ----------------+"<<endl
        <<"+-----       MULTI       MAP         -----+"<<endl
        <<"+--------------           ----------------+"<<endl;
        
        while( it.valid() )
        {
            cout
            <<"+-----"<<endl
            <<left<<setfill(' ')<<setw(40)<<"| Key:"<<setw(50)<<it.current().info().key()<<endl
            <<left<<setfill(' ')<<setw(40)<<"| Info:"<<setw(50)<<it.current().info().value()<<endl
            <<"+-----"<<endl;
            
            it++;
        }
    }
    else
        cout<<endl<<"There is no item!"<<endl;
}

void Program::TotalNumberOfWords()
{
    cout
    <<endl
    <<left<<setfill(' ')<<setw(40)<<"Number Of Elements:"<<setw(30)<<map.size()
    <<endl;
}
