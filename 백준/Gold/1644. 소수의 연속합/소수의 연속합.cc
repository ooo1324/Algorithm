#include <iostream>
#include <vector>
using namespace std;
#define MAX 4000001
bool d[MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }
      
    for (int i = 0; i <= n; i++)
        d[i] = true;

    d[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (!d[i]) continue;

        for (int j = i + i; j <= n; j += i)
            d[j] = false;
    }

    vector<int> vec;

    for (int i = 2; i <= n; i++)
    {
        if(d[i])
            vec.push_back(i);
    }

    int left = 0, right = 0, sum = 0, cnt = 0, size = vec.size();

    while (right <= size)
    {
        if (sum >= n)
        {
            sum -= vec[left];
            left++;
        }

        if (sum < n)
        {
            sum += vec[right];
            right++;
        }

        if (sum == n)
            cnt++;
    }
    
    cout << cnt;
    return 0;
}