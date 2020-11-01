#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e3 + 7;
const int inf = 1e18 + 7;
vector<int> a[MAXN];
vector<int> la;
int n, f[MAXN], l, x[MAXN], val[MAXN], memo[MAXN], res = inf , memo2[MAXN];

int ct(int u, int p)
{
    //int dem = 0;
    if (memo[u] != -1) return memo[u];
    int &cur = memo[u];
    cur = 0;
    for(int i = 0 ; i < a[u].size() ; i++)
    {
        int v = a[u][i];
        if (v != p)
            cur += ct(v, u);
    }
    return cur;
}

void solve()
{
    int dem = 0;
    memset(memo, -1, sizeof memo);
    for(int ii = 0 ; ii <= l ; ii++)
        memo[la[ii]] = x[ii];
    int temp = ct(1, 0);
    for(int ii = 1 ; ii <= n ; ii++)
        dem += abs(memo[ii] - f[ii]);
    res = min(res, dem);
}

void Try(int i)
{
    for(int j = 0 ; j <= 1 ; j++)
    {
        x[i] = j;
        if (i == l) solve();
        else Try(i + 1);
    }
}

void dfs(int u, int p)
{
    if (a[u].size() == 1 && u != 1)
    {
        la.push_back(u);
    }
    for(int j = 0 ; j < a[u].size() ; j++)
    {
        //kt = 1;
        int v = a[u][j];
        if (v != p)
        {
            dfs(v, u);
        }
    }
}

int han(int u, int p)
{
    //int dem = 0;
    if (memo2[u] != -1) return memo2[u];
    int &cur = memo2[u];
    cur = 0;
    for(int i = 0 ; i < a[u].size() ; i++)
    {
        int v = a[u][i];
        if (v != p)
            cur += han(v, u);
    }
    return cur;
}


main()
{
    memset(memo, -1, sizeof  memo);
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> f[i];
    for(int i = 1 ; i < n ; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    l = la.size() - 1;
    if (n <= 30) {
        Try(0);
        cout << res;
        return 0;
    }
    memset(memo2 , -1 , sizeof memo2);
    for(int ii = 0 ; ii <= l ; ii++)
        memo2[la[ii]] = 1;

    int k = han(1 , 0) , value = 0;

    for(int ii = 1 ; ii <= n ; ii++)
        value += abs(f[ii] - memo2[ii]);
    cout << value;
    return 0;
}
