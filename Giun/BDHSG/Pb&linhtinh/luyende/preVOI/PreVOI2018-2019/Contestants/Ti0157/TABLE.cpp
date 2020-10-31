#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,a,b) for(int i=a;i<=b;i++)
#define FD(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define oo
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int m,n,k;
int a[303][303];
ll res[303][303];
int ok[303][303];
int h[3]={0,1};
int c[3]={1,0};
pii tr[303][303];
void ReadInPut()
{
    cin>>m>>n>>k;
    F(i,1,m)F(j,1,n)cin>>a[i][j];
}
void BMF(int x,int y,int u,int v)
{
    memset(res,0,sizeof(res));
    memset(ok,0,sizeof(ok));
    queue<pii>q;
    q.push(mp(x,y));
    ok[x][y]=1;
    res[x][y]=a[x][y];
    while(q.size())
    {
        int i=q.front().fi;
        int j=q.front().se;
        q.pop();
        ok[i][j]=0;
        for(int z=0;z<2;z++)
        {
            int ix=i+h[z];int jx=j+c[z];
            if(ix>u||jx>v)continue;
            if(res[ix][jx]<res[i][j]+a[ix][jx])
            {
                res[ix][jx]=res[i][j]+a[ix][jx];
                tr[ix][jx]=mp(i,j);
                if(ok[ix][jx]==0){ok[ix][jx]=1;q.push(mp(ix,jx));}
            }
        }
    }
}
void Solve()
{
    while(k--)
    {
        ll ans=1e16;
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        BMF(x,y,u,v);
        int t1=tr[u][v].fi;
        int t2=tr[u][v].se;
        while(t1!=x&&t2!=y)
        {
            int g=a[t1][t2];
            a[t1][t2]=0;
            BMF(x,y,u,v);
            ans=min(ans,res[u][v]);
            a[t1][t2]=g;
            int tg=t1,tg1=t2;
            t1=tr[tg][tg1].fi;
            t2=tr[tg][tg1].se;
        }
        cout<<ans<<'\n';
    }
}
main()
{
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    ReadInPut();
    Solve();
}
