#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n= 0, count = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        vector<int> vec(26);
        string str;
        cin >> str;

        char pre_char = ' ';

        for (int j = 0; j < str.length(); j++)
        {
            if (pre_char != str[j])
                vec[str[j] % 97]++;

            pre_char = str[j];
        }
        
        int max = *max_element(vec.begin(), vec.end());

        if (max == 1)
            count++;
    }

    cout << count;

    return 0;
}