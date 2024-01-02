#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	if ((a.first - a.second) < (b.first - b.second)) 
		return true;
	return false;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;

	vector<pair<int, int>> vec;
	int p, q;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> q;
		vec.push_back({ p, q });
	}

	sort(vec.begin(), vec.end(), comp);

	long long answer = 0;

	for (int i = 0; i < a; i++)
		answer += vec[i].first;

	for (int i = a; i < n; i++)
		answer += vec[i].second;

	cout << answer;

	return 0;
}