#include <iostream>
#include <algorithm>
using namespace std; 
int d[501][501];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> d[i][j];
        }
    }

    int maxValue = d[0][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
                d[i][j] = d[i][j] + d[i - 1][j - 1];
            else if (j == 0)
                d[i][j] = d[i][j] + d[i - 1][j];
            else
                d[i][j] = d[i][j] + max(d[i - 1][j - 1], d[i - 1][j]);

            if(i == n - 1)
                maxValue = max(maxValue, d[i][j]);
        }
    }
    
    cout << maxValue;

    return 0;
}