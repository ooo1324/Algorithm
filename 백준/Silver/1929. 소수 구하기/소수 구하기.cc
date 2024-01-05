#include <iostream>
using namespace std;
#define MAX 1000001
bool d[MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> m >> n;

    for (int i = 2; i <= n; i++)
        d[i] = true;

    d[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (!d[i]) continue;

        for (int j = i + i; j <= n; j += i)
            d[j] = false;
    }
    
    for (int i = m; i <= n; i++)
    {
        if (d[i])
            cout << i << '\n';
    }

    return 0;
}
