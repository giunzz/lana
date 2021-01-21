#include <bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long 
const ll maxn = 1e4+7;
struct edge
{
    int u , v , w; 
};
bool cmp (edge &a , edge &b)
{
    return (a.w < b.w);
}
int cha[maxn] ={0} , hang[maxn]={0};

int find (int u)
{
    if (cha[u] != u) cha = find(cha[u]);
    return cha[u];
}

bool check (int u , int v)
{
    u = find(u) , v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v] = u;
    return true;
}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    int m , n;
    cin >> n >> m; // n dinh m canh
    vector<edge> g(m);
    for (edge &x :g) cin >> x.u >> x.v >> x.w;
    sort(g.begin(), g.end() , cmp);
    for (int i = 0 ; i < g.size() ; i++)
    {
        cerr << g[i].u << " " << g[i].v << " " << g[i].w << endl;
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) cha[i] = i , hang[i] = 0;
    for (edge &x : g)
    {
        if (check(x.u, x.v)) ans += x.w;
    }
    cout << ans;6
}

