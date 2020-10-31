#include<bits/stdc++.h>

using namespace std;

const int maxN = 5007;
int n, a[maxN], fake[maxN], par[maxN], res, tes;
vector<int> leaf, check;
bool kt[maxN];

int main()
{
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)    cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        par[y] = x; kt[x] = true;
    }
    par[1] = -1;
    for (int i = 1; i <= n; i++)
        if (kt[i] == false) leaf.push_back(i);
    int d = leaf.size();    res = 1e9 + 7;
    for (int i = 0; i < (1 << d); i++)
    {
        for (int j = 1; j <= n; j++)    fake[j] = 0;
        for (int j = 0; j < d; j++)
            if ((i & (1 << j)) == 0)    fake[leaf[j]] = 0;
            else    fake[leaf[j]] = 1;
        for (int j = 0; j < leaf.size(); j++)
        {
            int u = leaf[j];
            while (1)
            {
                u = par[u];
                if (u == -1)    break;
                fake[u] += fake[leaf[j]];
            }
        }
        tes = 0;
        for (int j = 1; j <= n; j++)
            tes += abs(fake[j] - a[j]);
        res = min(res, tes);
    }
    cout << res;
    return 0;
}
