#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int> &a, const pair<int,int> &b)
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

    vector<pair<int, int>> vec(n);

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec[i] = { a, b };
    }

    sort(vec.begin(), vec.end(), cmp);

    int time = 0, result = 0;
   
    for (int i = 0; i < n; i++)
    {
        if (vec[i].first >= time)
        {
            time = vec[i].second;
            result++;
        }
    }

    cout << result;

    return 0;
}