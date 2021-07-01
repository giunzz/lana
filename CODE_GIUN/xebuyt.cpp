#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e6+7;
ll n , a[maxn] , dd[maxn] ={0} ;
unordered_map <ll , bool> d;
inline bool check (ll x)
{
    ll sum = x;
    while ( sum < dd[n])
    {
        sum += x;
        if (d[sum] == 0) return false;
    }
    return true;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , dd[i] = dd[i-1] + a[i] , d[dd[i]] = 1;
    for (int i = 1 ; i < n ; i++) 
        if (check(dd[i]) == true) cout << dd[i] << " ";
    cout << dd[n];
}