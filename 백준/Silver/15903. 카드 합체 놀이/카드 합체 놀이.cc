#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    priority_queue<long long> pq;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        pq.push(-a);
    }
   
    for (int i = 0; i < m; i++)
    {
        long long pre_val = pq.top();
        pq.pop();
        long long sum = pq.top() + pre_val;
        pq.pop();

        pq.push(sum);
        pq.push(sum);
    }  

    long long sum = 0;

    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }

    cout << -sum;
   
    return 0;
}