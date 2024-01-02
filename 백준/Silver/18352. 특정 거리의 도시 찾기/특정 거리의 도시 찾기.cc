#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define MAX 300001
using namespace std;
vector<pair<int, int>> graph[MAX];
int d[MAX];
int n, m;
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, start));
    d[start] = 0;

    while (!pq.empty())
    {
        int currDist = -pq.top().first;
        int currNum = pq.top().second;

        pq.pop();

        if (currDist > d[currNum]) continue;

        for (int i = 0; i < graph[currNum].size(); i++)
        {
            int nextNum = graph[currNum][i].second;
            int nextDist = currDist + graph[currNum][i].first;

            if (nextDist < d[nextNum])
            {
                d[nextNum] = nextDist;
                pq.push(make_pair(-nextDist, nextNum));
            }
        }

    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int k, x;
    cin >> n >> m >> k >> x;

    fill_n(d, n + 1, INF);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(make_pair(1, b));
    }

    dijkstra(x);

    bool checkK = false;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == k)
        {
            cout << i << '\n';
            checkK = true;
        }  
    }

    if (!checkK) cout << -1;

   return 0;
}
