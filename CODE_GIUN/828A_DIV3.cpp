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
ll n , a, b , t , c = 0 , ans = 0;
int main()
{
    giuncute;
    cin >> n >> a >> b ;
    for (int i = 1 ; i <= n ; i++) 
    {
        cin >> t ;
        if (t == 1)
        {
            if (a) a--;
            else if (b) b-- , c++;
            else if (c) c--;
            else ans++;
        } 
        else if (b) b--;
        else ans += 2;
    }
    cout << ans;
}