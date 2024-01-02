#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int GCD(int a, int b)
{
    if (b == 0) return a;
    else return GCD(b, a % b);
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a1, a2, b1, b2, ans1, ans2;
    
    cin >> a1 >> a2 >> b1 >> b2;
    
    ans1 = (a1 * b2) + (a2 * b1);
    ans2 = a2 * b2;
    
    int answer = GCD(ans1, ans2);
    
    cout << ans1/answer << " " << ans2/answer;
    
    return 0;
}