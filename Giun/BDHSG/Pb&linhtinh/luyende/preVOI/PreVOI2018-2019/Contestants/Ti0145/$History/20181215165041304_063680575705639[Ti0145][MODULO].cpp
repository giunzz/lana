#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define FOR(i, u, v) for (ll i = u; i <= v; i++)
#define FORD(i, v, u) for (ll i = v; i >= u; i--)
#define N 105
#define ll long long



using namespace std;

ll a, b, n, k, mod, p10[N], cur;
pii all[(1 << 20) + 10];
ll inline mul(ll A, ll B) {return (A*B) % mod;}
void inline add(ll &A, ll B) {A += B; if (A >= mod) A -= mod;}

bool bit(ll x, ll i) {return (x >> i) & 1;}

void inkq(ll mask1, ll mask2, ll len1, ll len2)
{
    FORD(i, len1-1, 0)
        if (bit(mask1, i)) cout <<b;
        else cout <<a;
    FORD(i, len2-1, 0)
        if (bit(mask2, i)) cout <<b;
        else cout <<a;
    exit(0);
}

void trau()
{
    int len1 = n/2, len2 = n - len1;
    FOR(i, 0, (1ll << len1)-1)
    {
        ll val = 0;
        FOR(j, 0, len1-1)
        {
            ll z = a;
            if (bit(i, j)) z = b;
            add(val, mul(z, p10[len2+j]));
        }
        all[++cur] = mp(val, i);
    }
    sort(all+1, all+cur+1);
    FOR(i, 0, (1ll << len2)-1)
    {
        ll val = 0;
        FOR(j, 0, len2-1)
        {
            ll z = a;
            if (bit(i, j)) z = b;
            add(val, mul(z, p10[j]));
        }
        val = (k - val + mod) % mod;
        pii zz = mp(val, 0);
        int pos = lower_bound(all+1, all+cur+1, zz) - all;
        if (all[pos].F == val)
            inkq(all[pos].S, i, len1, len2);
    }
    cout <<-1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    cin >> a >> b >> n >> k;
    mod = (1ll << n);
    p10[0] = 1;
    FOR(i, 1, 64) p10[i] = (1ll*p10[i-1]*10) % mod;
    if (n <= 40) trau();
    else cout <<-1;
}
