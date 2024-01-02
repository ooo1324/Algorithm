#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Compare(string &a, string &b)
{
    if (a.length() == b.length())
        return a < b;
    else return a.length() < b.length();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;

    vector<string> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end(), Compare);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (auto i : vec)
        cout << i << '\n';

    return 0;
}