#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 1299710
bool d[MAX];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, a;
    cin >> n;
    vector<int> vec;
    vector<int> numbers;
    int maxVal = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
        maxVal = max(maxVal, a);
    }

    for (int i = 2; i < MAX; i++)
        d[i] = true;

    d[1] = 0;
    for (int i = 2; i < sqrt(MAX); i++)
    {
        if (!d[i]) continue;

        for (int j = i + i; j < MAX; j += i)
            d[j] = false;
    }
    
    for (int i = 2; i < MAX; i++)
    {
        if(d[i]) 
            numbers.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (d[vec[i]])
            cout << "0" << '\n';
        else
        {
            int idx = lower_bound(numbers.begin(), numbers.end(), vec[i]) - numbers.begin();
            cout << numbers[idx] - numbers[idx - 1] << '\n';
        }
    }
    return 0;
}
