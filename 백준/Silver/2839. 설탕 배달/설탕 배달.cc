#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;

    cin >> n;
    
    int cnt = 0;
    int num = 0;

    while (true)
    {
        if (n == 0) break;

        if (n % 5 == 0)
            num = 5;
        else if (n % 3 == 0)
            num = 3;
        else if (5 <= n)
            num = 5;
        else if (3 <= n)
            num = 3;
        else
            break;

        cnt++;
        n -= num;
    }
    
    cout << (n == 0 ? cnt : -1);
    

    return 0;
}