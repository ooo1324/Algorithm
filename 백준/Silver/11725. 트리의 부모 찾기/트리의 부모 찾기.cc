#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;
vector<int> graph[MAX];
int visited[MAX];
int d[MAX];
int n;
void bfs()
{
    queue<int> q;

    q.push(1);
    visited[1] = true;

    int pre_node = 0;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        //방문 노드

        for (int i = 0; i < graph[x].size(); i++)
        {
            int node = graph[x][i];
            if (!visited[node])
            {
                d[node] = x;
                q.push(node);
                visited[node] = true;
            }         
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    int a, b;
    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();
    
    for (int i = 2; i <= n; i++)
    {
        cout << d[i] << '\n';
    }

    return 0;
}