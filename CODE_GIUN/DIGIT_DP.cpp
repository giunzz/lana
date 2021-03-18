// cho n , s . Tim [1,n] bao nhieu so co tong chu so = s
#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
string n ;
ll s , ans = 0  , f[200][200][5];

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n >> s;
    for (int i = 1 ; i <= 9 ; i++)
    {
        if (i < n[0]-'0') f[1][i][0] = 1;
        else if (i == n[0]-'0') f[1][i][1] = 1;
        else f[1][i][2] = 1;
    }
    for (int i = 1 ; i < (int) n.size() ; i++)
    {
        for (int j = 0 ; j <= s ; j++)
        {
            for (int z = 0 ; z <= 2 ; z++)
            {
                if (f[i][j][z] == 0) continue;
                else 
                {
                    for (int d = 0 ; d <= 9 ; d++)
                    {
                        int newj = j+d;
                        int newz;
                        if (z == 0) newz = 0 ;
                        else if (z == 1) 
                        {
                            if (d < n[i]-'0') newz = 0 ;
                            else  if (d == n[i]-'0') newz = 1;
                            else newz = 2;
                        }
                        else newz = 2;
                        f[i+1][newj][newz] += f[i][j][z];
                        //cerr << f[i+1][newj][newz] << " "  << f[i][j][z] << endl;
                    }
                }
            }
        }
    }
    for (int i = 1 ; i <= (int) n.size() ; i++)
    {
        int MAXz = 1;
        if (i < (int) n.size()) MAXz = 2;
        for (int z = 0 ; z <= MAXz ; z++) ans += f[i][s][z];
    }
    cout << ans;
}
