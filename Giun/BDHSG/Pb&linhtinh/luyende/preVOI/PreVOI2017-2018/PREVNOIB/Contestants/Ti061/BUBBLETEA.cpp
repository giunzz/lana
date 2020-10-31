#include <bits/stdc++.h>
#define maxn 50005
#define maxC 1000000007
#define Reset(d, a) memset(d, a, sizeof(d))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define Length(a) int(a.length())
#define Size(a) int(a.size())
#define F first
#define S second
#define Task "BUBBLETEA"

using namespace std;

int n, k, a[maxn], c[maxn], mark[maxn], way[maxn], answer = maxC;
map <pair <int, int>, bool> d;
bool dd[maxn];
vector <pair <int, int>> b[maxn];

void Setup()
{
    cin >> n >> k;
    FOR(i, 1, k) cin >> a[i];

    int u, v, w;
    FOR(i, 1, n - 1)
    {
        cin >> u >> v >> w;
        b[u].push_back(make_pair(v, w));
        b[v].push_back(make_pair(u, w));
    }
}

void DFS(int u)
{
    for (auto p : b[u])
        if (!mark[p.F])
        {
            mark[p.F] = u;
            way[p.F] = way[u] + p.S;
            DFS(p.F);
        }
}

void Process(int id)
{
    if (id > k)
    {
        d.clear();
        int result = -1;
        for (int i = 1; i <= k; i += 2)
        {
            Reset(mark, 0);
            Reset(way, 0);
            mark[c[i]] = -1;
            DFS(c[i]);
            int u = c[i + 1];
            while (u != c[i])
            {
                if (d[make_pair(mark[u], u)] == true) return;
                d[make_pair(mark[u], u)] = true;
                u = mark[u];
            }

            result = max(result, way[c[i + 1]]);
        }
        answer = min(answer, result);
        return;
    }
    FOR(i, 1, k)
        if (!dd[i])
        {
            c[i] = a[id];
            dd[i] = true;
            Process(id + 1);
            dd[i] = false;
        }
}

void Operate()
{
    Process(1);
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    Setup();
    Operate();
}
