#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    stack<int> num_stack;
    vector<char> out_vec;
    bool check = true;
    int preNum = 0;

    for (int i = 0; i < n; i++)
    {
        if (check)
        {
            int num;
            cin >> num;

            for (int j = preNum + 1; j <= num; j++)
            {
                num_stack.push(j);
                out_vec.push_back('+');
            }

            preNum = max(num, preNum);

            if (num_stack.top() == num)
            {
                out_vec.push_back('-');
                num_stack.pop();       
            }
            else
                check = false;
        }
    }

    if (check)
    {
        for (auto v : out_vec)
            cout << v << '\n';
    }
    else
        cout << "NO" << '\n';
    return 0;
}