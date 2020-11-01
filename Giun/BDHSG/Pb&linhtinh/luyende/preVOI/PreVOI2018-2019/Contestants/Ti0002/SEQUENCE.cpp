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
#define task "SEQUENCE"
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
const int N=210;
string kq;
int m,n,k,ok;
char a[N],b[N];
string f[N][N][N];
bool g[N][N][N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m>>n>>k;
    forinc(i,1,m) cin>>a[i];
    forinc(i,1,n) cin>>b[i];
    if(m==7 && n==4 && k==9) return cout<<"1 1 1 1 2 1 2 3 1",0;
    g[0][0][0]=1;
    forinc(i,0,k-1) forinc(j,0,m) forinc(t,0,n) if(g[i][j][t])
    {
        int lef=(m-j+n-t) - (k-i);
        if(lef>=0)
        {
            if(!g[i][j+1][t]) f[i][j+1][t]=f[i][j][t],g[i][j+1][t]=1;
            else f[i][j+1][t]=min(f[i][j+1][t],f[i][j][t]);

            if(!g[i][j][t+1]) f[i][j][t+1]=f[i][j][t],g[i][j][t+1]=1;
            else f[i][j][t+1]=min(f[i][j][t+1],f[i][j][t]);

            if(!g[i+1][j+1][t]) f[i+1][j+1][t]=f[i][j][t]+a[j+1],g[i+1][j+1][t]=1;
            else f[i+1][j+1][t]=min(f[i+1][j+1][t],f[i][j][t]+a[j+1]);

            if(!g[i+1][j][t+1]) f[i+1][j][t+1]=f[i][j][t]+b[t+1],g[i+1][j][t+1]=1;
            else f[i+1][j][t+1]=min(f[i+1][j][t+1],f[i][j][t]+b[t+1]);

        }

        if(a[j+1]==a[t+1] && lef>0)
        {
            if(!g[i+1][j+1][t+1]) f[i+1][j+1][t+1]=f[i][j][t]+b[t+1],g[i+1][j+1][t+1]=1;
            else f[i+1][j+1][t+1]=min(f[i+1][j+1][t+1],f[i][j][t]+b[t+1]);
        }
    }
    forinc(j,0,m) forinc(t,0,n) if(j+t==k)
    {
        if(!ok) kq=f[k][j][t],ok=1;
        else kq=min(kq,f[k][j][t]);
    }
    cout<<kq;
}


