#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

long long n,m,l,r,kq=0;
long long a[5010];
long long g[5010][5010];
bool t[5010];
long long e[5010];
long long f[5010][3];
void khoitao()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
}
void dfs(long long u)
{
    if (t[u]==1)
    {
        if (a[u]==0)
        {
            g[u][0]=0;
            g[u][1]=1;
        }
        else
        {
            g[u][0]=a[u];
            g[u][1]=a[u]-1;
        }
        e[u]=1;
        return;
    }
    e[u]=0;
    long long h;
    for (long long i=0;i<=1 && f[u][i]!=-1;i++)
    {
        dfs(f[u][i]);
        e[u]=e[u]+e[f[u][i]];
    }
    if (f[u][1]==-1)
    {
        for (long long i=0;i<=e[f[u][0]];i++)
        {
            h=a[u]-i;
            if (h<0) h=0-h;
            g[u][i]=g[f[u][0]][i]+h;
        }
    }
    else
    {
        for (long long i=0;i<=e[f[u][0]];i++)
            for (long long j=0;j<=e[f[u][1]];j++)
        {
            h=a[u]-i-j;
            if (h<0) h=0-h;
            g[u][i+j]=min(g[u][i+j],g[f[u][0]][i]+g[f[u][1]][j]+h);
        }
    }
}
void nhap()
{
    cin>>n;
    for (long long i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i][0]=-1;
        t[i]=0;
        f[i][1]=-1;
    }
    for (long long i=1;i<n;i++)
    {
        cin>>l>>r;
        if (f[l][0]==-1) f[l][0]=r;
        else f[l][1]=r;
    }
    m=0;
    for (long long i=1;i<=n;i++)
    {
        if (f[i][0]==-1)
        {
            m++;
            t[i]=1;
        }
    }
    for (long long i=0;i<=n;i++)
    for (long long j=0;j<=m;j++)
    {
        g[i][j]=1000000000000;
    }
    dfs(1);
    kq=1000000000000;
    for (long long i=0;i<=e[1];i++)
      kq=min(kq,g[1][i]);
    cout<<kq;
}
int main()
{
    khoitao();
    nhap();
    return 0;
}
