#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAX 126
#define INF 1e9;
using namespace std;
int graph[MAX][MAX];
int d[MAX][MAX];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, 1, -1 };
int n;
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
            int next_x = x + x_move[v];
            int next_y = y + y_move[v];

            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
                continue;

            int nextDist = d[x][y] + graph[next_x][next_y];
            if (nextDist < d[next_x][next_y])
            {
                d[next_x][next_y] = nextDist;
                q.push({next_x, next_y});
            }
        }
        q.pop();

    }

}
void initGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
            d[i][j] = INF;
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cnt = 0;

    while (true)
    {
        cin >> n;

        if (n == 0)
            break;

        initGraph();
        cnt++;
        int k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> k;
                graph[i][j] = k;
            }
        }

        dijkstra(0, 0);

        cout << "Problem " << cnt << ": " << (int)d[n - 1][n - 1] << '\n';
    }

    return 0;
}