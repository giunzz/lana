#include <bits/stdc++.h>

using namespace std;

int t, a, b;

long long k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b;
        long long k = 1ll * a * b;
        for(int j = sqrt((long double)k); j >= 2; j--)
        {
            if(k % (1ll * j * j) == 0)
            {
                k /= 1ll * j * j;
                break;
            }
        }
        for(int j = sqrt((long double)k); j >= 1; j--)
        {
            if(k % j == 0)
            {
                cout << j << ' ' << k / j << endl;
                break;
            }
        }
    }
}
