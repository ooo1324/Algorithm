#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
bool visited[51][51];
int graph[51][51];
int x_move[4] = { 1, -1, 0, 0 };
int y_move[4] = { 0, 0, 1, -1 };
int cnt = 0;
vector<int> vec;
int n;
void bfs()
{
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = true;
                pair<int, int> p(i, j);
                q.push(p);

                cnt++;

                vec.push_back(1);

                while (!q.empty())
                {
                    for (int v = 0; v < 4; v++)
                    {
                        int node_x = q.front().first + x_move[v];
                        int node_y = q.front().second + y_move[v];

                        if (node_x < 0 || node_x >= n || node_y < 0 || node_y >= n)
                            continue;

                        if (graph[node_x][node_y] == 1 && !visited[node_x][node_y])
                        {
                            visited[node_x][node_y] = true;
                            pair<int, int> p(node_x, node_y);
                            q.push(p);
                            vec[cnt - 1] += 1;
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

    cin >> n;

    int a, b;

    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = st[j] - '0';
        }

    }

    bfs();

    cout << cnt << '\n';
    sort(vec.begin(), vec.end());

    for (int i = 0; i < cnt; i++)
        cout << vec[i] << '\n';

    return 0;
}