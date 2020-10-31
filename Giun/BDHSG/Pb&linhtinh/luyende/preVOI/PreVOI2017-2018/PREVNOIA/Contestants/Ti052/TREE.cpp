#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e3 + 7;
//const int Inf = 1e9 + 7;
int n, m, tmp, res, i, j, Inf;
int a[N], dp[N][N], dad[N], limit[N];
vector<int> son[N];

void Enter()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i < n; i ++)
    {
        int x, y;
        cin >> x >> y;
        son[x].push_back(y); dad[y] = x;
    }
}
void dfs(int u)
{
    if(son[u].size() == 0) {limit[u] = 1; return;}
    if(son[u].size() == 1)
    {
        dfs(son[u][0]); limit[u] = limit[son[u][0]];
        return;
    }
    dfs(son[u][0]); dfs(son[u][1]);
    limit[u] = limit[son[u][0]] + limit[son[u][1]];
}
void Init()
{
    memset(dp, 0x3f, sizeof(dp));
    Inf = dp[0][1];
    dfs(1);
}
void sol(int u, int gt)
{
    if(dp[u][gt] != Inf) return;
    if(son[u].size() == 0)
    {
        dp[u][gt] = abs(a[u] - gt);
//        cout << u << "  " << gt << "  " << abs(a[u] - gt) << "\n";
        return;
    }
    if(son[u].size() == 1)
    {
        sol(son[u][0], gt);
        dp[u][gt] = abs(a[u] - gt + dp[son[u][0]][gt]);
        return ;
    }
    int so = son[u][0], so2 = son[u][1], kq = Inf;
    for(int i = 0, _b = min(limit[so], gt); i <= _b; ++ i)
        if(gt - i <= limit[so2])
    {
        sol(so, i); sol(so2, gt - i);
        kq = min(kq, dp[so][i] + dp[so2][gt - i]);
    }
    else break;
    dp[u][gt] = kq + abs(a[u] - gt);
//    cout << u << "  " << gt << "  " << kq << "\n";
}
void Solve()
{
    if(n == 1)
    {
        cout << "0\n";
        return ;
    }
    res = Inf;
    if(son[1].size() == 1)
    {
        int so = son[1][0];
        for(int i = 0; i <= limit[1]; ++ i)
        {
            sol(so, i);
            dp[1][i] = dp[so][i] + abs(a[1] - i);
            res = min(res, dp[1][i]);
        }
        cout << res << "\n";
        return ;
    }
    int so = son[1][0], so2 = son[1][1], kq = Inf;
    for(int i = 0 ; i <= limit[1]; ++ i)
    {
        for(int j = 0, _b = min(limit[so], i); j <= _b; ++ j)
            if(i - j <= limit[so2])
        {
            sol(so, j); sol(so2, i - j);
//            cout << "op  " << j << "  " << i - j << "\n";
            kq = min(kq, dp[so][j] + dp[so2][i - j]);
        }
        else break;
        dp[1][i] = kq + abs(a[1] - i);
//        cout << i << "  " << kq << "\n";
        res = min(res, dp[1][i]);
    }
    cout << res << "\n";
//    for(int i = 1; i <= n; i ++) cout << limit[i] << " "; cout << "\n";
}

int main()
{
//#define file "r"
#define file "TREE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Enter();
    Init();
    Solve();
//    cout << Inf << "\n";
    return 0;
}
