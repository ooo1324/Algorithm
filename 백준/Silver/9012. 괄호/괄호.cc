#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string str;
        vector<char> vec;
        bool check = true;
        cin >> str;

        for (auto st : str)
        {
            if (st == '(')
                vec.push_back(st);
            else if (st == ')')
            {
                if (vec.size() == 0)
                    check = false;
                else
                    vec.pop_back();
            }
                              
        }

        cout << (vec.size() == 0 && check ? "YES" : "NO") << '\n';
    }  
    return 0;
}