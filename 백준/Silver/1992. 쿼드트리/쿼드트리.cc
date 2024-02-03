#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 65
using namespace std;
int d[MAX][MAX];
void compress(int n, int y, int x)
{
    if (n == 1)
    {
        cout << d[y][x];
        return;
    }

    bool exist0 = false;
    bool exist1 = false;

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (d[i][j] == 0)
                exist0 = true;
            else
                exist1 = true;

            if (exist0 && exist1)
                break;
        }
        if (exist0 && exist1)
            break;
    }

    if (exist0 && exist1)
    {
        cout << '(';
        compress(n / 2, y, x);
        compress(n / 2, y, x + n / 2);
        compress(n / 2, y + n / 2, x);
        compress(n / 2, y + n / 2, x + n / 2);
        cout << ')';
    }
    else if (exist0)
        cout << 0;
    else
        cout << 1;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
            d[i][j] = str[j] - '0';
    }

    compress(n, 0, 0);

    return 0;
}
