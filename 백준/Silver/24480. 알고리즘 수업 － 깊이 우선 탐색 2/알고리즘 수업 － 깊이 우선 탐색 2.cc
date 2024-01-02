#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 200001
int n;
int dfs_visited[MAX];
vector<int> dfs_graph[MAX];
int cnt = 1;
void dfs(int x)
{
    // 노드 방문 정보 저장
    dfs_visited[x] = cnt;
    cnt++;

    sort(dfs_graph[x].begin(), dfs_graph[x].end(), greater<int>());
    for (int i = 0; i < dfs_graph[x].size(); i++)
    {
        int node = dfs_graph[x][i];
        if (dfs_visited[node] == 0)
            dfs(node);
    }
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    int n, m, r;
    cin >> n >> m >> r;

    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        dfs_graph[a].push_back(b);
        dfs_graph[b].push_back(a);
        dfs_visited[i] = 0;
    }

    dfs(r);

    for (int i = 1; i <= n; i++)
    {
        cout << dfs_visited[i] << '\n';
    }
	return 0;
}