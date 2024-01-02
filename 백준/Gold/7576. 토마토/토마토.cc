#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int visited[1001][1001];
int graph[1001][1001];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, 1, -1 };
int m, n;
void bfs()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 1 && !visited[i][j])
            {
                q.push(make_pair(i,j));      
                visited[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        for (int v = 0; v < 4; v++)
        {
            int node_x = q.front().first + x_move[v];
            int node_y = q.front().second + y_move[v];

            if (node_x < 0 || node_x >= n || node_y < 0 || node_y >= m)
                continue;

            if (graph[node_x][node_y] == -1)
                continue;

            if (graph[node_x][node_y] == 0 && visited[node_x][node_y] == 0)
            {
                visited[node_x][node_y] = visited[q.front().first][q.front().second] + 1;
                pair<int, int> p(node_x, node_y);
                q.push(p);
            }
        }
        q.pop();
    }

}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;

    int node, result = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> node;
            graph[i][j] = node;
            if (node == -1)
                visited[i][j] = -1;
            else if (node == 0)
                result = 0;
        }
    }

    if (result != 0)
    {
        cout << 0;
        return 0;
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (result == -1)
                continue;

            if (visited[i][j] == 0)
                result = -1;
            else if(visited[i][j] > result)
            {
                result = visited[i][j];
            }
        }
    }

    cout << (result == -1 ? result : result - 1);
    
    return 0;
}