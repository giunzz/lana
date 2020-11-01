#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e3+5;

int n , a[maxn] , b[maxn];
vector < int > adj[maxn]; // adj[x][i] = y : y la con cua x
int f[maxn]; // tong cac nut con cua u;
long long ans = 0 , Ans = 1e18+5;
int deep[maxn]; //do sau tren cay
bool ok[maxn]; //mang danh dau cho dfs
int max_deep; // do sau lon nhat tren cay
vector < int > adj_deep[maxn]; // luu cac nut co cung do sau
int par[maxn];

void fr()
{
    freopen ("TREE.INP" , "r" , stdin);
    freopen ("TREE.OUT" , "w" , stdout);
}

void enter()
{
    int x , y;
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf("%d" , &b[i]);
        a[i] = b[i];
    }
    for (int i = 1 ; i < n ; ++i)
    {
        scanf("%d%d" , &x , &y);
        adj[x].push_back(y);
        par[y] = x;
    }
}

void dfs(int u)
{
    ok[u] = 0;
    for (int i = 0 ; i < adj[u].size() ; ++i)
    {
        int v = adj[u][i];
        if (ok[v])
        {
            deep[v] = deep[u] + 1;
            adj_deep[deep[v]].push_back(v);
            dfs(v);
        }
    }
}

void solve()
{
    memset (ok , 1 , sizeof ok);
    adj_deep[0].push_back(1);
    dfs(1);
    for (int i = 1 ; i <= n ; ++i)
        max_deep = max(max_deep , deep[i]);

    // chuyen tat ca nut la ve 1
    memset (f , 0 , sizeof f);
    for (int i = 1 ; i <= n ; ++i)
        if (adj[i].size() == 0)
        {
            ans += abs(a[i] - 1);
            a[i] = 1;
        }

    for (int i = max_deep - 1 ; i >= 0 ; --i)
        for (int j = 0 ; j < adj_deep[i].size() ; ++j)
        {
            int _j = adj_deep[i][j];
            if (adj[_j].size())
            {
                for (int u = 0 ; u < adj[_j].size() ; ++u)
                    f[_j] += a[adj[_j][u]];
                ans += abs(f[_j] - a[_j]);
                a[_j] = f[_j];
            }
        }
    Ans = min(ans , Ans);

    //chuyen tat ca nut la ve 0
    ans = 0;
    memset (f , 0 , sizeof f);
    for (int i = 1 ; i <= n ; ++i)
        a[i] = b[i];
    for (int i = 1 ; i <= n ; ++i)
        if (adj[i].size() == 0)
        {
            ans += a[i];
            a[i] = 0;
        }
    for (int i = max_deep - 1 ; i >= 0 ; --i)
        for (int j = 0 ; j < adj_deep[i].size() ; ++j)
        {
            int _j = adj_deep[i][j];
            if (adj[_j].size())
            {
                for (int u = 0 ; u < adj[_j].size() ; ++u)
                    f[_j] += a[adj[_j][u]];
                ans += abs(f[_j] - a[_j]);
                a[_j] = f[_j];
            }
        }
    Ans = min(ans , Ans);

    //neu co 2 nut la thi tong = 1 , neu chi co 1 nut thi bang 0
    ans = 0;
    memset (f , 0 , sizeof f);
    memset (ok , 1 ,sizeof ok);
    for (int i = 1 ; i <= n ; ++i)
        a[i] = b[i];
    for (int i = 1 ; i <= n ; ++i)
        if (!adj[i].size() && ok[i])
        {
            if (adj[par[i]].size() == 1)
            {
                ok[i] = 0;
                ans += a[i];
                f[par[i]] = 0;
            }
            else
            {
                int tmp = 0;
                for (int j = 0 ; j <= 1 ; ++j)
                {
                    tmp += a[adj[par[i]][j]];
                    ok[adj[par[i]][j]] = 0;
                }
                ans += abs (tmp - 1);
                f[par[i]] = 1;
            }
        }
    for (int j = 0 ; j < adj_deep[max_deep - 1].size() ; ++j)
    {
        int _j = adj_deep[max_deep - 1][j];
        if (adj[_j].size())
        {
            ans += abs(f[_j] - a[_j]);
            a[_j] = f[_j];
        }
    }
    for (int i = max_deep - 2 ; i >= 0 ; --i)
        for (int j = 0 ; j < adj_deep[i].size() ; ++j)
        {
            int _j = adj_deep[i][j];
            if (adj[_j].size())
            {
                for (int u = 0 ; u < adj[_j].size() ; ++u)
                    f[_j] += a[adj[_j][u]];
                ans += abs(f[_j] - a[_j]);
                a[_j] = f[_j];
            }
        }
    Ans = min(ans , Ans);

    //neu co 2 nut la thi tong = 1 ; chi co 1 nut thi bang 1
    ans = 0;
    memset (f , 0 , sizeof f);
    memset (ok , 1 ,sizeof ok);
    for (int i = 1 ; i <= n ; ++i)
        a[i] = b[i];
    for (int i = 1 ; i <= n ; ++i)
        if (!adj[i].size() && ok[i])
        {
            if (adj[par[i]].size() == 1)
            {
                ok[i] = 0;
                ans += abs(a[i] - 1);
                f[par[i]] = 1;
            }
            else
            {
                int tmp = 0;
                for (int j = 0 ; j <= 1 ; ++j)
                {
                    tmp += a[adj[par[i]][j]];
                    ok[adj[par[i]][j]] = 0;
                }
                ans += abs (tmp - 1);
                f[par[i]] = 1;
            }
        }
    for (int j = 0 ; j < adj_deep[max_deep - 1].size() ; ++j)
    {
        int _j = adj_deep[max_deep - 1][j];
        if (adj[_j].size())
        {
            ans += abs(f[_j] - a[_j]);
            a[_j] = f[_j];
        }
    }
    for (int i = max_deep - 2 ; i >= 0 ; --i)
        for (int j = 0 ; j < adj_deep[i].size() ; ++j)
        {
            int _j = adj_deep[i][j];
            if (adj[_j].size())
            {
                for (int u = 0 ; u < adj[_j].size() ; ++u)
                    f[_j] += a[adj[_j][u]];
                ans += abs(f[_j] - a[_j]);
                a[_j] = f[_j];
            }
        }
    Ans = min(ans , Ans);

    cout << Ans;
}

main()
{
    fr();
    enter();
    solve();
    return 0;
}
