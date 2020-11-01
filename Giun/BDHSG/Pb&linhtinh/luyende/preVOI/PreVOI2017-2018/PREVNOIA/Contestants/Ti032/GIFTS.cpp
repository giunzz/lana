#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int n , k;
long long a[maxn];
long long f[maxn]; // mang cong don tu a[i] => a[i+k-1]
long long ans = 1e18+5;
bool ok;

void fr()
{
    freopen ("GIFTS.INP" , "r" , stdin);
    freopen ("GIFTS.OUT" , "w" , stdout);
}

void enter()
{
    scanf("%d%d" , &n , &k);
    for (int i = 1 ; i <= n ; ++i)
        scanf("%lld" , &a[i]);
}

void solve()
{
    memset (f , 0 , sizeof f);

    for (int i = 1 ; i <= k ; ++i)
        f[1] += a[i];
    for (int i = k + 1 ; i <= n ; ++i)
        f[i - k + 1] = f[i - k] - a[i - k] + a[i];

    for (int i = 1 ; i <= n - k + 1 ; ++i)
    {
        ok = 1;
        for (int j = i + k ; j <= n - k + 1 ; ++j)
            if (f[j] > f[i])
            {
                ok = 0;
                break;
            }
        if (ok)
            for (int j = i - k ; j >= 1 ; --j)
                if (f[j] > f[i])
                {
                    ok = 0;
                    break;
                }
        if (ok)
            ans = min (ans , f[i]);
    }

    printf("%lld\n" , ans);
}

int main()
{
    fr();
    enter();
    solve();
}
