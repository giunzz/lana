#include <bits/stdc++.h>
#define foreinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define forv(a,b) for(auto&a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
inline int read()
{
    int x=0; bool ok=false; char c=getchar();
    while(!isdigit(c)) ok=(c=='-'),c=getchar();
    while(isdigit(c)) x=x*10+c-'0',c=getchar();
    if(ok) return -x; return x;
}
const int N=310,s1=110;
int m,n,k,kq;
int a[s1][s1];
int dd[s1][s1];
pii trc[s1][s1];
int d[s1][s1];
vector<pii> luu;
void bfs(int u,int v,int x,int y)
{
    queue<pii> q;
    d[u][v]=a[u][v];
    q.push({u,v});
    while(!q.empty())
    {
        int u=q.front().fi,v=q.front().se;
        q.pop();
        if(dd[u][v]) continue;
        dd[u][v]=1;
        if(d[u+1][v]<d[u][v]+a[u+1][v])
        {
            d[u+1][v]=d[u][v]+a[u+1][v];
            trc[u+1][v]={u,v};
        }
        if(d[u][v+1]<d[u][v]+a[u][v+1])
        {
            d[u][v+1]=d[u][v]+a[u][v+1];
            trc[u][v+1]={u,v};
        }
        if(u<x) q.push({u+1,v});
        if(v<y) q.push({u,v+1});
    }
    kq=min(kq,d[x][y]);
}
main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    m=read();n=read();k=read();
    foreinc(i,1,m) foreinc(j,1,n) a[i][j]=read();
    if(m<=30&&n<=30&&k<=30)
    {
        foreinc(tv,1,k)
        {
            kq=INT_MAX;
            int u=read(),v=read(),x=read(),y=read();
            foreinc(i,u,x) foreinc(j,v,y)
            {
                if((i==u&&j==v)||(i==x&&j==y));
                else
                {
                    memset(dd,0,sizeof(dd));
                    memset(d,0,sizeof(d));
                    dd[i][j]=1;
                    bfs(u,v,x,y);
                }
            }
            cout<<kq<<"\n";
        }
        return 0;
    }
    if(m<=100&&n<=100&&k<=100)
    {
        foreinc(tv,1,k)
        {
            kq=INT_MAX;
            int u=read(),v=read(),x=read(),y=read();
            memset(dd,0,sizeof(dd));
            memset(d,0,sizeof(d));
            bfs(u,v,x,y);
            int i=x,j=y;
            luu.push_back({i,j});
            while(i!=u&&j!=v)
            {
                pii tg=trc[i][j];
                i=tg.fi;j=tg.se;
                luu.push_back({i,j});
            }
            forv(vv,luu)
            {
                memset(dd,0,sizeof(dd));
                memset(d,0,sizeof(d));
                dd[vv.fi][vv.se]=1;
                bfs(u,v,x,y);
            }
            luu.clear();
            cout<<kq<<"\n";
        }
    }
}
