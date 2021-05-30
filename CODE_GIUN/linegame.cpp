#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e6+7 ;
ll n ,  f[maxn][5] ={0} ,a[maxn] , dau[] ={-1 , 1};

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++)
        for (int j = 0 ; j <= 1 ; j++) 
            f[i][j] = max (f[i-1][j] , f[i-1][!j] + a[i]*dau[j]);
    cout << max(f[n][0], f[n][1] );
}
