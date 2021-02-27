#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n ,  f[(int) 1e5+7][5]={{0}};
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("g.out","w",stdout);
    cin >> n ;
    for (ll i = 1 ; i <= n ; i++) cin >> f[i][0] >> f[i][1] >> f[i][2];
    for (ll i = 1 ; i <= n ; i++)
    {
        f[i][0] += max(f[i - 1][1], f[i - 1][2]);
        f[i][1] += max(f[i - 1][0], f[i - 1][2]);
        f[i][2] += max(f[i - 1][1], f[i - 1][0]);
    }
    cout << max(f[n][0], max(f[n][1], f[n][2]));
}