#include <iostream>
#include <algorithm>
using namespace std; 
int d[100001];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, a;
    cin >> n;

    int maxValue = -100001;
    int curValue = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        curValue = max(curValue + d[i], d[i]);
        maxValue = max(maxValue, curValue);
    }

    cout << maxValue;
 
    return 0;
}