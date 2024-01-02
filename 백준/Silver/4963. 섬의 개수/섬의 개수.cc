#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int h, w;
int graph[51][51];
int visited[51][51];
int move_x[8]{ -1, 1, 0, 0, -1, 1, -1 , 1 };
int move_y[8]{ 0, 0, -1, 1, -1, 1, 1, -1 };

void bfs(int& cnt)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (graph[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = true;
                q.push(make_pair(i, j));

                cnt++;
                while (!q.empty())
                {
                    for (int v = 0; v < 8; v++)
                    {
                        int node_x = q.front().first + move_x[v];
                        int node_y = q.front().second + move_y[v];

                        if (node_x < 0 || node_x >= h || node_y < 0 || node_y >= w)
                            continue;

                        if (graph[node_x][node_y] == 1 && !visited[node_x][node_y])
                        {
                            visited[node_x][node_y] = true;
                            q.push(make_pair(node_x, node_y));
                        }
                    }

                    q.pop();
                }
            }
        }
    }
}


void initGraph()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            graph[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> w >> h;

        if (h == 0 && w == 0) break;

        initGraph();

        int a;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> a;
                graph[i][j] = a;
            }
        }

        int cnt = 0;

        bfs(cnt);

        cout << cnt << '\n';
    }

    return 0;
}
