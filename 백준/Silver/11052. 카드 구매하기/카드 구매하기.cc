#include <iostream>
#include <algorithm>
using namespace std; 
int d[1001];
int dp[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> d[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i - j] + d[j], dp[i]);
	
	cout << dp[n];

	return 0;
}              