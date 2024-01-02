#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int d[10001];
	int dp[10001];

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> d[i];

	dp[0] = 0;
	dp[1] = d[1];
	dp[2] = d[1] + d[2];

	for (int i = 3; i <= n; i++)
		dp[i] = max(dp[i - 3] + d[i - 1] + d[i], max(dp[i - 2] + d[i], dp[i - 1]));
	
	cout << dp[n];

	return 0;
}