#include <iostream>
using namespace std;
#define MAX 10001
double d[MAX];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> d[i];

	double answer = 0;

	for (int i = 1; i <= n; i++)
	{
		d[i] = max(d[i], d[i] * d[i - 1]);

		answer = max(answer, d[i]);
	}

	cout << fixed, cout.precision(3);

	cout << answer;
	return 0;
}