#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "TMOVE";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int  m , n , a[100][100] = {0} , f[100][100] = {{INT_MIN / 100}} ;

int main()
{
    balabalo;
    giuncute;
    cin >> m >> n ; // m hàng n cột
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            cin >> a[i][j];
    }
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++) 
        {
            if ( i == 1  && j == 1) f[i][j] = a[i][j] ; 
            else f[i][j] = max(  f[i-1][j], max ( f[i][j-1]  , f[i-1][j-1]) ) + a[i][j];
        }
    }
    cout << f[m][n];
    return 0;
}