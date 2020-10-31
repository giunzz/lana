#include<bits/stdc++.h>
using namespace std;
ifstream fi("ARRANGE.INP");
ofstream fo("ARRANGE.out");
#define int long long
int tg=0,a[2001],dp[2001][2001],n,ans=0,k;
signed main()
{
    fi>>n;
    for(int i=1;i<=n;++i)
    {
        fi>>a[i];
        a[i]+=a[i-1];
    }
    tg=a[n]/n;
    k=a[n]%n;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=min(i,k);++j)
        {
            dp[i][j]=dp[i-1][j]+abs(a[i-1]-(i-1)*tg-j);
            if(j!=0)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(a[i-1]-(i-1)*tg-j+1));
        }
    }
    fo<<dp[n][k];
}
