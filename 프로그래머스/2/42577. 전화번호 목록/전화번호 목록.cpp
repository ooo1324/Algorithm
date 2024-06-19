#include <string>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_map<string, bool> m;
 
   for(int i = 0; i< phone_book.size() ; i++)
    {
        m.insert({phone_book[i], true});
    }
    
    for(int i = 0; i< phone_book.size() ; i++)
    {    
        string number = "";
        string str = phone_book[i];
        for(int j =0; j < str.size(); j++)
        {
            number += str[j];
            if(m[number] && str != number)
                return false;
        }
    }
    
    return true;
}