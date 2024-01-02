#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> graph[1001];
bool visited[1001];
int n, m;
int cnt;
void bfs()
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = true;
            cnt++;
        }
      
        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            sort(graph[x].begin(), graph[x].end());

            for (int j = 0; j < graph[x].size(); j++)
            {
                int node = graph[x][j];

                if (!visited[node])
                {
                    q.push(node);
                    visited[node] = true;
                }
            }

        }
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    cout << cnt;
        
    return 0;
}