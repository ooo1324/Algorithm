#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int graph[101][101];
bool visited[101][101];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, 1, -1 };
int n;
void bfs(int &cnt)
{
    queue<pair<int,int>> q;
    int curr_node;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0 && !visited[i][j])
            {
                visited[i][j] = true;
                curr_node = graph[i][j];
                q.push(make_pair(i, j));
                cnt++;

                while (!q.empty())
                {
                    for (int v = 0; v < 4; v++)
                    {
                        int node_x = q.front().first + x_move[v];
                        int node_y = q.front().second + y_move[v];

                        if (node_x < 0 || node_x >= n || node_y < 0 || node_y >= n)
                            continue;

                        if (graph[node_x][node_y] == curr_node && !visited[node_x][node_y])
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
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cnt_normal = 0, cnt_rg = 0;;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j < n; j++)
        {
            int node = st[j] == 'R' ? 1 : (st[j] == 'B' ? 2 : 3);
            graph[i][j] = node;
        }
    }

    bfs(cnt_normal);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int node = graph[i][j];
            visited[i][j] = 0;
            graph[i][j] = node == 3 ? 1 : node;
        }
    }

    bfs(cnt_rg);

    cout << cnt_normal << ' ' << cnt_rg;
        
    return 0;
}