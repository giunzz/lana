/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define maxn 5003
#define task "TREE"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, cnt = 0, tp[maxn], par[maxn], a[maxn], b[maxn], child[maxn], cc = 0, s[maxn], res = maxc;

pii luu[maxn];

vector <int> ke[maxn];

void DFS(int u)
{
    tp[++cnt] = u;
    for(auto v : ke[u])
    {
        if (par[u] == v) continue;
        if (ke[v].size() == 1)
        {
            child[u]++;
            luu[++cc] = MP(a[v], v);
        }
        par[v] = u;
        DFS(v);
        child[u] += child[v];
    }
}

void chuanbi()
{
    sort(luu+1, luu+cc+1);
    s[0] = 0;
    FOR(i, 1, cc)
        s[i] = s[i-1] + luu[i].F;
}

int tinh(int val)
{
    int pos = s[val];
    FOR(i, 1, child[1])
        if (i <= val) b[luu[i].S] = 0;
            else
            {
                pos += abs(luu[i].F - 1);
                b[luu[i].S] = 1;
            }
    FORD(i, n, 1)
    {
        int u = tp[i];
        int cur = 0;
        if (ke[u].size() == 1) continue;
        for (auto v : ke[u])
        {
            if (v == par[u]) continue;
            cur += b[v];
        }
        pos += abs(b[u] - cur);
        b[u] = cur;
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n-1)
    {
        int u, v;
        cin >> u >> v;
        ke[u].PB(v);
        ke[v].PB(u);
    }
    DFS(1);
    chuanbi();
    FOR(i, 0, child[1])
    {
        memcpy(b, a, sizeof (a));
        res = min(res, tinh(i));
    }
    cout << res;
    return 0;
}
