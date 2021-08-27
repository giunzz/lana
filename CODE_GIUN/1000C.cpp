#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define fi first
#define se second
#define pl pair<ll,ll>
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll n , l , r , ans[maxn] = {0};
vector<pl> a;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> l >> r;
        a.push_back({l,1}) , a.push_back({r + 1 , -1});
    }
    sort (a.begin() , a.end());
    ll cnt = a[0].se;
    for (int i  = 1 ; i < a.size() ; i++)
    {
        ans[cnt] += a[i].fi - a[i-1].fi;
        cnt += a[i].se;
    }
    for (int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
}