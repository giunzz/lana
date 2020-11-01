#include <bits/stdc++.h>
#define FILE "TREE"

using namespace std;
const int maxn=5e3+5, oo=1e9;

int n, ans, p[maxn], mx[maxn], s[maxn][8500];
vector <int> a[maxn];

void Build(int u)
{
    if (!a[u].size()) mx[u] = 1;
    else for (int &v:a[u]){ Build(v); mx[u] += mx[v]; }
    if (p[u] > mx[u]) ans += p[u]-mx[u], p[u] = mx[u];
    if (!a[u].size()) { if (p[u]) s[u][0]++; else s[u][1]++; }
    else if (a[u].size() == 1)
    {
        int v = a[u][0];
        for (int s1=0; s1<=mx[v]; s1++) s[u][s1] = s[v][s1], s[u][s1] += abs(s1-p[u]);
    }
    else
    {
        int v1 = a[u][0], v2 = a[u][1];
        for (int su=0; su<=mx[u]; su++) s[u][su] = oo;
        for (int s1=0; s1<=mx[v1]; s1++)
            for (int s2=0; s2<=mx[v2]; s2++)
                s[u][s1+s2] = min(s[u][s1+s2],s[v1][s1]+s[v2][s2]);
        for (int su=0; su<=mx[u]; su++) s[u][su] += abs(su-p[u]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    cin >> n; for (int i=1; i<=n; i++) cin >> p[i];
    for (int i=1; i<n; i++){ int u, v; cin >> u >> v; a[u].push_back(v); }
    Build(1); int res = oo; for (int s1=0; s1<=mx[1]; s1++) res = min(res,s[1][s1]);
    cout << ans + res;
    return 0;
}
