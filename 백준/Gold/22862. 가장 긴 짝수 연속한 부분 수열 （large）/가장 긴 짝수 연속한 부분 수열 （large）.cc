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

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int left = 0;
    int right = 0;
    int maxValue = 0;
    int cnt = 0;

    while (right < n)
    {
        if (cnt > k)
        {
            if (vec[left] % 2 == 1)
                cnt--;
            left++;
        }
        else
        {
            if (vec[right] % 2 == 1)
                cnt++;
            right++;
        }

        if (cnt <= k)
            maxValue = max(maxValue, right - left - cnt);
    }

    cout << maxValue;

    return 0;
}