#include <iostream>
using namespace std;
#define MAX 10001
int d[MAX];
int dp[MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 1; i <= n; i++)
    {
        dp[i] = d[i];
        for (int j = 1; j <= i; j++)
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
    }

    cout << dp[n];

    return 0;
}
