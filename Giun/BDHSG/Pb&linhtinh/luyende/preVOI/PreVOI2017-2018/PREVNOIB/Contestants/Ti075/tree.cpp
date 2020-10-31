#include<bits/stdc++.h>
#define maxn 5001
using namespace std;
int a[maxn],m,cl[maxn],s[maxn],sn,cur[maxn],deg[maxn],kc[maxn],n,pre[maxn],x[maxn],slx=0,start[maxn],stop[maxn],maxa[maxn],dd[maxn][3],ddd[maxn],f[maxn][maxn];
vector<int> g[maxn];
void DFS(int xp)
{
    memset(cl,0,sizeof(cl));
    cl[xp]=1;
    s[++sn]=xp;
    x[++slx]=xp;
    start[xp]=slx;
    while(sn>0)
    {
        int u=s[sn];
        if(cur[u]<deg[u])
        {
            int v=g[u][cur[u]++];
            if(cl[v]==0)
            {
                cl[v]=1;
                s[++sn]=v;
                x[++slx]=v;
                start[v]=slx;
                pre[v]=u;
                ddd[u]++;
                dd[u][ddd[u]]=v;
            }
        }
        else
        {
            sn--;
            stop[u]=slx;
        }
    }
}
int read_int()
{
    char c;
    int sign,kq;
    do
    {
        c=getchar();
    }
    while(c!='-'&&(c<'0'||c>'9'));
    if(c=='-') sign=-1,kq=0;
    else sign=1,kq=c-'0';
    do
    {
        c=getchar();
        if(c<'0'||c>'9') break;
        kq=kq*10+c-'0';
    }
    while(1);
    return sign*kq;
}
void write_int(long long x)
{
    if(x<0) putchar('-'),x=-x;
    char c[20];
    int sl=-1;
    c[++sl]=x%10+'0',x/=10;
    while(x)c[++sl]=x%10+'0',x/=10;
    while(sl>=0) putchar(c[sl--]);
}
int main ()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    n=read_int();
    for(int i=1; i<=n; i++)a[i]=read_int();
    for(int i=1; i<=n-1; i++)
    {
        int u,v;
        u=read_int();v=read_int();
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    DFS(1);
    for(int i=n; i>=1; i--)
    {
        int u=x[i];
        for(int i=0; i<deg[u]; i++)
        {
            int v=g[u][i];
            if(pre[v]==u)maxa[u]+=maxa[v]+1;
        }
    }
    for(int i=1; i<=n; i++)if(ddd[i]==0)maxa[i]=1;
    for(int i=n; i>=1; i--)
    {
        int u=x[i];
        if(ddd[u]==0)
        {
            f[u][0]=a[u];
            f[u][1]=abs(a[u]-1);
        }
        else
        {
            if(ddd[u]==1)
            {
                for(int j=0; j<=maxa[u]; j++)f[u][j]=f[dd[u][1]][j]+abs(j-a[u]);
            }
            else
            {
                for(int j=0; j<=maxa[u]; j++)
                {
                    f[u][j]=1000000000;
                    for(int j1=maxa[dd[u][1]]; j1>=0; j1--)
                        if(j-j1<=maxa[dd[u][2]])f[u][j]=min(f[u][j],f[dd[u][1]][j1]+f[dd[u][2]][j-j1]+abs(j-a[u]));
                        else break;
                }
            }
        }
    }
    int ds=1000000000;

    for(int i=0; i<=maxa[1]; i++)ds=min(ds,f[1][i]);
    write_int(ds);
}
