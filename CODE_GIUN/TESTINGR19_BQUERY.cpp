#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
#define pl pair<ll,ll>
const ll MOD = 1e9 + 7;
const ll maxn = 4e3 + 7;
using namespace std;
ll n , ans = 0 , m , q , a[maxn][maxn] = {0};
void sol1()
{
    ll l , r ;
    cin >> l >> r;
    for (int i = 1 ; i <= m ; i++) a[l][i] += r;
}
void sol2()
{
    ll l , r ;
    cin >> l >> r;
    for (int i = 1 ; i <= n ; i++) a[i][l] += r;
}
void sol3()
{
    ll l1 , r1 , l2 , r2 , ans = INT_MIN;
    cin >> l1 >> r1 >> l2 >> r2;
    for (int i = l1 ; i <= l2 ; i++)
        for (int j = r1 ; j <= r2 ; j++)  ans = max(ans , a[i][j]);
    cout << ans << endl;
}
int main()
{
    giuncute;
    // freopen("giun.inp","r",stdin);
    // freopen("giun.out","w",stdout);
    cin >> n >> m >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        if (x == 1) sol1();
        if (x == 2) sol2();
        if (x == 3 ) sol3();
    }
}