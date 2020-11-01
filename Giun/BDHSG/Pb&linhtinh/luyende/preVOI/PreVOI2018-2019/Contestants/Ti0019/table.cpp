#include <bits/stdc++.h>
inline int in()
{
    int x=0;char c=getchar();bool neg=0;
    while(('0'>c||c>'9') && c!='-') c=getchar();
    if(c=='-') neg=1,c=getchar();
    while('0'<=c&&c<='9') x=10*x+c-'0',c=getchar();
    if(neg) x=-x;
    return x;
}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define task "TABLE"
#define forinc(a,b,c) for(int a=b,__key=c;a<=__key;++a)
#define fordec(a,b,c) for(int a=b,__key=c;a>=__key;--a)
#define forv(a,b) for(auto&a:b)
#define ii pair<int,int>
#define i3 pair<int,ii>
#define fi first
#define se second
#define nd second.first
#define rd second.second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mt make_tuple
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))
#define reset(f,x) memset(f,x,sizeof(f))
#define all(a) a.begin(),a.end()
#define int long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int N=510;
int n,m,q;
int a[N][N],f[N][N],g[N][N],up[N][N],down[N][N];
int query(int x,int y,int u,int v)
{
    reset(f,0);reset(g,0);reset(down,0);reset(up,0);
    int kq=1e9;
    forinc(i,x,u) forinc(j,y,v) f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
    fordec(i,u,x) fordec(j,v,y) g[i][j]=max(g[i+1][j],g[i][j+1])+a[i][j];
    forinc(j,y,v)
    {
        forinc(i,x,u) down[j][i]=max(down[j][i-1],f[i][j]+g[i][j]-a[i][j]);
        fordec(i,u,x) up[j][i]=max(up[j][i+1],f[i][j]+g[i][j]-a[i][j]);
    }
    forinc(i,x,u) forinc(j,y,v)
    {
        if(i==x&&j==y || i==u&&j==v) continue;
        int re=0;
        re=max(down[j+1][i-1],up[j-1][i+1]);
        kq=min(kq,re);
    }
    return kq;
}
main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    m=in(),n=in(),q=in();
    forinc(i,1,m) forinc(j,1,n) a[i][j]=in();
    while(q--)
    {
        int x=in(),y=in(),u=in(),v=in();
        cout<<query(x,y,u,v)<<"\n";
    }
}

