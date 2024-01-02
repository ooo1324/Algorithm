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

    vector<int> vec;
    vector<int> dist_vec;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }

    for (int i = 1; i < n; i++)
    {
        dist_vec.push_back(vec[i] - vec[i - 1]);
    }

    sort(dist_vec.begin(), dist_vec.end(), greater<int>());

    int sum = 0;
    for (int i = k - 1; i < dist_vec.size(); i++)
    {
        sum += dist_vec[i];
    }
    
    cout << sum;
    
    return 0;
}