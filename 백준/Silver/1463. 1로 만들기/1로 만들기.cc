#include <iostream>
#include <algorithm>
using namespace std; 
int d[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;

		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);

		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
	}
	
	cout << d[n];

	return 0;
}              