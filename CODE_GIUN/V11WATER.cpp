#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll l[maxn] , r[maxn] , a[maxn] , ans = 0 , n ;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++) l[i] = max(l[i-1] , a[i-1]) ;
    for (int i = n ; i >= 1 ; i--) r[i] = max(r[i+1] , a[i+1]) ; 
    for (int i = 1 ; i <= n ; i++) ans += max( 0LL , min(l[i],r[i])-a[i]);
    cout << ans;
}