#include<bits/stdc++.h>
using namespace std; 
#define ll long long
ll n , t  , a , b , k , x[(int)2e5+7] , y[(int)2e5+7];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> t;
    while(t--){
        map<ll, ll> cntfirst, cntsecond;
        map<pair<ll, ll>, ll> cntpair;
        cin >> a >> b >> k;
        for (int i = 1 ; i <= k ; i++) cin >> x[i];
        for (int i = 1 ; i <= k ; i++) cin >> y[i];
        for(int i = 1; i <= k; ++i) ++cntfirst[x[i]], ++cntsecond[y[i]], ++cntpair[{x[i], y[i]}];
        ll ans = 0;
        for(int i = 1; i <= k; ++i){
            ll cnt = k - (cntfirst[x[i]] + cntsecond[y[i]] - cntpair[{x[i], y[i]}]);
            ans += cnt;
        }
        cout << ans / 2 << endl;
    }
}