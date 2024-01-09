#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
int d[MAX] = {0, 1, 1, 2, 2, 1, 2, 1};
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    

    for (int i = 8; i <= n; i++)
    {
        if (i % 7 == 0) d[i] = i / 7;
        else
            d[i] = min({ d[i - 1], d[i - 2], d[i - 5] }) + 1;
    }

    cout << d[n];

    return 0;
}
