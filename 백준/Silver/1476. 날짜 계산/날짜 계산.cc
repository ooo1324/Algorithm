#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int e, s, m;
    cin >> e >> s >> m;

    int year = 0, ey = 0, sy = 0, my = 0;
    while (true)
    {
        year++;
        int tmp_y = ++ey % 15;
        int tmp_s = ++sy % 28;
        int tmp_m = ++my % 19;

        ey = tmp_y == 0 ? ey : tmp_y;
        sy = tmp_s == 0 ? sy : tmp_s;
        my = tmp_m == 0 ? my : tmp_m;
      
        if (ey == e && sy == s && my == m)
            break;
    }
    
    cout << year;

    return 0;
}
