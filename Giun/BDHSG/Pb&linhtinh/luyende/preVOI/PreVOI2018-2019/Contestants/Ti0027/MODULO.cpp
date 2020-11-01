#include <bits/stdc++.h>
#define pii pair<int, int>
#define ft first
#define sd second
#define mp make_pair
#define pb push_back
using namespace std;
int a, b, n, k, c[25];
long long md, p[25];
void xl(int x)
{
    if(x == n)
    {
        long long s = 0;
        for(int i = 0; i < n; ++i) s = (s+p[i]*c[i]) % md;
        if(s == k)
        {
            for(int i = n-1; i >= 0; --i) cout << c[i];
            exit(0);
        }
        return;
    }
    c[x] = a;
    xl(x+1);
    c[x] = b;
    xl(x+1);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MODULO.inp", "r", stdin);
    freopen("MODULO.out", "w", stdout);
    cin >> a >> b >> n >> k;
    md = 1<<n;
    p[0] = 1;
    for(int i = 1; i < 19; ++i) p[i] = (p[i-1]*10) % md;
    xl(0);
    cout << "-1";
}
