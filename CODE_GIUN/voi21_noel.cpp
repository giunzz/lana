#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 3e3 +  7;
ll n , a[maxn] , ans = 0 , k , c[maxn]={0}  ;
using namespace std;

bool check(ll x , vector<ll> y)
{
    ll t = 0;
    for (int i = 0 ; i < (int)y.size() ; i++)
    {
        if (i+x > (int) y.size()) continue;
        if (abs(y[i] - y[i+x]) <= k) t++;
    }
    if (t == x) return true;
    else return false;
}

void quaylui (ll vt )
{
    if (vt == n + 1)         
    {
        vector<ll> tmp;
        for (int i = 1 ; i <= n ; i++)
            if (c[i] == 1) tmp.push_back(a[i]);
        if (tmp.size() % 2 == 0)
        {
            ll len = tmp.size()/2 ;
            for (ll i = 1 ; i <= len+1 ; i++)
            {
                if (ans > i) continue;
                if (check(i,tmp) == true) ans = max(ans,i);
            }
        }
    }
    else
    {
        for (int i = 0 ; i <= 1 ; i++)
        {
            c[vt] = i ;
            quaylui(vt+1);
        }
    }
}
int main()
{
    giuncute;
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> n  >> k;
    n = n*2;
    for (int i = 1 ; i <= n ; i++)  cin >> a[i];
    quaylui(1);
    cout << ans;
}
