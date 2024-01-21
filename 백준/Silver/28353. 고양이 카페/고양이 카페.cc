#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i = 0; i < vec.size(); i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	int left = 0, right = n - 1;
	int cnt = 0;

	while (right > left)
	{
		int value = vec[right] + vec[left];

		if (value > k)
		{
			right--;
		}
		else
		{
			right--;
			left++;
			cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}