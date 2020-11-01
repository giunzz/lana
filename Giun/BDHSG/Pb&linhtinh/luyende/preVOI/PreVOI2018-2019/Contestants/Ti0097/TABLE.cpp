#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
#define fi first
#define se second

int m,n,k;
long long x[maxn][maxn];
long long f[maxn][maxn];
bool check[maxn][maxn];

void io()
{
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
}

void Enter()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
    {
        scanf("%lld",&x[i][j]);
    }
}

void Solve1(int u,int v, int p, int q)
{
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
        {
            f[i][j] = -1e18;
            check[i][j] = 0;
        }
    long long ans = 1e18;
    for(int i = u; i<=p; ++i)
        for(int j = v; j<=q; ++j)
    {
            if((i == u && j == v) || (i == p && j == q)) continue;
            f[i][j] = -1e18;
            check[i][j] = 0;
            check[u][v] = 1;
            f[u][v] = x[u][v];
        for(int xx = u; xx<=p; ++xx)
            for(int yy = v; yy<=q; ++yy)
            {
                if(xx == u && yy == v) continue;
                if(xx == i && yy == j) continue;
                check[xx][yy] = 1;
                if(check[xx-1][yy])
                {
                    f[xx][yy] = max(f[xx][yy],f[xx-1][yy] + x[xx][yy]);
                }
                if(check[xx][yy-1])
                {
                    f[xx][yy] = max(f[xx][yy],f[xx][yy-1] + x[xx][yy]);
                }
            }
        if(ans > f[p][q])
        {
            ans = f[p][q];
        }
        check[i][j] = 0;
         for(int xx = u; xx<=p; ++xx)
            for(int yy = v; yy<=q; ++yy)
            {
                f[xx][yy] = -1e18;
            }
    }
    printf("%lld\n",ans);
}

void Solve2(int u, int v, int p, int q)
{
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
        f[i][j] = -1e18;
    f[u][v] = x[u][v];
    int idx,idy;
    int MAXX = -1e18;
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
        {
            f[i][j] = -1e18;
            check[i][j] = 0;
        }
    for(int i=u; i<=p; ++i)
    {
        for(int j=v; j<=q; ++j)
        {
            if(f[i-1][j] + x[i][j] > f[i][j])
            {
                f[i][j] = f[i-1][j] + x[i][j];
                if(x[i-1][j] >= MAXX)
                {
                    MAXX = x[i-1][j];
                    idx = i-1;
                    idy = j;
                }
            }
            if(f[i][j-1] + x[i][j] > f[i][j])
            {
                f[i][j] = f[i][j-1] + x[i][j];
                if(x[i][j-1] >= MAXX)
                {
                    MAXX = x[i][j-1];
                    idx = i;
                    idy = j-1;
                }
            }
        }
    }
    check[idx][idy] = 0;
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            f[i][j] = -1e18;
            f[idx][idy] = -1e18;
            check[u][v] = 1;
            f[u][v] = x[u][v];
        for(int xx = u; xx<=p; ++xx)
            for(int yy = v; yy<=q; ++yy)
            {
                if(xx == u && yy == v) continue;
                if(xx == idx && yy == idy) continue;
                check[xx][yy] = 1;
                if(check[xx-1][yy])
                {
                    f[xx][yy] = max(f[xx][yy],f[xx-1][yy] + x[xx][yy]);
                }
                if(check[xx][yy-1])
                {
                    f[xx][yy] = max(f[xx][yy],f[xx][yy-1] + x[xx][yy]);
                }
            }
            printf("%lld\n",f[p][q]);
}

int main()
{
    io();
    Enter();
    int u,v,p,q;
    long long rg = (long long) m*m*n*n*k*3;
    if(rg <= 100000000)
    {
        for(int i=1; i<=k; ++i)
        {
            scanf("%d%d%d%d",&u,&v,&p,&q);
            Solve1(u,v,p,q);
        }
    }
    else
    {
        for(int i=1; i<=k; ++i)
        {
            scanf("%d%d%d%d",&u,&v,&p,&q);
            Solve2(u,v,p,q);
        }
    }
}
