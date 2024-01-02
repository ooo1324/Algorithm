#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
   
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec[i] = { a,b };
    }

    sort(vec.begin(), vec.end());

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> cur_pair = vec[i];
        pq.push(-cur_pair.second);

        if (-pq.top() <= cur_pair.first)
            pq.pop();
    }

    cout << pq.size();

    return 0;
}