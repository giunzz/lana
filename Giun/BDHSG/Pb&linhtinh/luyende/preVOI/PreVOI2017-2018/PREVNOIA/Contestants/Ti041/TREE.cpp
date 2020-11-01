using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()
#define fn "TREE"    ///FILE_NAME_HERE
#define rep(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rrep(c,it) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)

template <class T,class U>
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T,class U,class V>
T addmod(T x,U y,V mod)
{
    return ((x + y)%mod + mod)%mod;
}
template <class T,class U,class V>
T submod(T x,U y,V mod)
{
    return ((x - y)%mod + mod)%mod;
}
template <class T,class U,class V>
T mulmod(T x,U y,V mod)
{
    return (ll)x*y%mod;
}
///---------------------------------------------------------END_TEMPLATE-------------------------------------------------------///

namespace task
{

const int N=5e3+5;
const int maxN=8200;
const ll inf=1e15;
vector <int> adj[N];
bool isLeaf[N];
ll a[N],dp[N][maxN],szt[N],b[N];
int n;
vector <int> topo;

void dfs(int u,int par)
{
    isLeaf[u]=true;
    for(int i=0; i<sz(adj[u]); ++i)
    {
        int v=adj[u][i];
        if(v==par)continue;
        isLeaf[u]=false;
        dfs(v,u);
    }
    topo.pb(u);
}

void _dfs(int u,int par)
{
    szt[u]=b[u];
    for(int i=0; i<sz(adj[u]); ++i)
    {
        int v = adj[u][i];
        if(v==par)continue;
        _dfs(v,u);
        szt[u] += szt[v];
    }
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i];
    for(int x,y,i=1; i<n; ++i)
    {
        cin>>x>>y;
        adj[x].pb(y);
    }
    dfs(1,1);
    for(int u=1; u<=n; ++u)
        if(isLeaf[u])
            b[u] = 1;
    _dfs(1,1);
    for(int u=1; u<=n; ++u)
        for(int k=0; k<=szt[1]; ++k)
            dp[u][k]=inf;
    for(int u=1; u<=n; ++u)
        if(isLeaf[u])
            for(int j=0; j<=1; ++j)
                minimize(dp[u][j],Abs(a[u] - j));
    if(n <= 500)
    {
        for(int i=0; i<sz(topo); ++i)
        {
            int u=topo[i];
            if(isLeaf[u])continue;
            if(sz(adj[u]) == 1)
            {
                int v=adj[u][0];
                for(int j=0; j<=szt[u]; ++j)
                    minimize(dp[u][j],dp[v][j] + Abs(a[u] - 1ll*j));
            }
            if(sz(adj[u]) == 2)
            {
                int lc=adj[u][0];
                int rc=adj[u][1];
                for(int j=0; j<=szt[u]; ++j)
                    for(int k=0; k<=szt[u]; ++k)
                        if(1ll*(j + k) <= szt[u])
                            minimize(dp[u][j + k],dp[lc][j] + dp[rc][k] + Abs(a[u] - 1ll*(j + k)));
            }
        }
    }
    else
    {
        for(int i=0; i<sz(topo); ++i)
        {
            int u=topo[i];
            if(isLeaf[u])continue;
            if(sz(adj[u]) == 1)
            {
                int v=adj[u][0];
                for(int j=0; j<=szt[v]; ++j)
                    minimize(dp[u][j],dp[v][j] + Abs(a[u] - j));
            }
            if(sz(adj[u]) == 2)
            {
                int lc=adj[u][0];
                int rc=adj[u][1];
                for(int j=0; j<=szt[lc]; ++j)
                    for(int k=0; k<=szt[rc]; ++k)
                        if(j + k <= szt[u])
                            minimize(dp[u][j + k],dp[lc][j] + dp[rc][k] + Abs(a[u] - (j + k)));
            }
        }
    }
    ll ans=inf;
    for(int k=0; k<=szt[1]; ++k)
      minimize(ans,dp[1][k]);
        cout<<ans;
}}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
#endif // ONLINE_JUDGE
    task::solve();
}
