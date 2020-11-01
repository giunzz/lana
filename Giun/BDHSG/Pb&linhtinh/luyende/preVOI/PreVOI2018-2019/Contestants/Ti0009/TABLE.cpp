#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(v,a) for(auto&v:a)
#define batbit(i,a) (a|(1<<(i-1)))
#define tatbit(i,a) (a&~(1<<(i-1)))
#define getbit(i,a) ((a>>(i-1))&1)
#define pii pair<int,int>
#define pi3 pair<int,pii>
#define vi3 vector<pi3>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ran(int l, int r) {return l+rng()%(r-l+1);}
int re(){int x=0; char c; bool neg=false;while (c!='-' && (c<'0'||'9'<c)) c=getchar();if (c=='-') neg=true,c=getchar();while ('0'<=c && c<='9'){x=x*10+c-'0';c=getchar();}if (neg) x=-x;return x;}
const int N=310;
int n,m,k,X,Y,U,V;
int a[N][N],d[N][N];
pii tr[N][N];
bool dd[N][N],pa[N][N];
int dx[]={1,0};
int cx[]={0,1};
vii  mm;
priority_queue <pi3,vi3,greater<pi3> > q;
void dfs(int i, int j)
{
    memset(dd,false,sizeof(dd)); memset(tr,0,sizeof(tr));
    memset(d,127,sizeof(d));
    d[i][j]=a[i][j]; q.push({d[i][j],{i,j}}); dd[i][j]=true;
    while (!q.empty())
    {
        int x=q.top().se.fi,y=q.top().se.se,c=q.top().fi; q.pop(); dd[x][y]=false;
        forinc(I,0,1)
        {
            int u=x+dx[I],v=y+cx[I];
            if (X<=u && u<=U && Y<=v && v<=V && !pa[u][v] && d[u][v]>d[x][y]+a[u][v])
            {
                d[u][v]=d[x][y]+a[u][v];
                tr[u][v]={x,y};
                if (!dd[u][v])q.push({d[u][v],{u,v}}),dd[u][v]=true;
            }
        }
    }
}
void tv()
{
    int x=U,y=V;
    while (x && y)
    {
        if ((x==X && y==Y)||(x==U && y==V)) ;
        else mm.pb({x,y});
        pii tg=tr[x][y];
        x=tg.fi,y=tg.se;
    }
}
 main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("table.inp","r",stdin);
    freopen("table.out","w",stdout);
    cin>>n>>m>>k;
    forinc(i,1,n) forinc(j,1,m) {int x; cin>>x; a[i][j]=-x;}
    while (k--)
    {
        mm.clear();
        cin>>X>>Y>>U>>V;
        dfs(X,Y);
        tv(); int kq=INT_MIN;
        forv(v,mm)
        {
            pa[v.fi][v.se]=true;
            dfs(X,Y);
            kq=max(kq,d[U][V]);
            pa[v.fi][v.se]=false;
        }
        cout<<-kq<<"\n";
    }
}
