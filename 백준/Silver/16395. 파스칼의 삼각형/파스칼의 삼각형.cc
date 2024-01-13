#include <iostream>
using namespace std;
#define MAX 31
long long d[MAX][MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    d[0][0] = 1;
 
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (j == 0) d[i][j] = 1;
            else
                d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
        }
    }

    cout << d[n - 1][k - 1];
    return 0;
}
