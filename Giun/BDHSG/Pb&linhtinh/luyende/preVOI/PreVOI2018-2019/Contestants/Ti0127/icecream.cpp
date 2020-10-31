#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,maxx,m1,m2,m,res;
int f[55][55][55][55];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin>>n>>maxx;
    cin>>m>>m1>>m2;
    f[0][m][m1][m2]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=50;j++)
        for(int k=0;k<=50;k++)
        for(int t=0;t<=50;t++)
        if(f[i][j][k][t])
    {
        if(j+k+t+1<=maxx)
            f[i+1][j+1][k][t]+=f[i][j][k][t];
        if(j>0)
            f[i+1][j-1][k+1][t]+=f[i][j][k][t];
        if(j>0&&k>0)
            f[i+1][j-1][k-1][t+1]+=f[i][j][k][t];
        else
            if(j>=3)
            f[i+1][j-3][k][t+1]+=f[i][j][k][t];
    }
    for(int i=0;i<=50;i++)
        for(int j=0;j<=50;j++)
            for(int k=0;k<=50;k++)
        if(i+j+k<=maxx)
        res+=f[n][i][j][k];
        cout<<res;
    return 0;
}
