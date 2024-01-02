#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   
    int n;

    cin >> n;

    priority_queue<int> pq;

    int a, answer = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        pq.push(-a);
    }
 
    while (true)
    {
        if (pq.size() == 1)
            break;

        int pre_top = pq.top();
        pq.pop();
         
        int sum = pre_top + pq.top();
        pq.pop();

        answer += sum;
        pq.push(sum);
    }

    cout << -answer;

    return 0;
}