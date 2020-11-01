#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=5e4+2;
const int MOD=1e9+7;
const int bm=1;
int n,m,k,r;
int x[N],d[N];
long long MAX=0;
long long f[N],dd[N];
vector<ii> a[N];

void sinh()
{
    freopen(".inp","w",stdout);
    srand(time(0));
}

void DFS(int u, int p)
{
    int l=r+1;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i].x;
        int c=a[u][i].y;
        if ( v == p ) continue;
        f[v]=f[u]+c,DFS(v,u);
        if ( x[v] ) d[++r]=v;
    }
    if ( (r - l + 1) % 2 == 0 )
    {
        for(int i=l;i<=r;i++) dd[i]=f[d[i]]-f[u];
        sort(dd+l,dd+r+1);
        for(int i=l;i<=r/2;i++) MAX=max(MAX,dd[i]+dd[r-i+l]);
        r=l-1;
    }
    if ( r - l + 1 && x[u] )
    {
        for(int i=l;i<=r;i++) dd[i]=f[d[i]]-f[u];
        sort(dd+l,dd+r+1),MAX=max(MAX,dd[r]);
        for(int i=l;i<=r/2;i++) MAX=max(MAX,dd[i]+dd[r-i+l-1]);
        r=l-1;
    }
}

bool dfs(int u, int p)
{
    int l=r+1;
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i].x;
        int c=a[u][i].y;
        if ( v == p ) continue;
        if ( dfs(v,u) ) d[++r]=v,dd[r]=c;
    }
    if ( ( r - l + 1 ) % 2 )
    {
        sort(dd+l,dd+r+1),MAX=max(MAX,dd[r]);
        for(int i=l;i<=r;i++)
            MAX=max(MAX,dd[i]+dd[r-i+l-1]);
        r=l-1;
        return 0;
    }
    else
    {
        sort(dd+l,dd+r+1);
        for(int i=l;i<=r;i++)
            MAX=max(MAX,dd[i]+dd[r-i+l]);
        r=l-1;
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    freopen("BUBBLETEA.inp","r",stdin);
    freopen("BUBBLETEA.out","w",stdout);
    cin>>n>>k;
    for(int y,i=1;i<=k;i++) cin>>y,x[y]=1;
    for(int i=1;i<n;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        a[u].pb(ii(v,c)),a[v].pb(ii(u,c));
    }
    if ( n == k ) dfs(1,0);
    else DFS(1,0);
    cout<<MAX;
}
