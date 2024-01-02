#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int t, n, a, b;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        vector<pair<int, int>> vec(n);

        for (int j = 0; j < n; j++)
        {
            cin >> a >> b;

            vec[j] = { a, b };
        }

        sort(vec.begin(), vec.end());

        int a_min = 100001, b_min = 100001, count = 0;
        for (int j = 0; j < n; j++)
        {
            pair<int, int> cur_pair = vec[j];
            if (a_min > cur_pair.first || b_min > cur_pair.second)
            {
                a_min = min(a_min, cur_pair.first);
                b_min = min(b_min, cur_pair.second);
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}