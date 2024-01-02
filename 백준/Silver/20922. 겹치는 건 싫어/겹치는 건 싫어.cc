#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001
int d[MAX];
int check[MAX];
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> d[i];

	int left = 0;
	int right = 0;
	int maxValue = 0;

	while (true)
	{
		if (right >= n + 1)
		{
			maxValue = max(maxValue, right - left - 1);
			break;
		}

		if (check[d[right]] < k)
		{
			check[d[right]]++;
			right++;
		}
		else
		{
			maxValue = max(maxValue, right - left);
			
			check[d[left]]--;
			left++;	
		}
	}

	cout << maxValue;

	return 0;
}