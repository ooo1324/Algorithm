#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    sort(vec.begin(), vec.end(), greater<int>());

    int result = 0;

    int i = 0;
    while (i < n - 2)
    {
        if (vec[i] < (vec[i + 1] + vec[i + 2]))
        {
            result += (vec[i] + vec[i + 1] + vec[i + 2]);
            break;
        }
        i++;
    }

    cout << (result == 0 ? -1 : result);

    return 0;
}