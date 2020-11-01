// MR.J
#include<bits/stdc++.h>
#define maxn 5005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "tree"
using namespace std;
int n, p[maxn], luu[maxn], dem, prv[maxn], node[maxn], dd[maxn];
vector <int > g[maxn];
ll ans = 100000000000000ll;

void setup() {
    cin >> n;
    rep(i, 1, n) cin >> p[i];
    rep(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
}

void DFS(int u) {
    dd[u] = 1;
    bool ok = 0;
    for(int &v : g[u]) {
        if(dd[v]) continue;
        ok = 1;
        prv[v] = u;
        DFS(v);
    }
    if(!ok) luu[++dem] = u;
}

int getbit(int x, int i) {
    return (x >> i) & 1;
}

void handling(int state) {
    rep(i, 1, dem) {
        node[luu[i]] = getbit(state, i-1);
    }
    rep(i, 1, dem) {
        int v = luu[i];
        int u = prv[v];
        while(u) {
            node[u] += node[v];
            u = prv[u];
        }
    }
    ll sum = 0;
    rep(i, 1, n) sum += abs(node[i] - p[i]);
    ans = min(ans, sum);
}

void calc() {
    int state = (1 << dem) - 1;
    rep(i, 0, state) {
        rep(i, 1, n) node[i] = 0;
        handling(i);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    calc();
    return 0;
}
