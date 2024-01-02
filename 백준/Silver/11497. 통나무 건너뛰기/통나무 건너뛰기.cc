#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, result = 0; 
        cin >> n;
        vector<int> vec(n);
 
        for (int j = 0; j < n; j++)
            cin >> vec[j];

        sort(vec.begin(), vec.end());

        for (int i = 0; i < vec.size() - 2; i++) 
            result = max(result, abs(vec[i] - vec[i + 2]));
        
        cout << result << '\n';
    }
    

    return 0;
}