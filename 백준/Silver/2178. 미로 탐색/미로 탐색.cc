#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int visited[101][101];
int graph[101][101];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, 1, -1 };
int cnt = 0;
int m, n;
void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    visited[i][j] += 1;
    q.push(make_pair(i, j));

    while (!q.empty())
    {
        for (int v = 0; v < 4; v++)
        {
            int node_x = q.front().first + x_move[v];
            int node_y = q.front().second + y_move[v];

            if (node_x < 0 || node_x >= n || node_y < 0 || node_y >= m)
                continue;

            if (graph[node_x][node_y] > 0 && !visited[node_x][node_y])
            {
                visited[node_x][node_y] = visited[q.front().first][q.front().second] + 1;
                q.push(make_pair(node_x, node_y));
            }
        }
        q.pop();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;

    string a;
    for (int j = 0; j < n; j++)
    {
        cin >> a;

        for (int i = 0; i < m; i++)
        { 
            graph[j][i] = a[i] - '0';
        }
    }

    bfs(0, 0);

    cout << visited[n - 1][m - 1];

    return 0;
}
 