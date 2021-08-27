#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , a[maxn];
ll l[maxn] , r[maxn] , f[maxn];

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    l[1] = a[1];
    ll tmp = a[1];
    for (int i = 2 ; i <= n ; i++) l[i] = min (l[i-1] , tmp + a[i] ) , tmp += a[i];
    r[n] = a[n];
    for (int i = n - 1 ; i >= 1 ; i--) r[i] = min (a[i] , r[i+1] + a[i]);
    f[n] = a[n];
    for (int i = n - 1 ; i >= 1 ; i--) f[i] = f[i+1] + a[i];
    for (int i = 1 ; i <= n ; i++) cerr  << r[i] << " " << l[i] << " " << f[i] << endl;
    ll ans = 0 ;
    for (int i = 1 ; i <= n ; i++) 
        if (r[i] > 0 && l[i] + f[i] > 0) ans++;
    cout << ans;
}