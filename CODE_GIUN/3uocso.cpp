#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1000000007;
const ll maxn = 3e7 + 3;
ll n, a , sang[maxn] = {0} , ans = 0;

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    sang[0] = 1; sang[1] = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (!sang[i]) 
        {
            ans++;
           for (ll j = i * 2; j <= min(n,(ll)1e6); j += i) sang[j] = 1;
        }
    }
    cout << ans;
}


