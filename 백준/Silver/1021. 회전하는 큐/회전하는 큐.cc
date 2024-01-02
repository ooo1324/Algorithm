#include <stdio.h>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
        
    int n = 0, m = 0, num = 0, count = 0;
    cin >> n >> m;

    deque<int> deq;

    for (int i = 1; i <= n; i++)
        deq.push_back(i);

    for (int i = 0; i < m; i++)
    {
        cin >> num;

        while (true)
        {
            if (deq.front() == num)
            {
                deq.pop_front();
                break;
            }
            int size = deq.size();
            int idx = find(deq.begin(), deq.end(), num) - deq.begin();

            if (idx <= size / 2)
            {
                deq.push_back(deq.front());
                deq.pop_front();
            }
            else
            {
                deq.push_front(deq.back());
                deq.pop_back();
            }
            count++;
        }
    }

    cout << count;

    return 0;
}