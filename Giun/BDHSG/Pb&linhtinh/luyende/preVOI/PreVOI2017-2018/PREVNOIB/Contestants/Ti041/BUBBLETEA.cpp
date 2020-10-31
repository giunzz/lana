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
#define fn "BUBBLETEA"    ///FILE_NAME_HERE
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

namespace task{

const int N=5e4+5;
const ll inf=1e17;
const int lg=18;
vector <pii> adj[N];
int x[N],dp[N][lg + 2],cnt[N],cc[N],d[N],g[N];
int n,k;
int mark[N];
ll ans=inf;

void dfs(int u,int par)
{
    dp[u][0]=par;
    for(int i=0;i<sz(adj[u]);++i)
    {
        int v=adj[u][i].fir;
        int c=adj[u][i].sec;
        if(v==par)continue;
        cc[v]=c;
        d[v] = d[u] + 1;
        dfs(v,u);
    }
}

int lca(int u,int v)
{
    if(d[u] < d[v])swap(u,v);
    for(int j=lg;j>=0;--j)
        if(d[dp[u][j]] >= d[v])
          u=dp[u][j];
    if(u==v)return u;
    for(int j=lg;j>=0;--j)
        if(dp[u][j] ^ dp[v][j])
          u=dp[u][j],v=dp[v][j];
    return dp[u][0];
}

ll up(int u,int v,int t)
{
    int p=lca(u,v);
    ll ret=0;
    while(u !=p)
    {
        if(mark[u])return -inf;
        ret+=1ll*cc[u];
        mark[u]=t;
        u=dp[u][0];
    }
    while(v != p)
    {
        if(mark[v])return -inf;
        ret+=1ll*cc[v];
        mark[v]=t;
        v=dp[v][0];
    }
    return ret;
}

ll check()
{
    ll ret=-inf;
    int t=1;
    for(int j=1;j<=k;++j)
        for(int i=1;i<=k;++i)
         if(i != j and g[i]==g[j])
    {
        ll ok=up(x[i],x[j],t);
        maximize(ret,ok);
        ++t;
    }
    return ret;
}

void bt(int idx,int j)
{
    if(j==k + 1)
    {
        fill(mark + 1,mark + 1 + n,0);
        minimize(ans,check());
        return ;
    }
    if(cnt[idx] == 2)++idx;
    if(cnt[idx] < 2)
    {
        g[j]=idx;
        ++cnt[idx];
        bt(idx,j + 1);
        --cnt[idx];
    }
}

void sub1()
{
    bt(1,1);
    cout<<ans;
}

void addEdges(int u,int v,int c){adj[u].pb(mp(v,c)),adj[v].pb(mp(u,c));}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;++i)
        cin>>x[i];
    for(int u,v,c,i=1;i<n;++i)
        cin>>u>>v>>c,addEdges(u,v,c);
    dfs(1,1);
    for(int j=1;j<=lg;++j)
        for(int i=1;i<=n;++i)
          dp[i][j]=dp[dp[i][j-1]][j-1];
    if(k <= 10)sub1();
    else
    {
        cout<<-1;
    }
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
