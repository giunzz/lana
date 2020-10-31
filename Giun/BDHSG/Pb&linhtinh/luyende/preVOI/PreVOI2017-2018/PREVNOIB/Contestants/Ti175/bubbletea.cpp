#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back

using namespace std;

const int N = 1e5;
const LL oo = 1e16;
int n,k,u,v,d[N],p[N][22],f[N], b[100];
LL dp[N],c,mi,ma,mem[N];
bool vis[N];
vector < int > a[N];
map < pair < int , int > , LL > Map;

void load() {
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
}


void dfs(int u, int pr) {
    //cout << u << " " << pr << endl;
    for (int i = 0 ; i < a[u].size() ; ++ i) {
        int v = a[u][i];

        if (v != pr) {
            d[v] = d[u] + 1;
            p[v][0] = u;
            for (int j = 1 ; j < 20 ; ++ j)
                p[v][j] = p[p[v][j-1]][j-1];

            dp[v] = dp[u] + Map[mp(u,v)];
            dfs(v,u);
        }
    }

    return ;
}

int lca(int u, int v) {

    if (d[u] < d[v])
        swap(u,v);

    int tmp = d[u] - d[v];

    for (int i = 0 ; i <= 19 ; ++ i)
        if (tmp & (1 << i))
            u = p[u][i];

    if (u == v) return u;

    for (int i = 19 ; i >= 0 ; -- i)
        if (p[u][i] != p[v][i])
        u = p[u][i], v = p[v][i];

    return p[u][0];
}

void duyet(int u, int p) {

    int cnt = 0;
    for (int i = 0 ; i < a[u].size() ; ++ i) {
        int v = a[u][i];

        if (v != p) {
            duyet(v,u);
            if (!vis[u]) {
                   mem[++cnt] = Map[mp(u,v)];
            }
    }}

    if (cnt > 0) {
        sort(mem+1,mem+1+cnt);

            for (int i = 1 ; i <= cnt / 2 ; ++ i)
                ma = max(ma,mem[i] + mem[cnt- i + 1]);

            if (cnt % 2) {
                ma = max(ma,mem[cnt/2 + 1]);
                vis[u] = 1;
            }

    }
}

void process() {

    cin >> n >> k;
    for (int i = 1 ; i <= k ; ++ i)
        cin >> f[i];

    for (int i = 1 ; i < n ; ++ i) {
        cin >> u >> v >> c;
        a[u].pb(v);
        a[v].pb(u);
        Map[mp(u,v)] = Map[mp(v,u)] = c;
    }

    dfs(1,0);
    if (n <= 10) {

        for (int i = 1 ; i <= k ; ++ i)
            b[i] = i;
        LL ans = oo;


        do {
           ma = 0;
            for (int i = 1 ; i <= k ; i = i + 2) {

                ma = max(ma,dp[f[b[i]]] + dp[f[b[i+1]]] - 2 * dp[lca(f[b[i]],f[b[i+1]])]);
            }

            ans = min(ans,ma);

        } while (next_permutation(b+1,b+1+k));

        cout << ans << endl;
        return ;
    }


         mi = oo;
           ma = 0;
        duyet(1,0);
        cout << ma << endl;

}

int main() {
    load();
    process();
    return 0;
}
