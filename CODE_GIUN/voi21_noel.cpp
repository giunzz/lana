#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
ll n , a[maxn] , ans = 0 , k , d[maxn]={0}  ;
using namespace std;

void check (ll x )
{
    cerr << x << endl;
    ll m = 0 ;
    for (int i = 1 ; i <= n ; i++ )
    {
        if (i + x > n) {break;}
        if ( abs(a[i] - a[i + x]) <= k ) m++;
    }
    if (m == x) 
    {
        cout << x ;
        return ;
    }
    x--;
    //else check(x);
}
int main()
{
    giuncute;
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> n  >> k;
    ll ans = n ;
    if (ans )
    n = 2 * n ;
    for (int i = 1 ; i <= n ; i++)  cin >> a[i];
    check(ans);
}
