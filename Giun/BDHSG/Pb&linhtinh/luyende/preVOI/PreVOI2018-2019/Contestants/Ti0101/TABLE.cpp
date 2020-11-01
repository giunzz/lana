#include<bits/stdc++.h>
using namespace std;
#define NAME "TABLE"
#define fi first
#define se second
const int maxn = 3e2 + 5;
typedef pair<int,int> ii;
long long a[maxn][maxn];
long long f[maxn][maxn];
ii trace[maxn][maxn];
int m,n,k;
int u,v,p,q;

void io()
{
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
}

void Input()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) scanf("%lld",&a[i][j]);
}

void Find_way()
{
    for(int i = u + 1; i <= p; ++i)
        for(int j = v + 1; j <= q; ++j) f[i][j] = -1e18;
    f[u][v] = a[u][v];
    for(int i = u + 1; i <= p; ++i)
    {
        f[i][v] = f[i - 1][v] + a[i][v];
        trace[i][v] = ii(i - 1,v);
    }
    for(int i = v + 1; i <= q; ++i)
    {
        f[u][i] = f[u][i - 1] + a[u][i];
        trace[u][i] = ii(u,i - 1);
    }
    for(int i = u + 1; i <= p; ++i)
        for(int j = v + 1; j <= q; ++j)
        {
            if(f[i][j] < f[i - 1][j] + a[i][j])
            {
                f[i][j] = f[i - 1][j] + a[i][j];
                trace[i][j] = ii(i - 1,j);
            }
            if(f[i][j] < f[i][j - 1] + a[i][j])
            {
                f[i][j] = f[i][j - 1] + a[i][j];
                trace[i][j] = ii(i,j - 1);
            }
        }
}

void Solve()
{
    for(int itest = 1; itest <= k; ++itest)
    {
        scanf("%d%d%d%d",&u,&v,&p,&q);
        Find_way();
        ii t = trace[p][q];
        int tmp = a[t.fi][t.se];
        ii c = t;
        while(t.fi != u && t.se != v)
        {
            if(tmp < a[t.fi][t.se])
            {
                tmp = a[t.fi][t.se];
                c = t;
            }
            t = trace[t.fi][t.se];
        }
        a[c.fi][c.se] = -1e9;
        Find_way();
        a[c.fi][c.se] = tmp;
        printf("%lld\n",f[p][q]);
    }
}

int main()
{
    io();
    Input();
    Solve();
}
