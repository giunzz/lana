#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

#define MAX   100100
const long long INF = (long long)1e14 + 7LL;

vector<pair<int, long long> > adj[MAX];
int par[MAX], numNode[MAX], n;
long long high[MAX], f[MAX];
bool imp[MAX];
void loadTree(void) {
    int m; scanf("%d%d", &n, &m);
    REP(love, m) {
        int x; scanf("%d", &x);
        imp[x] = true;
    }
    REP(love, n - 1) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
}
void preDFS(int u) {
    if (imp[u]) numNode[u] = 1;
    FORE(it, adj[u]) if (it->fi != par[u]) {
        int v = it->fi;
        par[v] = u;
        high[v] = high[u] + it->se;
        preDFS(v);
        numNode[u] += numNode[v];
    }
}
bool calcDFS(int u, long long lim) {
    multiset<long long, greater<long long> > child;
    FORE(it, adj[u]) if (it->fi != par[u]) {
        int v = it->fi;
        if (!calcDFS(v, lim)) return false;
        if (numNode[v] % 2 != 0) child.insert(it->se + f[v]);
    }
    if (imp[u]) child.insert(0);
    if (child.empty()) return true;
    int canRemove = child.size() % 2;
    f[u] = -1;
    while (!child.empty()) {
        long long cur = *child.begin(); child.erase(child.begin());
        __typeof(child.begin()) it = child.lower_bound(lim - cur);
        if (it == child.end()) {
            if (canRemove == 0) return false;
            canRemove--;
            f[u] = cur;
        } else child.erase(it);
    }
    return (true);
}
long long process(void) {
    long long L = 0;
    long long R = INF;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return calcDFS(1, L) ? L : R;
        long long M = (L + R) >> 1;
        if (calcDFS(1, M)) R = M; else L = M + 1;
    }
}
int main(void) {
//#ifdef THEMIS
    freopen("bubbletea.inp", "r", stdin);
    freopen("bubbletea.out", "w", stdout);
//#endif // THEMIS
    loadTree();
    preDFS(1);
    cout << process() << endl;
    return 0;
}
