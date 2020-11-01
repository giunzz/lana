#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<= b; ++i)
#define FORD(i, a, b) for (int i = a; i>=b; --i)
#define REP(i, a) for (int i = 0; i<a; ++i)
#define N 50505
#define pp pair<int, int>
#define bit(S, i) (((S) >> i) & 1)
#define IO cin.tie(NULL);cout.tie(NULL);
#define taskname "BUBBLETEA"
using namespace std;
int n, k,a[N];
vector<pp> e[N];
struct SUB1 {
    long long ans = 1e18;
    vector<int> used[N];
    set<pp> tmp;
    long long f[N];
    bool dfs(int u, int p, int finish) {
        if(u == finish) return true;
        for (pp tt : e[u]) if (tt.first != p) {
            int v = tt.first;
            int c = tt.second;
            if (tmp.find(pp(min(u, v), max(u, v))) != tmp.end()) continue;
            tmp.insert(pp(min(u, v), max(u, v)));
            f[v] = f[u] + c;
            if(!dfs(v, u, finish)) tmp.erase(pp(min(u, v), max(u, v)));
        }
        return false;
    }
    long long check() {
        tmp.clear();
        long long ret = 0;
        FOR(i, 1, k / 2) {
            FOR(j, 1, n) f[j] = 0;
            dfs(used[i][0], -1, used[i][1]);
            if(f[used[i][1]]) {
                ret = max(ret, f[used[i][1]]);
            } else return 1e18 + 5;
        }
        return ret;
    }
    void TRY(int u) {
        if (u == k){
            ans = min(ans, check());
            return;
        }
        FOR(i, 1, k / 2) if (used[i].size() < 2) {
            used[i].push_back(a[u + 1]);
            TRY(u + 1);
            used[i].pop_back();
        }
    }
    void Run() {
        TRY(0);
        printf("%lld", ans);
    }
}Sub1;

struct SUB2 {
    struct HopcroftKarp {
        vector<int> d, match;
        queue<int> q;
        vector<vector<int> > e;
        int n;
        const int NIL = 0;
        const int inf = 1e9;
        void reset(int n) {
            this -> n = n;
            d.clear();
            match.clear();
            d.resize(n * 2 + 1);
            match.resize(n * 2 + 1);
            e.clear();
            e.resize(n * 2 + 1);
        }

        void addEdge(int u, int v) {
            e[u].push_back(v);
        }
        int getMaxMatching() {
            int matching = 0;
            while(bfs()) {
                FOR(i, 1, n) if(match[i] == NIL && dfs(i)) {
                    matching++;
                }
            }
            return matching;
        }
private:
        bool bfs() {
            FOR(i, 1, n) {
                if (match[i] == NIL) {
                    d[i] = 0;
                    q.push(i);
                } else d[i]=inf;
            }
            d[NIL] = inf;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v: e[u]) {
                    if (d[match[v]] == inf) {
                        d[match[v]] = d[u] + 1;
                        q.push(match[v]);
                    }
                }
            }
            return d[NIL] != inf;
        }
        bool dfs(int u) {
            if (u != NIL) {
                for (int v : e[u]) {
                    if (d[match[v]] == d[u] + 1) {
                        if (dfs(match[v])){
                            match[u] = v;
                            match[v] = u;
                            return true;
                        }
                    }
                }
                d[u] = inf;
                return false;
            }
            return true;
        }
    }HK;
    int p[N];
    void dfs(int u) {
        for (pp tt : e[u]) if (tt.first != p[u]) {
            int v = tt.first;
            p[v] = u;
            dfs(v);
        }
    }
    void Run() {
        p[1]= -1;
        dfs(1);
        int l = 1;
        int r = 1e9;
        int cur = -1;
        while (l <= r) {
            int m = (l + r) >> 1;
            HK.reset(n);
            FOR(u, 1, n){
                for (pp tt : e[u]) {
                    int v = tt.first;
                    int c = tt.second;
                    if (p[v] == u&& c<= m) {
                        HK.addEdge(u, v + n);
                    }
                }
            }
            if(HK.getMaxMatching() == n / 2) {
                cur = m;
                r = m - 1;
            }else l = m + 1;
        }
        printf("%d", cur);
    }
}Sub2;
int main() {
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    IO;
    scanf("%d %d", &n, &k);
    FOR(i, 1, k) {
        scanf("%d", &a[i]);
    }

    int u, v, c;
    FOR(i, 2, n) {
        scanf("%d %d %d", &u, &v, &c);
        e[u].push_back(pp(v, c));
        e[v].push_back(pp(u, c));
    }
    if (k <= 10) Sub2.Run();
    else {
        if(k == n) Sub2.Run();
       // else Sub3.Run();
    }
}
