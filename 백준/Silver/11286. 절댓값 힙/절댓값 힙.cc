#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct cmp
{
    bool operator()(int num1, int num2)
    {
        if (abs(num1) > abs(num2))
            return true;
        else if (abs(num1) == abs(num2))
        {
            if (num1 > num2)
                return true;
            else
                return false;
        }
        return false;
    }
};
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;

    priority_queue<int, vector<int>, cmp> p_queue;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        
        if (num != 0)
        {
            p_queue.push(num);
        }
        else
        {
            if (!p_queue.empty())
            {
                cout << p_queue.top() << '\n';
                p_queue.pop();
            }
            else
                cout << 0 << '\n';
        }
    }
    
    return 0;
}