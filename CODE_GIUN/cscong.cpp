#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define pl pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll maxn = 5e3 + 7;
using namespace std;
ll a[maxn] , f[maxn][maxn] , ans = INT_MIN , n ;
bool cnt[maxn] = {0};

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= a[i] ; j++)
        {
            if (cnt[a[i] - j] != 0) f[a[i]][j] = f[a[i] - j][j] + 1;
			ans = max (ans, f[a[i]][j]);
        }
        cnt[a[i]] = 1;
    }
    ans++;
    cout << ans;
}