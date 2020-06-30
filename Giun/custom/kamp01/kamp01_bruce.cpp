#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 5e5 + 7;

int n, m;
ll ans = 0;
vector < ii > g[N];
int parent[N], a[N], color[N];
int cost[N];

void BFS(int source) {
    memset(parent, 0, sizeof(parent));
    queue < int > q;
    q.push(source);
    parent[source] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, g[u].size()) {
            int v = g[u][i].fi;
            int w = g[u][i].se;
            if (!parent[v]) {
                q.push(v);
                parent[v] = u;
                cost[v] = w;
            }
        }
    }
}

int main() {
    fileInput("kamp01");
    fast;
    cin >> n >> m;
    FOR(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb(ii(v, w));
        g[v].pb(ii(u, w));
    }
    FOR(i, 1, m) {
        cin >> a[i];
    }

    memset(color, 0, sizeof(color));
    BFS(a[1]);
    color[a[1]] = 1;
    FOR(sink, 2, m) {
        int v = a[sink];
        while (!color[v] and v != a[1]) {
            ans += cost[v];
            color[v] = 1;
            v = parent[v];
        }
    }
    cout << ans << endl;

    return (0);
}