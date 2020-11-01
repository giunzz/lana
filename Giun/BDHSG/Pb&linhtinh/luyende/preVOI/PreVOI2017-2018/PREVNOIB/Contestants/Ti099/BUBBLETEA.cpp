#include <bits/stdc++.h>
#define maxn int(1e6)
#define oo int64_t(1e12)

using namespace std;

int n, k, a[maxn], cl[maxn], pd[maxn], x[maxn], nho[maxn];
long long kc[maxn];
typedef pair <int, int> II;
typedef pair <II, int> III;
III e[maxn];
set <II> s;
vector <int> g[maxn];
long long ds;

void DFS(int xp)
{
    for(int i = 1; i <= n; ++i) cl[i] = 0;
    cl[xp] = 1; pd[xp] = 0; kc[xp] = 0;
    s.insert(II(kc[xp], xp));
    while(!s.empty())
    {
        II t = *s.begin();
        s.erase(t);
        int u = t.second;
        for(int i = 0; i < g[u].size(); ++i)
        {
            int k = g[u][i];
            int v = (k > 0) ? e[k].first.second : e[-k].first.first;
            int l = e[abs(k)].second;
            if(cl[v] == 0)
            {
                cl[v] = 1;
                pd[v] = u;
                kc[v] = kc[u] + l;
                s.insert(II(kc[v], v));
            }
            else if(kc[v] > kc[u] + 1)
            {
                s.erase(II(kc[v], v));
                kc[v] = kc[u] + l;
                s.insert(II(kc[v], v));
            }
        }
    }
}

void xuly()
{
    long long kq = 0;
    int i = 1;
    while(i < k)
    {
        DFS(a[x[i]]);
        kq = max(kq, kc[a[x[i + 1]]]);
        i += 2;
    }
    if(kq > 0) ds = min(kq, ds);
}

void thu(int i)
{
    if(i > k) {xuly(); return;}
    for(int j = 1; j <= k; ++j) if(nho[j] == 0)
    {
        x[i] = j;
        nho[j] = 1;
        thu(i + 1);
        nho[j] = 0;
    }
}

void sub1()
{
    ds = oo;
    thu(1);
    printf("%I64d", ds);
}

void sub2()
{
    DFS(a[1]);
    cout << kc[a[2]];
}

void  solve()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; ++i) scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        g[u].push_back(i);
        g[v].push_back(i);
        e[i] = III(II(u, v), c);
    }
    if(k <= 10) sub1();
}
int main()
{
    freopen("BUBBLETEA.inp", "r", stdin);
    freopen("BUBBLETEA.out", "w", stdout);
    solve();
}
