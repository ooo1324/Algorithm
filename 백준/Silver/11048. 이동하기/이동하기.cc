#include <iostream>
using namespace std;
int d[1001][1001];
int n, m;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> d[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			d[i][j] += max(d[i][j - 1], d[i - 1][j]);
	
	cout << d[n][m];

	return 0;
}