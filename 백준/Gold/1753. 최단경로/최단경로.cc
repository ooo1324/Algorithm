#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;
vector<pair<int, int>> graph[20001];
int d[20001];
int v, e;
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, start));
    d[start] = 0;

    while (!pq.empty())
    {
        //최단 거리가 가장 짧은 노드 꺼내기

        //출발 노드에서 현재 노드까지의 거리
        int currDist = -pq.top().first;

        //현재 노드 번호
        int currNum = pq.top().second;
        pq.pop();

        if (currDist > d[currNum]) continue;

        for (int i = 0; i < graph[currNum].size(); i++)
        {
            int nextNum = graph[currNum][i].first;
            int nextDist = currDist + graph[currNum][i].second;

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

    int k;

    cin >> v >> e >> k;

    fill_n(d, v + 1, INF);

    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    dijkstra(k);

    for (int i = 1; i <= v; i++)
    {
        if(d[i] == INF)
            cout << "INF" << '\n';
        else
            cout << d[i] << '\n';
    }
    

    return 0;
}


