#include <iostream>                         //To use standard input(cin) and output(cout) functions.
using namespace std;

//TEST
//
//#include "MultiMap.cpp"
//#include "MMAPIterator.h"
//#include "Pair.h"
//#include <iomanip>
//
//typedef Pair<string,string> TPair;
//
//void print(SinglyLinkedList<TPair>& sll)
//{
//    SSLIterator<TPair> it(&sll);
//    
//    cout
//    <<"+--------------              -------------+"<<endl
//    <<"+-----       SINGLY LINKED LIST      -----+"<<endl
//    <<"+--------------              -------------+"<<endl;
//    
//    while( it.valid() )
//    {
//        cout
//        <<"+-----"<<endl
//        <<left<<setfill(' ')<<setw(40)<<"| Key:"<<setw(50)<<it.current().info().key()<<endl
//        <<left<<setfill(' ')<<setw(40)<<"| Info:"<<setw(50)<<it.current().info().value()<<endl
//        <<"+-----"<<endl;
//        
//        it++;
//    }
//}
//
//
//void print(MultiMap<string, string> &m)
//{
//    MMAPIterator<string, string> it(m);
//    
//    cout
//    <<"+--------------           ----------------+"<<endl
//    <<"+-----       MULTI       MAP         -----+"<<endl
//    <<"+--------------           ----------------+"<<endl;
//    
//    while( it.valid() )
//    {
//        cout
//        <<"+-----"<<endl
//        <<left<<setfill(' ')<<setw(40)<<"| Key:"<<setw(50)<<it.current().info().key()<<endl
//        <<left<<setfill(' ')<<setw(40)<<"| Info:"<<setw(50)<<it.current().info().value()<<endl
//        <<"+-----"<<endl;
//        
//        it++;
//    }
//}
//
//
//int main()
//{
//    MultiMap<string, string> map;
//    
//    map.insert("key", "anahtar");
//    map.insert("key", "a");
//    map.insert("key", "delik");
//    map.insert("key", "hole");
//    
//    map.insert("data", "veri");
//    map.insert("data", "veri");
//    map.insert("data", "v");
//    map.insert("data", "e");
//    
//    map.insert("search", "arama");
//    map.insert("sea", "deniz");
//    
//    print(map);
//    
//    
//    map.remove("data", "veri");
//    map.remove("search", "arama");
//    cout<<endl<<"REMOVED ITEMS"<<endl;
//    
//    cout
//    <<endl<<"data, veri"
//    <<endl<<"search, arama"<<endl;
//    
//    cout<<endl<<"AFTER REMOVE"<<endl;
//    print(map);
//    
//    
//    cout<<"COUNT"<<endl;
//    cout<<map.count("key")<<endl;
//    
//    
//    map.clear();
//    cout<<"AFTER CLEAR"<<endl;
//    print(map);
//    
//    
//    cout<<"COUNT"<<endl;
//    cout<<map.count("data")<<endl;
//    
//    return 0;
//
//}



#include "Program.h"
#include <list>
int main()
{
    list<int> a;
    list<int>::iterator it;
    
    return 0;
}
