#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    vector<int> vec(2, 0);
   
    int cur_val = str[0] - '0';
    vec[cur_val] = 1;

    for (int i = 1; i < str.size(); i++)
    {
        int value = str[i] - '0';
        if (cur_val != value)
        {
            vec[value]++;
            cur_val = value;
        }         
    }
    
    cout << min(vec[0], vec[1]);

    return 0;
}