/*input
4
4 3 2 4
8
2 2 2 2 1 9 1 2
4
4 2 3 4
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 100005
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
    for (int i = 0; i < x.size(); i++) os << x[i] << sp;
    return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
    cout << x.fi << sp << x.se << sp;
    return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
    for (int i = 0; i < x.size(); i++) os << x[i] << endl;
    return os;
}

int n;
vector<int> a;
int sum = 0;
int lo, hi;

const int INF = 1e18;
const int INF2 = 1e12;
class MinCostMaxFlow {
private:
    struct data {
        int u, v, cap, f, cost;
        data (int _u = 0, int _v = 0, int _cap = 0, int _f = 0, int _cost = 0): u(_u), v(_v), cap(_cap), f(_f), cost(_cost) {};
        int other(data x, int u) {
            if (x.u == u) return x.v;
            return x.u;
        }
    } E;
    vector<data> e;
    vector<vector<int> > a;
    int dis[N], par[N];
    bool inqueue[N];
    queue<int> q;
    int S, T;
    bool BellmanFord() {
        while (!q.empty()) q.pop();
        memset(par, 0, sizeof(par)); memset(inqueue, 0, sizeof(inqueue)); memset(dis, 127, sizeof(dis));
        par[S] = INF; dis[S] = 0; inqueue[S] = true;
        q.push(S);
        while (!q.empty()) {
            int u = q.front(); q.pop(); inqueue[u] = false;
            for (int i = 0; i < a[u].size(); i++) {
                data t = e[a[u][i]];
                int v = E.other(t, u);
                if (t.f < t.cap && dis[v] > dis[u] + t.cost) {
                    dis[v] = dis[u] + t.cost;
                    par[v] = a[u][i];
                    if (!inqueue[v]) {
                        inqueue[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        return par[T] != 0;
    }
    void dfs() {
        int delta = INF;
        int u = T;
        while (1) {
            delta = min(delta, e[par[u]].cap - e[par[u]].f);
            u = E.other(e[par[u]], u);
            if (u == S) break;
        }
        u = T;
        while (1) {
            e[par[u]].f += delta;
            e[par[u] ^ 1].f -= delta;
            u = E.other(e[par[u]], u);
            if (u == S) break;
        }
    }
public:
    void init(int _S, int _T) {
        S = _S; T = _T;
        a.assign(N, vector<int>());
    }
    void addEdge(int u, int v, int cap, int cost) {
        e.push_back(data(u, v, cap, 0, cost));
        e.push_back(data(v, u, 0, 0, -cost));
        a[u].push_back(e.size() - 2);
        a[v].push_back(e.size() - 1);
    }
    int solve() {
        int ret = 0;
        while (BellmanFord()) {
            dfs();
        }
        for (int i = 0; i < e.size(); i++) if (e[i].f > 0) ret += e[i].f * e[i].cost;
        return ret;
    }
} MCMF;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        a.push_back(t);
        sum += t;
    }
    int numhi = 0;
    if (sum % n != 0) {
        lo = sum / n; hi = lo + 1;
        numhi = sum - lo * n;
    }
    else lo = hi = sum / n;
    int S = n, T = n + 1;
    MCMF.init(S, T);
    for (int i = 0; i < n; i++) {
        MCMF.addEdge(S, i, a[i], 0);
        if (lo != hi) {
            MCMF.addEdge(i, T, lo, 0);
            MCMF.addEdge(i, T, 1, INF2);
        }
        else
            MCMF.addEdge(i, T, lo, 0);
        if (i)
            MCMF.addEdge(i, i - 1, 1e11, 1);
        if (i != n - 1)
            MCMF.addEdge(i, i + 1, 1e11, 1);
    }
    cout << MCMF.solve() - numhi*INF2 << endl;
}