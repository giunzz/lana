#include <bits/stdc++.h>
#define task "bubbletea"
#define maxn int(5e4+5)
#define oo int64_t(1e14)
#define ft first
#define sd second

using namespace std;
typedef pair <int,int> II;
typedef pair <II,int> III;

int n, k;
int64_t ds;
set <II> s;
int x[maxn];
III e[maxn];
int64_t kc[maxn];
vector <int> g[maxn];
int a[maxn], deg[maxn];
int nho[maxn], cl[maxn];

void dfs(int u)
{
    cl[u] = 1; kc[u] = 0;
    s.insert(II(kc[u], u));
    while(!s.empty())
    {
        II t = *s.begin(); s.erase(t);
        int u = t.sd;
        for(int i = 0; i < deg[u]; ++i)
        {
            int l = g[u][i];
            int v = (l > 0) ? e[l].ft.sd : e[-l].ft.ft;
            int w = e[abs(l)].sd;
            if(!cl[v])
            {
                cl[v] = 1;
                kc[v] = kc[u] + w;
                s.insert(II(kc[v], v));
            }
            else if(kc[v] > kc[u] + w)
            {
                s.erase(II(kc[v], v));
                kc[v] = kc[u] + w;
                s.insert(II(kc[v], v));
            }
        }
    }
}

void xuly()
{
    int64_t kq = 0;
    for(int i = 1; i < k; i += 2)
    {
        for(int i = 1; i <= k; ++i) cl[i] = 0, kc[a[x[i]]] = oo;
        dfs(a[x[i]]);
        if(kc[a[x[i + 1]]] == oo)
        {
            kq = -1;
            break;
        }
        kq = max(kq, kc[a[x[i + 1]]]);
    }
    if(kq > 0) ds = min(ds, kq);
}

void thu(int i)
{
    if(i > k)
    {
        xuly();
        return;
    }
    for(int j = 1; j <= k; ++j) if(nho[j] == 0)
    {
        x[i] = j;
        ++nho[j];
        thu(i + 1);
        --nho[j];
    }
}

void sub1()
{
    ds = oo;
    for(int i = 1; i <= k; ++i) nho[i] = 0;
    thu(1);
    if(ds == oo) printf("-1");
    else printf("%I64d", ds);
}

void sub2()
{
    printf("-1");
}

void sub3()
{
    sub2();
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; ++i) scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[i] = III(II(u, v), w);
        g[u].push_back(i), ++deg[u];
        g[v].push_back(-i), ++deg[v];
    }
    if(k <= 10) sub1();
    else if(k == n) sub2();
    else sub3();
}
