#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
const ll oo = 1e18 + 7 ;
using namespace std;

ll d[20] , f[20] , n  , ans = 0 ;

vector<pl> get()
{
    ll k ;
    cin >> k;
    vector<ll> card[5];
    vector<pl> res(5);
    for (int i = 1 ; i <= k ; i++)
    {
        ll c , d ;
        cin >> c >> d;
        card[c].push_back(d); // chi phi c sat thuong d
    }
    for (int i = 1 ; i <= 3 ; i++)
    {
        sort(card[i].begin() , card[i].end() , greater<ll>());
        card[i].push_back(-oo) , card[i].push_back(-oo), card[i].push_back(-oo);
    }
    res[1].fi = max({card[1][0], card[2][0], card[3][0]}); // 1 phan tu
    res[1].se = res[1].fi * 2;
    res[2].fi = max(card[1][0] + card[2][0], card[1][0] + card[1][1]);
    res[2].se = max(card[1][0] + card[2][0] + max(card[1][0], card[2][0]), 2 * card[1][0] + card[1][1]);
    res[3].fi = card[1][0] + card[1][1] + card[1][2];
    res[3].se = res[3].fi + card[1][0];
    return res;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 0 ; i < 10 ; i++) d[i] = f[i] = -oo;
    d[0] = 0 ;
    for (int i = 1 ; i <= n ; i++)
    {
        auto v = get();
        for (int j = 0 ; j < 10 ; j++)
        {
            for (int k = 1 ; k <= 3 ; k++)
            {
                ll newj = (j + k) % 10;
                if (j + k  >= 10) f[newj] = max(f[newj] , d[j] + v[k].se);
                else f[newj] = max(f[newj] , d[j] + v[k].fi);
            }
        }
        for (int j = 0 ; j < 10 ; j++) d[j] = max(d[j] , f[j]) , f[j] = -oo , ans = max(ans , d[j]);
    }
    cout << ans ;
}
