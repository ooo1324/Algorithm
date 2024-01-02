#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	int zero[41] = { 1, 0 };
	int one[41] = { 0, 1 };
	
	for (int i = 2; i < 41; i++)
	{
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		cout << zero[n] << ' ' << one[n] << '\n';
	}

	return 0;
}