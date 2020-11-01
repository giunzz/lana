#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn=5001;
int n, a[maxn], vl[maxn], re[maxn], prv[maxn];
vector<int> g[maxn];
bool cl[maxn];
int read_int()
{
    int kq = 0, sign = 1;
    char c = getchar();
    while (c <'0' || c >'9')
    {
        if (c == '-')
            sign = -1;
        c = getchar();
    }
    while (c>='0' && c <='9')
        kq = kq*10+c-'0', c= getchar();
    return kq*sign;
}

void DFS1(int u)
{
    cl[u] = true;
    for (int i = 0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if (!cl[v])
        {
            cl[v] = true;
            prv[v] = u;
            DFS1(v);
            vl[u] += vl[v];

        }
    }
    if (g[u].size() == 0)
        vl[u] = a[u];
    re[u] = a[u] - vl[u];
}


int main()
{
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n = read_int();
    for (int i = 1; i<=n; i++)
        a[i] = read_int();
    for (int i = 1; i<n; i++)
    {
        int u = read_int(), v = read_int();
        g[u].push_back(v);
    }
    DFS1(1);
    cout << n-1;
    return 0;
}
