#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 2000000001
int main()

{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)

        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int left = 0;
    int right = 1;
    int minValue = 2000000001;

    while (right < n)
    {
        int value = vec[right] - vec[left];

        if (m <= value)
        {
            left++;
            minValue = min(minValue, value);
            if (m == 0)
                right++;
        }
        else
            right++;
    }

    cout << minValue;

    return 0;
}