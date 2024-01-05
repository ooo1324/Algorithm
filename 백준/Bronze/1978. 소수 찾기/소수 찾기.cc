#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    int num = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (a > 1)
        {
            bool check = false;
            for (int i = 2; i < a; i++)
            {
                if (a % i == 0)
                    check = true;
            }
            if (!check) num++;
        }    
    }

    cout << num;
    return 0;
}