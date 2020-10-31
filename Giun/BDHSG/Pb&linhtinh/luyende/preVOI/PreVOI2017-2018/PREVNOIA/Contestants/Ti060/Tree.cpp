#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+5;

int n, sl = 0, ans = 0, res = LONG_MAX;
int a[maxn], la[maxn], ga[maxn];
vector <int> g[maxn];

int calc(int x)
{
    if (g[x].size() != 0) ga[x] = 0;
    for (int i=0; i<g[x].size(); i++)
        ga[x] += calc(g[x][i]);
    ans += abs(a[x] - ga[x]);
    return ga[x];
}

void backtrack(int x)
{
    for (int j=0; j<=1; j++)
    {
        //ans += abs(a[la[x]] - j);
        ga[la[x]] = j;
        if (x == sl)
        {
            ans = 0;
            int xxxx = calc(1);  //cout << xxxx << ' ';
            res = min(res, ans);
        }
        else backtrack(x + 1);
        //ans -= abs(a[la[x]] - j);
    }
}

int main()
{
    freopen("Tree.inp", "r", stdin);
    freopen("Tree.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        //ga[i] = a[i];
    }
    for (int i = 1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i=1; i<=n; i++)
        if (g[i].size() == 0)
            {
                sl++;
                la[sl] = i;
                //cout << la[sl] << ' ';
            }
        backtrack(1);
        cout << res;
}
