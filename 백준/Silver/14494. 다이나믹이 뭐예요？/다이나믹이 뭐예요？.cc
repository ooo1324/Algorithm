#include <iostream>
using namespace std;
#define MAX 1001
long long d[MAX][MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    d[0][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = (d[i - 1][j] + d[i][j - 1] + d[i - 1][j - 1]) % 1000000007;
  
    cout << d[n][m];
    return 0;
}
