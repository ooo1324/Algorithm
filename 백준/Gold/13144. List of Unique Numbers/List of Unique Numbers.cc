#include <iostream>
#include <algorithm>
#include <vector>
bool vis[100001];
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

    long long cnt = 0;
    int right = 0;
    for (int left = 0; left < n; left++)
    {
        while (right < n)
        {
            if (vis[vec[right]])
                break;
            vis[vec[right]] = true;
            right++;
        }
        cnt += (right - left);
        vis[vec[left]] = false;
    }

    cout << cnt;

    return 0;
}