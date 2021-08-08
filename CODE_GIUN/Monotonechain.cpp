#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e18;
const ll maxn = 4e5 + 7;
using namespace std;

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    giuncute;
    cin >> n ;
    v[0] = {-MOD , -MOD};
    for (int i = 1 ; i <= n ; i++) cin >> v[i].fi >> v[i].se;
