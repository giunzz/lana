#include<cstdio>
#include<math.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int limit=4*1e3+1;
struct inf 
{
    long long first,second;
    inf(long long a=0,long long b=0)
    {
        first=a,second=b;
    }
} pos,pre[limit][limit];
vector<long long>ans;
long long n,k,res;
long long a[limit],b[limit],dp[limit][limit];
void in()
{
    scanf("%lld%lld",&n,&k);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
}
void trace()
{
    printf("%lld\n",res);
    while (pos.first && pos.second)
    {
        ans.push_back(a[pos.first]);
        pos=pre[pos.first][pos.second];
    }
    while (ans.size()) 
    {
        printf("%lld ",ans[ans.size()-1]);
        ans.pop_back();
    }
}
void so()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (a[i]==b[j])
            {
                long long opt=0;
                long long cur=0;
                for (int i1=i-1;i1>=1;i1--)
                    for (int j1=j-1;j1>=1;j1--) if (a[i1]==b[j1] && abs(a[i]-a[i1])<=k)
                        {
                            if (dp[i1][j1]>opt || (dp[i1][j1]==opt && a[i1]>cur)) 
                            {
                                cur=a[i1];
                                opt=dp[i1][j1];
                                pre[i][j]=inf(i1,j1);
                            }
                        }
                dp[i][j]=opt+1;
                if (dp[i][j]>res) 
                {
                    res=dp[i][j];
                    pos=inf(i,j);
                }
            }
    trace();
}
int main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    in();
    so();
}