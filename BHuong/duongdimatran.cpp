#include<bits/stdc++.h>
using namespace std; 
#define ll long long
ll f[3007][3007] ={{0}},h,w , a[1007][1007],MOD = 1e9+7;
char c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("giun.inp","r",stdin);
//    freopen("giun.out","w",stdout);
    cin >> h >> w ;
    for (int i = 1 ; i <= h ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {   
            cin >> c;
            if (c == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    f[1][1] = 1;
    for (int i = 1 ; i <= h ; i++)
    {
        for (int j = 1 ; j <= w ; j++)
        {
            if (i == 1 && j == 1) continue;

            if(a[i][j] == 0 ) 
            {
                if (a[i-1][j] != 1 && a[i][j-1] != 1) f[i][j] = (f[i-1][j]+f[i][j-1]) % MOD;
                else if (a[i-1][j] != 1) f[i][j] = (f[i-1][j])%MOD;
                else if(a[i][j-1] != 1 )f[i][j] = (f[i][j-1])%MOD;
            }
            //cerr << f[i][j] << " ";
        }
        //cerr << endl;
    }
    cout << f[h][w];
}
