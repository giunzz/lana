#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 5 * 1e3 + 100, oo = 1e9;
int d[N],dp[N][N],n,u,v,val[N];
vector < int > a[N];

void load() {
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
}


void dfs(int u) {

    if (a[u].size() == 0) {
        d[u] = 1;
        return;
    }

    for (int i = 0 ; i < a[u].size() ; ++ i) {
        int v = a[u][i];
        dfs(v);
        d[u] += d[v];
    }

    return ;
}

void solve(int u) {

    if (a[u].size() == 0) {
        dp[u][0] = val[u];
        dp[u][1] = abs(val[u] - 1);

        return ;
    }

    for (int i = 0 ; i < a[u].size() ; ++ i) {
        int v = a[u][i];
        solve(v);
    }

    for (int i = 0 ; i <= d[u] ; ++ i) {


        if (a[u].size() == 1)
            dp[u][i] = min(dp[u][i],dp[a[u][0]][i]);
        if (a[u].size() == 2) {
            int v1 = a[u][0], v2 = a[u][1];

            for (int j = 0 ; j <= min(d[v1],i) ; ++ j)
                dp[u][i] = min(dp[u][i],dp[v1][j] + dp[v2][i - j]);
        }

        dp[u][i] += abs(val[u] - i);
    }

    return ;
}

void process() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> val[i];

    for (int i = 1 ; i < n; ++ i) {
        cin >> u >> v;
        a[u].pb(v);
    }


    dfs(1);

    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 0 ; j <= 4000 ; ++ j)
            dp[i][j] = oo;

    solve(1);

    int ans = oo;
    for (int i = 0 ; i <= d[1] ; ++ i)
        ans = min(ans,dp[1][i]);

    cout << ans;

}

int main() {
    load();
    process();
    return 0;
}
