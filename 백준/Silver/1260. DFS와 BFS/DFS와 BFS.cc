#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool dfs_visited[1001];
vector<int> dfs_graph[1001];
bool bfs_visited[1001];
vector<int> bfs_graph[1001];
void dfs(int x)
{
    // 노드 방문 정보 저장
    dfs_visited[x] = true;

    // 방문 노드 출력
    cout << x << " ";
    sort(dfs_graph[x].begin(), dfs_graph[x].end());
    for (int i = 0; i < dfs_graph[x].size(); i++)
    {
        int node = dfs_graph[x][i];
        if (!dfs_visited[node])
            dfs(node);
    }
}
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    bfs_visited[start] = true;



    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        // 방문 노드 출력
        cout << x << " ";

        sort(bfs_graph[x].begin(), bfs_graph[x].end());

        for (int i = 0; i < bfs_graph[x].size(); i++)
        {
            int node = bfs_graph[x][i];
            if (!bfs_visited[node])
            {
                q.push(node);
                bfs_visited[node] = true;
            }

        }
    }
   
 
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, m, v;

    cin >> n >> m >> v;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        dfs_graph[a].push_back(b);
        bfs_graph[a].push_back(b);
        dfs_graph[b].push_back(a);
        bfs_graph[b].push_back(a);
    }

    dfs(v);
    cout << endl;
    bfs(v);
    return 0;
}
 