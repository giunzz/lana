#include <bits/stdc++.h>
#define task "tree"
#define maxn 5005
#define oo int(2e9)

using namespace std;

int n, id;
int a[maxn];
vector <int> g[maxn];
int st[maxn], fi[maxn];
int deg[maxn], cl[maxn];
int prv[maxn], tp[maxn];

void dfs(int u)
{
    cl[u] = 1; tp[++id] = u; st[u] = id;
    for(int i = 0; i < deg[u]; ++i)
    {
        int v = g[u][i];
        if(!cl[v])
        {
            dfs(v);
            prv[v] = u;
        }
    }
    fi[u] = id;
}

int m, ds;
int b[maxn], x[maxn];
int c[maxn], d[maxn];

void xuly()
{
    for(int i = 1; i <= n; ++i) c[i] = a[i];
    for(int i = 1; i <= n; ++i) d[i] = 0;
    for(int i = 1; i <= m; ++i) d[b[i]] = x[i];
    for(int i = n; i >= 1; --i)
    {
        int u = tp[i];
        d[prv[u]] += d[u];
    }
    int kq = 0;
    for(int i = 1; i <= n; ++i) kq += abs(c[i] - d[i]);
    ds = min(ds, kq);
}

void thu(int i)
{
    if(i > m){xuly(); return;}
    for(int j = 0; j <= 1; ++j)
    {
        x[i] = j;
        thu(i + 1);
    }
}

void sub1()
{
    for(int i = 1; i <= n; ++i) if(st[i] == i && fi[i] == i) b[++m] = i;
    ds = oo;
    thu(1);
    printf("%d", ds);
}

void sub2()
{
    sub1();
}

void sub3()
{
    sub2();
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v), ++deg[u];
        g[v].push_back(u), ++deg[v];
    }
    for(int i = 1; i <= n; ++i) cl[i] = 0;
    prv[1] = 0; id = 0;
    dfs(1);
    if(n <= 30) sub1();
    else if(n <= 300) sub2();
    else sub3();
}
