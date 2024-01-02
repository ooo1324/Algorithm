#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;

    vector<int> vec1(n);

    for (int i = 0; i < n; i++)
        cin >> vec1[i];

    vector<int> vec2(vec1.begin(), vec1.end());

    sort(vec1.begin(), vec1.end());

    vec1.erase(unique(vec1.begin(), vec1.end()), vec1.end());

    for (int i = 0; i < n; i++)
    {
        cout << distance(vec1.begin(), lower_bound(vec1.begin(), vec1.end(), vec2[i])) << " ";
    }

    return 0;
}