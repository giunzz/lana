#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 2e5+7;
ll n , x ;
pair <ll,ll> dd[maxn];
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x ; 
        dd[x].first ++ ;
        dd[x].second = i ;
    }
    ll ma = INT_MAX;
    for (ll i = 1 ; i <= n ; i++)
        if (dd[i].first == 1) ma = min(dd[i].second,ma);
    if (ma == INT_MAX) cout << -1;
    else cout << ma;
}