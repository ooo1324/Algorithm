#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int arr1[50];
    int arr2[50];
    int ans = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr2[i]);

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        ans += arr1[i] * arr2[i];
    }

    printf("%d", ans);
    return 0;
}
