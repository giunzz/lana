#include <bits/stdc++.h>
#define maxn 5005
#define oo int(1e9)

using namespace std;

int n, m, id, ds;
int a[maxn], b[maxn], x[maxn], t[maxn], dau[maxn], cuoi[maxn], y[maxn], cl[maxn], pd[maxn];
vector <int> g[maxn];

void DFS(int u)
{
    cl[u] = 1;
    x[++id] = u;
    dau[u] = id;
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(cl[v] == 0)
        {
            pd[v] = u;
            DFS(v);
        }
    }
    cuoi[u] = id;
}

void xuly()
{
    int kq = 0;
    for(int i = 1; i <= m; ++i) b[t[i]] = y[i];
    for(int i = n; i > 0; --i)
    {
        int u = x[i];
        for(int j = dau[u]; j <= cuoi[u]; ++j) b[u] += b[j];
    }
    for(int i = 1; i <= n; ++i) kq += abs(a[i] - b[i]);
    ds = min(ds, kq);
}

void thu(int i)
{
    if(i > m) {xuly(); return;}
    for(int j = 0; j <= 1; ++j)
    {
        y[i] = j;
        thu(i + 1);
    }
}

void sub1()
{
    for(int i = 1; i <= n; ++i) cl[i] = 0;
    id = 0, m = 0;
    DFS(1);
    for(int i = 1; i <= n; ++i) if(dau[i] == cuoi[i]) t[++m] = i;
    ds = oo;
    thu(1);
    printf("%d", ds);
}

void sub2()
{
    sub1();
}

void solve()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    if(n <= 30) sub1();
    else sub2();
}

int main()
{
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);
    solve();
}
