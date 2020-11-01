#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define Task "TREE"
using namespace std;
int n,b[maxn],cnt,par[maxn],ans = maxc,c[maxn],pos[maxn],temp;
vector <int> a[maxn];
bool dd[maxn];
void dfs(int u)
{
    if (a[u].size() == 1) c[u] = dd[pos[u]];
    for (int v : a[u])
        if (v != par[u])
        {
            par[v] = u;
            dfs(v);
            c[u] += c[v];
        }
}
void trau(int have)
{
    if (have == cnt)
    {
        FOR(i,1,n) c[i] = 0;
        dfs(1);
        temp = 0;
        FOR(i,1,n) temp += abs(c[i] - b[i]);
        ans = min(ans,temp);
        return;
    }
    ++have;
    FOR(i,0,1)
        {
            dd[have] = i;
            trau(have);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> b[i];
    if ( n == 1)
    {
        if (b[1] == 1 || !b[1]) cout << 0;
        else cout << b[1] - 1;
        return 0;
    }
    FOR(i,1,n-1)
    {
        int x,y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    FOR(i,2,n) if ((int) a[i].size() == 1) pos[i] = ++cnt;
    trau(0);
    cout << ans;
    return 0;
}
