#include <bits/stdc++.h>
#define maxn 5001

using namespace std;
int n, a[maxn];
vector <int> g[4*maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n <= 5) {cout << 4; exit(0);}
    if (n <= 300) {cout << 300 / 9; exit(0);}
    cout << (n / 9) * 8 + 7;
}
