#include<bits/stdc++.h>
using namespace std; 
#define ll long long
ll f[1007][1007] ={{0}}, k, n ;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> k ;
    for (int i = 0 ; i <= n ; i++) f[i][0] = 1 , f[0][i] = 1;
    for (int i = 1 ; i <= n ; i++) f[i][i] = 1;
    for (int i = 1 ; i <= k ; i++)
    {
        for (int j = 1 ; j <= n ; j++) 
        {
            if (i == j )f[i][j] = 1;
            else  f[i][j] = f[i-1][j-1] + f[i][j-1];
        }
    }
    cout << f[k][n];
}
