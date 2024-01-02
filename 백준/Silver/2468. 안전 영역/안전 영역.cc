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
int max_cnt;
void bfs(int node)
{
    queue<pair<int,int>> q;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] >= node && !visited[i][j])
            {
                visited[i][j] = true;
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

                        if (graph[node_x][node_y] >= node && !visited[node_x][node_y])
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

    max_cnt = max(cnt, max_cnt);   
}
void Init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> vec;
    cin >> n;

    int a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            graph[i][j] = a;
            vec.push_back(a);
        }
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        bfs(vec[i]);
        Init();
    }

    cout << max_cnt;
   
    return 0;
}