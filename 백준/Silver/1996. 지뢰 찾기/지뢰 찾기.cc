#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001
char boomArr[MAX][MAX];
char valueArr[MAX][MAX];
int n = 0;
int check_x[8]{ 1, -1, 0, 0, 1, -1, 1, -1 };
int check_y[8]{ 0, 0, 1, -1, 1, -1, -1, 1 };
void checkBoom(int i, int j)
{
    if (boomArr[i][j] != '.')
    {
        valueArr[i][j] = '*';
        return;
    }

    int sumValue = 0;
    for (int v = 0; v < 8; v++)
    {
        int x = i + check_x[v];
        int y = j + check_y[v];

        if (x < 0 || x >= n || y < 0 || y >= n)
            continue;

        if(boomArr[x][y] != '.')
            sumValue += (boomArr[x][y] - '0');
    }

    valueArr[i][j] = sumValue >= 10 ? 'M' : sumValue + '0';
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            boomArr[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            checkBoom(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << valueArr[i][j];
        }
        cout << '\n';
    }

    return 0;
}
