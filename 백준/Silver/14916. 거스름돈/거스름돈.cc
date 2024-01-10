#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
int d[MAX] = {0, -1, 1, -1, 2, 1};
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    for (int i = 6; i <= n; i++)
    {
        if (i % 5 == 0) d[i] = i / 5;
        else
        {
            int i2 = d[i - 2] == -1 ? d[i - 5] : d[i - 2];
            int i5 = d[i - 5] == -1 ? d[i - 2] : d[i - 5];
            d[i] = min(i2, i5) + 1;
        }           
    }

    cout << d[n];

    return 0;
}
