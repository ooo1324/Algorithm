#include <iostream>
using namespace std;
#define MAX 1001
int d[MAX];
int dp[MAX];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> d[i];

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		int maxValue = 0;
		for (int j = 1; j < i; j++)
		{
			if (d[i] < d[j])
				maxValue = max(maxValue, dp[j]);
		}

		dp[i] = maxValue + 1;
		answer = max(dp[i], answer);
	}

	cout << answer;

	return 0;
}