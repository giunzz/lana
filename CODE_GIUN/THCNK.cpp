#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  k, n ;
vector<vector<ll>> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("thcnk.inp","r",stdin);
    freopen("thcnk.out","w",stdout);
    cin >> n >> k ;
    f.resize(n+k+1);
    for (ll i = 0 ; i <= n+k ; i++) f[i].resize(n+k+1);
    for (ll i = 0 ; i <= n+k ; i++)
    {
        for (ll j = 0 ; j <= n +k ; j++) f[i][j] = 0;
    }
    for (ll i = 0 ; i <= max(n,k); i++)  f[0][i] = 1;
    f[1][1] = 1;
    //for (int i = 1 ; i <= max(n,k); i++) f[i][i] = 1;
    for (ll i = 1 ; i <= k ; i++)
    {
        for (ll j = 1 ; j <= n ; j++) 
        {
            //if (i == j )f[i][j] = 1;
            if (i > j || ( i == 1 && j == 1) ) continue;
            f[i][j] = (f[i-1][j-1] + f[i][j-1]) ;
        }
    }
    cout << f[k][n];
    //cout << C(k,n);
}
