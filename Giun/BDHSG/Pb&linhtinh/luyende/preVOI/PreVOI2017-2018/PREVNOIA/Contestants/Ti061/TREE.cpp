#include <bits/stdc++.h>
#define maxn 5005
#define maxC 1000000007
#define Reset(d, a) memset(d, a, sizeof(d))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
#define Length(a) int(a.length())
#define Size(a) int(a.size())
#define F first
#define S second
#define Task "TREE"

using namespace std;

int n, a[maxn], num = 0, d[maxn];
long long result, answer = 1ll * maxC * maxC, c[maxn];
//bool dd[maxn];
vector <int> b[maxn];

void Setup()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    int u, v;
    FOR(i, 1, n - 1)
    {
        cin >> u >> v;
        b[u].push_back(v);
        //dad[v] = u;
    }
    FOR(i, 1, n) if (!Size(b[i])) d[++num] = i, c[i] = a[i];
}

/*void DFS(int u)
{
    //dd[u] = true;
    h[u] = h[dad[u]] + 1;
    if (h[u] > maxh) maxh = h[u], d[num = 1] = u;
        else if (h[u] == maxh) d[++num] = u;
    for (auto v : b[u]) DFS(v);
}*/

void DFS_2(int u)
{
    //dd[u] = true;
    long long sum = 0;
    for (auto v : b[u])
    {
        DFS_2(v);
        sum += c[v];
    }
    if (Size(b[u]) > 0) c[u] = sum;
    result += abs(c[u] - a[u]);
}

void Process(int k)
{
    if (k > num)
    {
        result = 0;
        //FOR(i, 1, num) result += abs(c[d[i]] - a[d[i]]);
        //Reset(dd, 0);
        DFS_2(1);
        answer = min(answer, result);
        //cout << result << " ";
        return;
    }
    FOR(i, 0, 1)
    {
        c[d[k]] = i;
        Process(k + 1);
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
