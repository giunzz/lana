#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define fi first
#define se second
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll MOD = 1e18;
const ll maxn = 1e3 + 7;
using namespace std;
ll  n , m , x  , ma[maxn] , cnt1[maxn] , cnt2[maxn];

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1  ; i <= n ; i++)
    {
        ll tp1 = 0 , tp2 = 0 ;
        for (int j = 1 ; j <= m ; j++)
        {
            cin >> x;
            if (x > 0 ) tp1 += x;
            else tp2 -= x;
        }
        cnt1[i]  = tp1;
        cnt2[i] = tp2;
    }
    for (int i = 1 ; i <= n ; i++) ma[i] = max(cnt1[i] , cnt2[i]);
    sort (ma + 1 , ma + 1 + n);
    cout << ma[n] + ma[n-1];
}