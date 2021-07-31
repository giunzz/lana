#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1e9 + 7;
const ll maxn = 1e5 + 3;
ll n, f[maxn] = {0} , t[maxn] , r[maxn];

int main()
{
    giuncute;
    freopen("NKTICK.inp","r",stdin);
    freopen("NKTICK.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> t[i];
    for (int i = 1 ; i <= n ; i++) cin >> r[i];
    f[1] = t[1];
    for (int i = 2 ; i <= n ; i++) f[i] = min (f[i-1] + t[i] , f[i-2] + r[i-1]);
    cout << f[n];
}