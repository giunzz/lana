#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=5e3+2;
const int M=8e3;
const int MOD=1e9+7;
const long long oo=1e18;
const int bm=1;
int n,m;
long long MIN=oo;
long long c[N],g[N];
long long f[N][M];
vector<int> a[N];

void sinh()
{
    freopen("TREE.inp","w",stdout);
    srand(time(0));
    n=4095;
    cout<<n<<endl<<0;
    for(int i=2;i<=n;i++)
        cout<<" "<<1;
    cout<<endl;
    for(int i=1;i<=n/2;i++)
        cout<<i<<" "<<i*2<<endl<<i<<" "<<i*2+1<<endl;
}

void DFS(int u, int p)
{
    int dem=0;
    int d[5];
    if ( a[u].size() == 1 )
        f[u][0]=c[u],f[u][1]=abs(c[u]-1),g[u]=1;
    if ( a[u].size() == 2 )
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            if ( v == p ) continue;
            DFS(v,u),g[u]+=g[v];
            for(int j=0;j<=g[u];j++)
                f[u][j]=f[v][j]+abs(c[u]-j);
        }
    if ( a[u].size() == 3 )
    {
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            if ( v == p ) continue;
            DFS(v,u),g[u]+=g[v],d[++dem]=v;
        }
        for(int i=0;i<=g[u];i++)
            for(int j=0;j<=min(g[d[1]],1ll*i);j++)
                f[u][i]=min(f[u][i],f[d[1]][j]+f[d[2]][i-j]+abs(i-c[u]));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].pb(v),a[v].pb(u);
    }
    memset(f,60,sizeof(f)),a[1].pb(0),DFS(1,0);
    for(int i=0;i<=g[1];i++) MIN=min(MIN,f[1][i]);
    cout<<MIN;
}
