#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1000000007;
const ll maxn = 1e5 + 3;
ll n;
pl v[maxn];
vector <pl> res;
ll ccw (pl &a, pl &b, pl &c) 
{ 
    ll a1 = b.fi - a.fi , b1 = b.se - a.se , a2 = c.fi - b.fi , b2 = c.se - b.se ;
    ll t  = a1*b2 - a2*b1;
    if (t == 0) return 0; // di thang
    else if (t < 0) return -1; // queo phai
    else return 1; // queo trai
}

bool cmp (pl &i , pl &j)
{
    ll tmp = ccw( v[1] , i , j) ;
    return (tmp == 1) || ( (tmp == 0) && (i.se < j.se || (i.se == j.se && i.fi < j.fi)) ) ;
}

ll getS(pl &a, pl &b, pl &c)
{
    ll tmp = (b.fi - a.fi) * (c.se - b.se) - (b.se - a.se) * (c.fi - b.fi);
    return abs(tmp);
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    v[0] = {-1e18, -1e18};
    for (int i = 1 ; i <= n ; i++) cin >> v[i].fi >> v[i].se; 
    for (int i = 2 ; i <= n ; i++)
    {
        if (v[i].se < v[1].se) swap(v[i] , v[1]);
        else if (v[i].se == v[1].se && v[i].fi < v[1].fi) swap(v[i] , v[1]);
    }
    sort(v + 2 , v + 1+ n , cmp);
    for (int i = 1 ; i <= n ; i++)
    {
        if (v[i] == v[i-1]) continue;
        if(res.size() < 2) res.push_back(v[i]);
        else
        {
            while( res.size() > 1 && ccw(res[res.size() - 2], res.back(), v[i]) <= 0) res.pop_back();
            res.push_back(v[i]) ; 
        }
    }
    ll ans = 0;
    for (int i = 2 ; i < (int) res.size() ; i++) ans += getS(res[0], res[i - 1], res[i]);
    cout << res.size() << '\n';
    cout << ans / 2 << '.' << (ans & 1) * 5 << '\n';
    for (int i = 0 ; i < (int)res.size() ; i++) cout << res[i].first << ' ' << res[i].second << '\n';
    return 0;
}