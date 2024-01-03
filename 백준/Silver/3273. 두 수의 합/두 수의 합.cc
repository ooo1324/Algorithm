#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    cin >> x;

    sort(vec.begin(), vec.end());

    int left = 0, right = n - 1;
    int cnt = 0;

    while (left < right)
    {
        int value = vec[left] + vec[right];

        if (value == x)
        {
            cnt++;
            left++;
            right--;
        }
        else if (value > x)
            right--;
        else if (value < x)
            left++;
    }
    
    cout << cnt;
  
    return 0;
}
