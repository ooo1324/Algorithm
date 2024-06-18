#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 201
int rows[4] = {-1, 1, 0 , 0};
int colms[4] = { 0, 0, -1, 1 };
int R = 0, C = 0, N = 0;
void checkBoom(vector<vector<char>> &vec1, vector<vector<char>>& vec2)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (vec1[i][j] == 'O')
            {
                vec2[i][j] = '.';
                for (int v = 0; v < 4; v++)
                {
                    int x = i + rows[v], y = j + colms[v];
                    if (x >= 0 && x < R && y >= 0 && y < C)
                        vec2[x][y] = '.';
                }
            }
        }
    }

 
}
void printVector(vector<vector<char>>& vec)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << vec[i][j];
        }
        cout << '\n';
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
  
    cin >> R >> C >> N;

    vector<vector<char>> boomArr(R, vector<char>(C, 'O'));
    vector <vector<char>> valueVec(R, vector<char>(C, 'O'));
    vector <vector<char>> valueVec2(R, vector<char>(C, 'O'));

    for (int i = 0; i < R; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++)
        {
            boomArr[i][j] = str[j];
        }
    }

    if (N == 1)
        printVector(boomArr);
    else if (N % 2 == 0)
        printVector(valueVec);
    else if ((N - 1) % 4 == 2)
    {
        checkBoom(boomArr, valueVec);
        printVector(valueVec);
    }
    else
    {
        checkBoom(boomArr, valueVec);
        checkBoom(valueVec, valueVec2);
        printVector(valueVec2);
    }
    return 0;
}
