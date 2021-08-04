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
vector <ll> hs, res;
ll ccw (pl &a, pl &b, pl &c) 
{ 
    ll a1 = b.fi - a.fi , b1 = b.se - a.se , a2 = c.fi - b.fi , b2 = c.se - b.se ;
    ll t  = a1*b2 - a2*b1;
    if (t == 0) return 0;
    else if (t < 0) return -1;
    else return 1;
}

bool cmp (pl &i , pl &j)
{
    return ccw( v[1] , i , j) > 0;
}
ll getS(pl &a, pl &b, pl &c)
{
    ll tmp = (b.fi - a.fi) * (c.se - b.se) - (b.se - a.se) * (c.fi - b.fi);
    return abs(tmp);
}
void graham() 
{
    int k = 1;
    while (k <= n + 1) 
    {
        if (hs.size() < 2) hs.push_back(k) , k++;
        else 
        {
            
            if (ccw(v[hs[hs.size() - 2]], v[hs[hs.size() -1]], v[k]) < 0) hs.pop_back();
            else hs.push_back(k) , k++;
        }
    }
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> v[i].fi >> v[i].se; 

    for (int i = 2 ; i <= n ; i++)
    {
        if (v[i].se < v[1].se) swap(v[i] , v[1]);
        else if (v[i].se == v[1].se && v[i].fi < v[1].fi) swap(v[i] , v[1]);
    }
    sort(v + 2 , v + 1+ n , cmp);
    v[n + 1] = v[1];
    graham();
    res.push_back(hs[0]);
    for(ll i = 1; i < (int) hs.size() - 1; i++)
        if(ccw(v[hs[i - 1]], v[hs[i]], v[hs[i + 1]]) == 1) res.push_back(hs[i]); 
    ll ans = 0;
    cout << res.size() << endl;
    for (int i = 2 ; i < res.size() ; i++) ans += getS(v[res[0]], v[res[i - 1]], v[res[i]]);
    cout << ans / 2 << '.' << (ans & 1) * 5 << '\n';
    for(auto i : res) cout << v[i].first << ' ' << v[i].second << '\n';
    
    return 0;
}