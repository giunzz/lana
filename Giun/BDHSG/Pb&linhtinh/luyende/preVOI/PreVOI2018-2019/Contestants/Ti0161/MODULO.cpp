/*********THACH THAO*********/

#include <bits/stdc++.h>
#define maxC 1000000007
#define maxn 64
#define Task "MODULO"
#define pll pair <long long, long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int A, B, n, a[maxn], d[maxn];
long long k, p, h[maxn];

void in()
{
    cin >> A >> B >> n >> k;
}

void check()
{
    long long res = 0;
    for (int i = 1; i <= n; ++i)
        if (!d[i]) a[i] = A;
        else a[i] = B;
    for (int i = 1; i <= n; ++i)
        res = (res + 1ll*(1ll*(1ll*a[i]%p)*h[n-i]) % p) % p;
    if (res % p == k)
    {
        for (int i = 1; i <= n; ++i) cout << a[i];
        exit(0);
    }
}

void backtrack(int id)
{
    if (id > n)
    {
        check();
        return;
    }
    for (int i = 0; i <= 1; ++i)
    {
        d[id] = i;
        backtrack(id+1);
    }
}

void solve()
{
    p = 1;
    for (int i = 1; i <= n; ++i) p = 1ll * p * 2;
    h[0] = 1;
    for (int i = 1; i < n; ++i) h[i] = (((1ll * h[i-1]) % p) * 10) % p;
    if (n <= 20) backtrack(1);
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
	in();
    solve();
    return 0;
}
