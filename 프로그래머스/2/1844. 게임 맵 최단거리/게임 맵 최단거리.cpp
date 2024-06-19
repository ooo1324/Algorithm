#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 101
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};
int visited[MAX][MAX];
int n, m;
void bfs(vector<vector<int>> &maps)
{
    n = maps.size();
    m = maps[0].size();
    queue<pair<int, int>> q;
    visited[0][0] += 1;
    q.push({0, 0});
    while(!q.empty())
    {
         for(int v= 0 ; v < 4; v++)
         {
             int x = q.front().first + move_x[v];
             int y = q.front().second+ move_y[v];
             
             if(x < 0 || x >= n || y <0 || y >= m)
                 continue;
             if(maps[x][y] > 0 && !visited[x][y])
             {   
                 visited[x][y] = visited[q.front().first][q.front().second] + 1;
                 q.push({x, y});
             }
         }
        q.pop();
    }
    
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    bfs(maps);
        
    answer = visited[n -1][m-1];
    
    return answer == 0 ? -1 : answer;
}