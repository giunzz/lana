#include<bits/stdc++.h>
using namespace std;
const int maxn = 4e3 ;
long long   m , n , a[maxn + 7][maxn + 7] , f[maxn + 7][maxn + 7] ;
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0);
    freopen("MAXPATH.inp","r", stdin);freopen("MAXPATH.out","w",stdout);
    cin >> m >> n ; 
    for (int i = 1 ; i <= m ; i++)
        for (int j = 1 ; j <= n ; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1 )f[i][j] = -1;
        }
    if (a[1][1] == -1 || a[m][n] == -1) return -1;
    for (int i = 0 ; i <= m ; i++) f[i][0] = -1 , a[i][0] = -1;
    for (int i = 0 ; i <= n  ; i++) f[0][i] = -1 ,a[0][i] = -1;   
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++) 
        {
            if ( i == 1  && j == 1 ) f[i][j] = a[i][j];
            else if  ( f[i][j-1] == -1 && f[i-1][j] == -1  ) f[i][j] = -1;
            else if (a[i][j] != -1) f[i][j] = max(  f[i-1][j] , f[i][j-1]   ) + a[i][j];
        }
    }
    cout << f[m][n];
    return 0;
}