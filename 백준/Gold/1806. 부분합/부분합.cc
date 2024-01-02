#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
long long d[MAX];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, s, a;
	cin >> n >> s;

	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		d[i] = d[i - 1] + a;
	}

	int left = 0;
	int right = 1;
	int minValue = MAX;

	while (right <= n)
	{
		long long sum = d[right] - d[left];

		if (sum >= s)
		{
			left++;
			minValue = min(minValue, right - left);
		}
		else
			right++;
	}

	cout << (minValue == MAX ? 0 : minValue + 1);

	return 0;
}