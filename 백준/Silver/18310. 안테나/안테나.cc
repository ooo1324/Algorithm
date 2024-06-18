#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, a;

    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end());

    cout << vec[(n - 1) /2];
   
    return 0;
}