#include <bits/stdc++.h>
using namespace std;
#define maxn 305
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define int long long
#define MOD 1000000007
#define pii pair<int,int>
int n,m,k,a[maxn][maxn],res;
int f[maxn][maxn],g[maxn][maxn];
struct ct
{
    int u,v,p,q;
} sc[maxn];
main()
{
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    scanf("%lld%lld%lld",&m,&n,&k);
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            scanf("%lld",&a[i][j]);
    for(int i=1; i<=k; ++i)
    {
        scanf("%lld%lld%lld%lld",&sc[i].u,&sc[i].v,&sc[i].p,&sc[i].q);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for(int j=sc[i].u; j<=sc[i].p; ++j)
            for(int d=sc[i].v; d<=sc[i].q; ++d)
                f[j][d]=max(f[j-1][d],f[j][d-1]) + a[j][d];
        res=f[sc[i].p][sc[i].q];
        for(int j=sc[i].p; j>=sc[i].u; --j)
            for(int d=sc[i].q; d>=sc[i].v; --d)
            {
                g[j][d]=max(g[j+1][d],g[j][d+1]) + a[j][d];
//                if(j==sc[i].u && d==sc[i].v)
//                    res=min(res,f[sc[i].p][sc[i].q] - a[j][d]);
//                if(j==sc[i].p && d==sc[i].q)
//                    res=min(res,f[sc[i].p][sc[i].q] - a[j][d]);
            }
        for(int j=sc[i].u+1; j<=sc[i].p; ++j)
        {
            int x=j,dem=0,dem1=0,ans=0;
            int y=sc[i].v;
            while(x >= sc[i].u && y <=sc[i].q)
            {
                ++dem;
                if(f[x][y]+g[x][y]-a[x][y] != f[sc[i].p][sc[i].q])
                {
                    ++dem1;
                    ans=max(ans,f[x][y]+g[x][y]-a[x][y]);
                }
                --x;
                ++y;
            }
            if(dem - dem1 <=1)
                res=min(res,ans);
        }
        for(int d=sc[i].v+1; d<sc[i].q; ++d)
        {
            int x=sc[i].p,dem=0,dem1=0,ans=0;
            int y=d;
            while(x >= sc[i].u && y <=sc[i].q)
            {
                ++dem;
                if(f[x][y]+g[x][y]-a[x][y] != f[sc[i].p][sc[i].q])
                {
                    ++dem1;
                    ans=max(ans,f[x][y]+g[x][y]-a[x][y]);
                }
                --x;
                ++y;
            }
            if(dem - dem1 <=1)
                res=min(res,ans);
        }
        printf("%lld\n",res);
    }
}
