#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll MOD = 1000000007;
const ll maxn = 3e3 + 3;
ll n, x , d[maxn] = {0};

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> x , d[x]++;
    d[1] -= min(d[1] , d[3]) ,d[2] *= 2;
    ll tmp = d[2] % 4;
    d[2] += min ( tmp , d[1]) , d[1] -= min ( tmp , d[1]) ;
    d[2] = (d[2] + 3) /4 ,d[1] = (d[1] + 3)/4; // a +
    cout << d[1] + d[2] + d[4] +  d[3];
}
