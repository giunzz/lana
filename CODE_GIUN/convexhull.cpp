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
stack <ll> hs;
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

void graham() 
{
    int k = 1;
    while (k <= n + 1) 
    {
        if (hs.size() < 2) hs.push(k) , k++;
        else 
        {
            
            if (ccw(v[hs.size() - 2], v[hs.size() -1], v[k]) <= 0) hs.pop();
            else hs.push(k) , k++;
        }
    }
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> v[i].fi >> v[i].se;
        if (v[i] < v[1] && i > 1) swap(v[i] , v[1]); 
    }
    sort(v + 2 , v + 1+ n , cmp);
    v[n + 1] = v[1];
    graham();
    cout << hs.size()-2 << endl;
    
    while (hs.size() != 2)
    {
        ll u = hs.top();
        cout << v[u].fi << " " << v[u].se << endl;
        hs.pop();
    }
    return 0;
}