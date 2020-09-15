#include <iostream>
#include <fstream>
#include <queue>
#define int long long
using namespace std;
const int inf=1e9;
int n,k,a[105],m,ans=0,dp[105][505],s=0;
priority_queue<int>q;
main()
{
    freopen("noise.inp","r",stdin);
    freopen("noise.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=m;i++)s+=a[i]*(a[i]+1)/2;
    n=m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)dp[i][j]=-inf;
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
    {
        dp[i][0]=max(dp[i][0],dp[i-1][0]);
        for(int j=1;j<=k;j++)
        {
            j++;
            int tmp=a[i]/j,r=a[i]%j;
            int red=-(tmp+1)*(tmp+2)*r/2-(tmp+1)*tmp*(j-r)/2+a[i]*(a[i]+1)/2;
            j--;
            for(int z=0;z<=k;z++)
            {
                if(j+z>k)continue;
                dp[i][j+z]=max(dp[i][j+z],dp[i-1][z]+red);
            }
        }
    }
    cout<<s-dp[n][k]<<endl;
    return 0;
}
