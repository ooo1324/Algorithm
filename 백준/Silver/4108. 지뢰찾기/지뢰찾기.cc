#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 101
int R = 0, C = 0;
char boomArr[MAX][MAX];
int move_x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int move_y[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void checkBoom(int i, int j)
{
    if (boomArr[i][j] == '*')
    {
        cout << '*';
        return;
    }

    int sumValue = 0;
    for (int v = 0; v < 8; v++)
    {
        int x = i + move_x[v];
        int y = j + move_y[v];

        if (x < 0 || x >= R || y < 0 || y >= C)
            continue;

        if (boomArr[x][y] == '*')
            sumValue++;
    }

    cout << sumValue;

}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true)
    {
        cin >> R >> C;

        if (R == 0 && C == 0)
            break;


        for (int i = 0; i < R; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < C; j++)
            {
                boomArr[i][j] = str[j];
            }  
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                checkBoom(i, j);
            }
            cout << '\n';
        }
    }
    
    return 0;
}
