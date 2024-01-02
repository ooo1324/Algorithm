#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 1e9;
using namespace std;
int graph[MAX][MAX];
int d[MAX][MAX];
int m, n;
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = { 0, 0, 1, -1 };
void dijkstra(int i, int j)
{
    queue<pair<int, int>> q;

    q.push({i, j});
    d[i][j] = graph[i][j];

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        for (int v = 0; v < 4; v++)
        {
            int next_x = x + move_x[v];
            int next_y = y + move_y[v];

            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
                continue;

            int currDist = d[x][y] + graph[next_x][next_y];
            if (currDist < d[next_x][next_y])
            {
                d[next_x][next_y] = currDist;
                q.push({next_x, next_y});
            }
        }
        q.pop();
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> m >> n;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            graph[i][j] = str[j] - '0';
            d[i][j] = INF;
        }
    }

    dijkstra(0, 0);

    cout << d[n - 1][m - 1];
    
    return 0;
}