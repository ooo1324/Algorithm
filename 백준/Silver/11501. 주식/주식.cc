#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n; 
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> vec(n);

        for (int j = 0; j < n; j++)
            cin >> vec[j];
        
        int max_value = 0;
        long long result = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (max_value < vec[j])
                max_value = vec[j];
            else
                result += max_value - vec[j];
        }

        cout << result << '\n';
    }

   

    return 0;
}