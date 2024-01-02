#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int d[1001];
	int dp[1001];

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> d[i];

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		int maxVal = 0;
		for (int j = 0; j < i; j++)
		{
			if (d[i] > d[j])
				maxVal = max(maxVal, dp[j]);
		}

		dp[i] = maxVal + 1;
		answer = max(dp[i], answer);
	}


	cout << answer;

	return 0;
}