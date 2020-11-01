/*
*/
#define taskname "TREE"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
const int maxN = 5001;
int n, a[maxN], b[maxN], parent[maxN];
int BestCost, BestLeaf;
vector<int> adj[maxN];

template <typename T>
inline bool Minimize(T& Target, T Value)
{
    if (Target <= Value) return false;
    Target = Value;
    return true;
}

inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int res = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        res = res * 10 + c - '0';
    return res;
}

void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}


void Enter()
{
    n = ReadInt();
    for (int i = 1; i <= n; ++i)
        a[i] = ReadInt();
    for (int i = n - 1; i > 0; --i)
    {
        int x = ReadInt();
        int y = ReadInt();
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void Visit(int u)
{
    for (int i = 0; i < (int)adj[u].size(); ++i)
        if (adj[u][i] == parent[u])
        {
            adj[u][i] = adj[u].back();
            adj[u].pop_back();
            break;
        }
    for (int v: adj[u])
    {
        parent[v] = u;
        Visit(v);
    }
}

void Scan(int u, int Cost)
{
    if (a[u] > b[u]) --Cost;
    else ++Cost;
    if (adj[u].empty() && b[u] == 0 && Minimize(BestCost, Cost))
        BestLeaf = u;
    for (int v: adj[u])
        Scan(v, Cost);
}

void Solve()
{
    while (true)
    {
        BestCost = 0;
        Scan(1, 0);
        if (BestCost >= 0) break;
        for (int v = BestLeaf; v != -1; v = parent[v])
            ++b[v];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += abs(a[i] - b[i]);
    WriteInt(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    parent[1] = -1;
    Visit(1);
    Solve();
}
