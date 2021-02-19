#include<bits/stdc++.h>
using namespace std;
int n , k , f[(int) 1e4+7][(int) 1e4+7] ={{0}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Zb.inp","r",stdin);
    freopen("zb.out","w",stdout);
    cin >> n >> k;
    
    f[1][0] =1;
    for (int i = 2; i  <= n   ; i++)
    {
        for (int j =  0 ; j <=  k  ; j++)
        {
            for (int z = 0 ; z <= i-1; z++)
            {
                f[i][j] += (f[i-1][j-z]  ) % (int) 1e7; 
                
            }
          //  cerr << f[i][j] << " ";
        }
        //cerr << endl;
    }
    cout << f[n][k] ;
}