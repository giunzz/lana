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
ll hs[maxn];
ll ccw (pl &a, pl &b, pl &c) 
{ 
    ll a1 = b.fi - a.fi , b1 = b.se - a.se , a2 = c.fi - a.fi , b2 = c.se - a.se ;
    ll t  = a1*b2 - a2*b1;
    if (t == 0) return 0;
    else if (t < 0) return -1;
    else return 1;
}

bool cmp1 (pl& i, pl& j)
{
    if(i.se != j.se) return i.se < j.se;
    return i.fi > j.fi;
}

bool cmp (pl &i , pl &j)
{
    return ccw( v[1] , i , j) > 0;
}

void graham() 
{
    int k = 1, j = 1;
    while (k <= n + 1) 
    {
        while (j > 2 && ccw(v[hs[j - 2]], v[hs[j - 1]], v[k]) <= 0) {
            j--;
        }
        hs[j++] = k++;
    }
    cout << j - 2 << endl;
    for(long i = 1; i < j - 1; i++)
    {
        cout << v[hs[i]].fi <<' ' << v[hs[i]].se << endl;
    }
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    while(cin >> n && n)
    {
        for (int i = 1 ; i <= n ; i++) cin >> v[i].fi >> v[i].se; 

        sort(v + 1, v + n + 1, cmp1);
        sort(v + 2 , v + 1 + n , cmp);
        v[n + 1] = v[1];
        graham();
    }
    return 0;
}