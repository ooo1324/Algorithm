#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string code = "abcdefghijklmnopqrstuvwxyz";
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++)
    {
        bool check = false;
        vector<vector<int>> vec(26, vector<int>(2, 0));
        string str;
        getline(cin, str);
        
        for (int j = 0; j < str.size(); j++)
        {
            char ch = str[j];
            if (ch != ' ')
            {
                int askii = (int)ch - 97;
                vec[askii][0] += 1;
                vec[askii][1] = askii;
            }
        }

        sort(vec.begin(), vec.end());

        int maxValue = vec[vec.size() - 1][0];
        for (int j = vec.size() - 2; j >= 0; j--)
        {
            if (!check && vec[j][0] == maxValue)
            {
                check = true;
            }
        }

        int maxNode = vec[vec.size() - 1][1];
        cout << (check ? '?' : (char)(maxNode + 97)) << '\n';
    }

    return 0;
}