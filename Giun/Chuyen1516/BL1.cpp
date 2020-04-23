#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("BL1.INP", "r", stdin);
    freopen("BL1.OUT", "w", stdout);
    int n, k, a[105], maxs;
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        if (i == k) maxs = a[i];
        else if (i > 4)
            if (maxs < a[i] - a[i-k]) maxs = a[i] - a[i-k];
    }
    cout << maxs;
    return 0;
}
