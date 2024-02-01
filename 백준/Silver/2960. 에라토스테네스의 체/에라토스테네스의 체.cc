#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    bool d[1001];
    for (int i = 2; i <= n; i++)
        d[i] = false;

    int addValue, cnt = 0, answer = 0;

    for (int i = 2; i <= n; i++)
    {
        if (!d[i])
        {
            addValue = i;
            for (int j = i; j <= n; j += addValue)
            {
                if (!d[j])
                {
                    d[j] = true;
                    cnt++;

                    if (cnt == k)
                    {
                        answer = d[j];
                        cout << j;
                        return 0;
                    }

                }
            }
        }
    }

    return 0;
}