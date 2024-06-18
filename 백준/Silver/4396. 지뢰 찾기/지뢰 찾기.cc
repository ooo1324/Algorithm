#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 11
int n;
char boomArr[MAX][MAX];
char clickArr[MAX][MAX];
int Mx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int My[8] = { -1, 1, 0, -1, 1, -1, 1, 0 };
bool isBoom = false;
void checkBoom(int i, int j)
{
    if (clickArr[i][j] != 'x')
        return;

    if (boomArr[i][j] == '*')
    {
        isBoom = true;
        return;
    }    

    int value = 0;
    for(int v = 0; v < 8; v++)
    {
        int x = i + Mx[v];
        int y = j + My[v];

        if (x < 0 || x >= n || y < 0 || y >= n)
            continue;

        if (boomArr[x][y] == '*')
            value++;
    }

    clickArr[i][j] = value + '0';
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
            boomArr[i][j] = str[j];
    }

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
            clickArr[i][j] = str[j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            checkBoom(i, j);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isBoom && boomArr[i][j] == '*')
            {
                cout << '*';
            }
            else
                cout << clickArr[i][j];
        } 
        cout << '\n';
    }

    return 0;
}
