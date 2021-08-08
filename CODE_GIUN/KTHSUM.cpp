#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pd pair<double,double>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 4e5 + 7;
using namespace std;

ll a[maxn],k , n , f[maxn] = {0};
set <ll> ans;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , ans.insert(a[i]);
    for (int i = 1 ; i <= n ; i++)
    {
        ll tmp = a[i];
        for (int j = i+1 ; j <= n ; j++)
        {
            tmp += a[j];
            ans.insert(tmp);
        }
    }
    k = ans.size() - (k - 1);
    ll t = 0 ;
    for (auto i : ans) 
    {
        t++;
        if (t == k)
        {
            cout << i;
            return 0;
        }
    }
}