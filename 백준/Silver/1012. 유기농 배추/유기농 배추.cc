#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
bool visited[51][51];
int graph[51][51];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, 1, -1 };
int cnt = 0;
int m, n, k;
void bfs()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = true;
                pair<int, int> p(i, j);
                q.push(p);

                cnt++;

                while (!q.empty())
                {
                    for (int v = 0; v < 4; v++)
                    {
                        int node_x = q.front().first + x_move[v];
                        int node_y = q.front().second + y_move[v];

                        if (node_x < 0 || node_x >= m || node_y < 0 || node_y >= n)
                            continue;
                       
                        if (graph[node_x][node_y] == 1 && !visited[node_x][node_y])
                        {
                            visited[node_x][node_y] = true;
                            pair<int, int> p(node_x, node_y);
                            q.push(p);
                        }
                    }
                    q.pop();
                }
            }
        }
    }

    cout << cnt << '\n';
}
void reset()
{
    cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> k;

        int a, b;

        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            graph[a][b] = 1;
        }

        bfs();
   
        reset();
    }

    return 0;
}
 