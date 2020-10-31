#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a,b_=b;i<=b_;++i)
#define ford(i,a,b) for(int i=a,b_=b;i>=b_;--i)
#define forv(i,a) for(auto &i:a)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ___ << "\n"
#define __ << " " <<
#define _ << " "
#define getbit(x,i) (((x)>>(i))&1)
#define onbit(x,i) ((x)|(1<<(i)))
#define INF 1000000000000000
using namespace std;

const int N=305;
int m,n,a[N][N],query;
int dong[2]={1,0};
int cot[2]={0,1};
pii q[N*N];
int topL,topR;
ll d[N][N];
int tr[N][N];

bool Inside(int u, int v){ return (1<=u) && (u<=m) && (1<=v) && (v<=n); }
bool InHcn(int i, int j, int x, int y, int u, int v)
{
    return(x<=i && i<=u) && (y<=j && j<=v);
}
ll BFS(int sx, int sy, int tx, int ty, int bx, int by)
{
    fori(i,sx,tx) fori(j,sy,ty) d[i][j]=0; d[sx][sy]=a[sx][sy];
    topL=topR=1; q[1]={sx,sy};
    int x,y;
    while(topL<=topR)
    {
        x=q[topL].fi; y=q[topL].se; topL++;
        fori(i,0,1)
        {
            int u=x+dong[i], v=y+cot[i];
            if(InHcn(u,v,sx,sy,tx,ty)) if(u!=bx || v!=by)
            {
                if(d[u][v]==0) q[++topR]={u,v};
                d[u][v]=max(d[u][v],d[x][y]+a[u][v]);
            }
        }
    }
    return d[tx][ty];
}
void Apps1()
{
    int x,y,u,v; ll res;
    while(query--)
    {
        scanf("%d %d %d %d",&x,&y,&u,&v);
        res=BFS(x,y,u,v,0,0);
        fori(i,x,u) fori(j,y,v)
        {
            if(i==x && j==y) continue;
            if(i==u && j==v) continue;
            res=min(res,BFS(x,y,u,v,i,j));
        }
        cout << res ___;
    }
}
void Find(int sx, int sy, int tx, int ty)
{
    fori(i,sx,tx) fori(j,sy,ty) d[i][j]=tr[i][j]=0; d[sx][sy]=a[sx][sy];
    topL=topR=1; q[1]={sx,sy};
    int x,y,u,v;
    while(topL<=topR)
    {
        x=q[topL].fi; y=q[topL].se; topL++;
        fori(i,0,1)
        {
            u=x+dong[i]; v=y+cot[i];
            if(InHcn(u,v,sx,sy,tx,ty))
            {
                if(d[u][v]==0) q[++topR]={u,v};
                if(d[u][v]<d[x][y]+a[u][v])
                {
                    d[u][v]=d[x][y]+a[u][v]; tr[u][v]=i+1;
                }
            }
        }
    }
    u=tx; v=ty;
    int p;
    vector<pii> vt;
    ll res=BFS(sx,sy,tx,ty,0,0);
    while(u!=sx || v!=sy)
    {
        p=tr[u][v]-1;
        if(p==0) u--; else v--;
        if(u!=sx || v!=sy)
        {
            res=min(res,BFS(sx,sy,tx,ty,u,v));
        }
    }
    cout << res ___;
}
void Apps2()
{
    int x,y,u,v; ll res;
    while(query--)
    {
        scanf("%d %d %d %d",&x,&y,&u,&v);
        Find(x,y,u,v);
    }
}
int main()
{
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    scanf("%d %d %d",&m,&n,&query);
    fori(i,1,m) fori(j,1,n) scanf("%d",&a[i][j]);
    if(m<=30 && n<=30 && query<=30) Apps1();
    else Apps2();
    //Apps2();
}

