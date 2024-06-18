#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N = 0;
    cin >> N;
    vector<int> vec(N);
 
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    cout << vec[(N - 1) / 2];
    return 0;
}
