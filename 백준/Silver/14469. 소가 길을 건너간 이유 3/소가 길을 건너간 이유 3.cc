#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    
    for(int i = 0 ; i < n ; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    
    sort(vec.begin(), vec.end());
    
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cnt = max(vec[i].first, cnt);
        cnt += vec[i].second;
    }
    
    cout << cnt;
    return 0;
}


