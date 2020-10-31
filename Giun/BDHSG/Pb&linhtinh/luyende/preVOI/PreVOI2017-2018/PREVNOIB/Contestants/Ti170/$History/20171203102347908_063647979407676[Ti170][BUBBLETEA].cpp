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
#define maxn 10005
#define task "BUBBLETEA"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, k, tr[maxn][maxn], t[maxn], d[maxn][maxn], res = maxc;

vector <pii> ke[maxn];

void IJK(int x, int mang[], int id)
{
    FOR(i, 1, n) mang[i] = maxc;
    mang[x] = 0;
    priority_queue <pii> q;
    q.push(MP(0, x));
    while(sz(q))
    {
        int u = q.top().S;
        int l = -q.top().F;
        q.pop();
        if (l > mang[u]) continue;
        for (auto p : ke[u])
        {
            int v = p.F;
            int w = p.S;
            if (mang[v] > mang[u] + w)
            {
                mang[v] = mang[u] + w;
                tr[id][v] = u;
                q.push(MP(-mang[v], v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, k)
        cin >> t[i];
    FOR(i, 1, n-1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB(MP(v, w));
        ke[v].PB(MP(u, w));
    }
    FOR(i, 1, k)
        IJK(t[i], d[t[i]], t[i]);
    FOR(i, 1, k)
    {
        int ans = -maxc;
        FOR(j, 1, k)
        {
            if (i == j) continue;
            ans = max(ans , d[t[i]][t[j]]);
        }
        res = min(res, ans);
    }
    cout << res;
    return 0;
}
