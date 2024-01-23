#include <iostream>
using namespace std;
#define MAX 31
long long d[MAX][MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int r, c, w;
    cin >> r >> c >> w;

    d[0][0] = 1;
    int result = 0;
    for (int i = 1; i < r + w - 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0) d[i][j] = 1;
            else
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }

    for (int i = r - 1; i < r + w - 1; i++)
    {
        for (int j = c -1 ; j <= c + i - r; j++)
        {
            result += d[i][j];
        }
    }

    cout << result;
    return 0;
}
