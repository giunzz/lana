#include<bits/stdc++.h>
using namespace std;
long long dp[110][510],n,m,k,a[110];
long long Min(long long a,long long b)
{
    if(a<b) return a;
    return b;
}
long long tinh(long long a)
{
    return a*(a+1)/2;
}
long long solve(long long a, long long b)
{
    if(b==0)
    {
        return tinh(a);
    }
    long long tmp=0;
    if(a%(b+1)==0)
    {
        tmp=b+1;
        return tinh(a/(b+1))*(b+1);
    }
    else
    {
        long long nguyen=a/b;
        long long them=nguyen*b;
        long long bu=a-them;
        return tinh(a/(b))*(b)+tinh(bu);
    }
}
int main()
{
     freopen("NOISE.inp","r",stdin);
    freopen("NOISE.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    //cout<<solve(5,2);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        long long u;
        cin>>u;
        a[u]++;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<=m;i++)
    {
        dp[i][0]=dp[i-1][0]+a[i]*(a[i]+1)/2;
      //  cout<<dp[i][0]<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=k;j++)
        {
            //if(a[i]<=j) break;
            for(int h=0;h<=j;h++)
            {
                dp[i][j]=Min(dp[i][j],dp[i-1][j-h]+solve(a[i],h));
                //cout<<solve(a[i],h)<<" ";
            }
        }
    }
    /*cout<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=k;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[m][k]<<endl;
    return 0;
}
