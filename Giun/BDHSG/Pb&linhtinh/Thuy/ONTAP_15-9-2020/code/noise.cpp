#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,m;
ll a[107], dp[107][508];
const ll INF= LONG_MAX;
ll tongx(int x)
{
    return (1ll*x*(x+1)/2);
}
inline ll f(int L, int T)
{
    int x=L/T, t=(x+1)*T-L;
    return tongx(x)*t+tongx(x+1)*(T-t);
}
int main()
{
    freopen("noise.inp","r",stdin);
    freopen("noise.out","w",stdout);
    cin>>n>>m>>k; int x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[x]++;
    }
    for (int i=1;i<=m;i++)
    {
        for(int j=0;j<=k;j++) dp[i][j]=INF;
        for(int j=0;j<=k;j++)
        {
          for(int z=j;z<=k;z++)
            cout<<f(a[i], j + 1)<<endl,
            dp[i][z]=min(dp[i][z], dp[i-1][z-j]+f(a[i],j+1));
        }
    }
    cout<<dp[m][k];
    return 0;
}

