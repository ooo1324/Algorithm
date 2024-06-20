#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sortVec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int,int>> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    
    sort(vec.begin(), vec.end(), sortVec);
    
    for (int i = 0; i < n; i++)
    {
        cout << vec[i].first << " " << vec[i].second << '\n';
    }

    return 0;
}