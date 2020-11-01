#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));


const long long N = 1e5 + 10;
const long long INF = 1e18;
struct edge
{
    long long foo, bar, len;
    edge (long long foo = 0, long long bar = 0, long long len = 0) : foo(foo), bar(bar), len(len) {}
    long long findOther (long long u) { return foo + bar - u; }
} e[N];

long long n, nPark;
vector<long long> g[N];
bool isPark[N];
long long depth[N];
long long countPark[N];
long long lowest[N];
long long dp[N];
bool ok = true;
bool depthCompare (long long foo, long long bar)
{
    return depth[foo] < depth[bar];
}
bool check (long long foo, vector<long long> &t, long long ban, long long lim)
{
    long long ptr = t.size() - 1;
    long long match = 0;
    for (long long i = 0; i < ptr; i++)
    {
        if (i == ban) continue;
        if ((depth[t[i]] + depth[t[ptr]] - 2 * depth[foo] > lim || ptr == ban) && ptr > i)
        {
            ptr--;
        }
        if ((depth[t[i]] + depth[t[ptr]] - 2 * depth[foo]) <= lim) match += 2;
    }
    if (ban == -1) return match == (long long)t.size() - 1;
    return match == (long long)t.size() - 2;
}

void dfs (long long foo, long long parent, long long lim)
{
    if (not ok) return;
    countPark[foo] = isPark[foo];
    dp[foo] = -INF;
    vector<long long> t;
    for (long long i = 0; i < g[foo].size(); i++)
    {
        long long ie = g[foo][i];
        long long bar = e[ie].findOther(foo);
        if (bar == parent) continue;
        depth[bar] = depth[foo] + e[ie].len;
        dfs(bar, foo, lim);
        if (not ok) return;
        countPark[foo] += countPark[bar];
        dp[foo] = max(dp[foo], dp[bar]);
        if (countPark[bar] & 1)
        {
            t.push_back(lowest[bar]);
        }
    }
    if (not ok) return;
    if (isPark[foo])
    {
        t.push_back(foo);
    }
    vector<bool> calc;
    calc.resize(t.size());
    for (long long i = 0; i < t.size(); i++) calc[i] = false;
    sort (t.begin(), t.end(), depthCompare);
    if (t.size() == 0) return;

    long long ptr = t.size() - 1;

    if (t.size() % 2 == 0)
    {
        if (not check(foo, t, -1, lim))
            ok = false;
    }
    else
    {
        long long lo = 0, hi = t.size() - 1, po = -1;
        while (lo <= hi)
        {
            long long mi = (lo + hi) / 2;
            if (check(foo, t, mi, lim))
            {
                po = mi;
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        if (po == -1) ok = false;
        else lowest[foo] = t[po];
    }
}

int main()
{
    #define file "BUBBLETEA"
    freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    //ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> nPark;
    for (long long ip = 1; ip <= nPark; ip++)
    {
        long long x;
        cin >> x;
        isPark[x] = 1;
    }
    for (long long ie = 1; ie < n; ie++)
    {
        long long foo, bar, len;
        cin >> foo >> bar >> len;
        e[ie] = edge(foo, bar, len);        g[foo].push_back(ie);
        g[bar].push_back(ie);
    }

    long long lo = 0, hi = INF, ret;
    while (lo <= hi)
    {
        long long mi = (lo + hi) / 2;
        ok = true;
        dfs(1, 0, mi);
        if (ok)
        {
            ret = mi;
            hi = mi - 1;
        }
        else lo = mi + 1;
    }

    cout << ret;
    return 0;
}

