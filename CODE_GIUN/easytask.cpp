#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 1e6 + 7;
const ll oo = 1e18 + 7 ;
using namespace std;
ll n , sang[maxn] = {0} , pre[maxn] , a[maxn];

void ss()
{
    sang[0] = sang[1] = 1;
    for (int i = 2 ; i*i <= 1e6 ; i++)
        if (!sang[i])
            for (int j = i * 2 ; j <= 1e6 ; j += i) sang[j] = 1;
}
int main()
{
    giuncute;
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    ss();
    ll mi = INT_MAX , ans = INT_MIN;
    for (int i = 1 ; i <= n ; i++)
    {
        pre[i] = pre[i-1] + a[i];
        if (!sang[i]) mi = min(mi ,pre[i-1]) , ans = max (ans , pre[i] - mi);
    }
    cout << ans;
}