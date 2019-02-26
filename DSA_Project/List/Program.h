#include "MultiMap.cpp"

class Program
{
    
private:
    char choice;
    MultiMap<string, string> map;
    
public:
    
    void ShowMenu();
    
    void AddWord();
    void FindWord();
    void DeleteWord();
    void ShowAllWords();
    void TotalNumberOfWords();
};
