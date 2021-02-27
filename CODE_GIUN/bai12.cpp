#include <bits/stdc++.h>
using namespace std;
int m , n , a[107][107] , b[107][107] , ans , vt1 , vt2 , vt3 , vt4 ;


int tinh (int x , int y , int z , int k )
{
    int i1 = x, j1 = y, i2 = z , j2 = k;
    int s =  b[i2][j2] - b[i1-1][j2] - b[i2][j1-1] + b[i1-1][j1-1];
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    freopen("bai12.inp","r",stdin);freopen("bai12.out","w",stdout);
    cin >> m >> n ;
    for (int i = 0 ; i <= m ; i++) b[i][0] = 0;
    for (int i = 0 ; i <= n ; i++) b[0][i] = 0;

    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            cin >>a[i][j];
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
        }
    }
    for (int i = 1 ; i <= m ; i++ )
    {
        for (int j = 1 ; j <= n ; j++)
        {
            for (int x = 1 ; x <= i ; x++ )
            {
                for (int y = 1 ; y <= j ; y++)
                {
                    if ( tinh (x , y , i , j) > ans )
                    {
                    ans = tinh (x , y , i , j);
                    vt1 = x , vt2 = y ;
                    vt3 = i , vt4 = j;
                    cerr << ans << " " << vt1 << " " << vt2 << " " << vt3 << " " << vt4 << " " << endl;
                    }
                }
            }
        }
    }
    cout << ans << endl << vt1 << " " << vt2 << " " << vt3 << " " << vt4;
    return 0;
}

