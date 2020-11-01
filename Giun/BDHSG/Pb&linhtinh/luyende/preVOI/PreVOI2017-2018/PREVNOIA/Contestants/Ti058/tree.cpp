#include<bits/stdc++.h>
using namespace std;
const int N=5002;
int d[N], a[N], n, res, sum, tmp;
bool check[N];
vector<int> seed, V[N];
void dfs(int u, int dad)
{
    bool tt=0;
    for ( int i=0; i<V[u].size(); i++ )
        if ( V[u][i]!=dad )
        {
            dfs(V[u][i], u);
            tt=1;
        }
    if ( !tt )
    {
        seed.push_back(u); tmp++;
        check[u]=1;
    }
}
int dfs2(int u, int dad)
{
    if ( check[u] )
    {
        sum+=abs(a[u]-d[u]);
        return d[u];
    }
    d[u]=0;
    for ( int i=0; i<V[u].size(); i++ )
        if ( V[u][i]!=dad )
            d[u]=d[u]+dfs2(V[u][i], u);
    sum+=abs(a[u]-d[u]);
    return d[u];
}
void track(int u)
{
    if ( u==seed.size() )
    {
        sum=0;
        dfs2(1, 0);
        res=min(res, sum);
        return;
    }
    for ( int i=0; i<=1; i++ )
    {
        d[seed[u]]=i;
        track(u+1);
    }
}
int main()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    for ( int i=1; i<=n; i++ ) scanf("%d", &a[i]);
    for ( int i=1; i<n; i++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        V[x].push_back(y);
        V[y].push_back(x);
    }
    res=25e6; tmp=0;
    dfs(1, 0);
    sort(seed.begin(), seed.end());
    track(0);
    printf("%d", res);
}
