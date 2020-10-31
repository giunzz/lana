#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);
#define bit(S, i) (((S) >> i) & 1)
template<typename T> inline void read(T &x) {
    char c;
    bool neg = false;
    while (!isdigit(c = getchar()) && c != '-');
    x = 0;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    do {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
    if (neg) x = -x;
}
template<typename T> inline void write(T x) {
    if (x < 0) {
        putchar('-');
        write(-x);return;
    }
    if (x < 10) {
        putchar(char(x + 48));
    }
    else {
        write(x/10);
        putchar(char(48 + x%10));
    }
}
template<typename T> inline void writeln(T x) {
    write(x);
    putchar('\n');
}
using namespace std;
int n;
long long a[N];
queue<int> Thieu, Thua;

struct Edge {
    int u, v, cap, flow, cost;
};

struct MinCostFlow{
    vector<vector<int> > g;
    vector<Edge> e;
    vector<int> d, bef;
    int n, s, t;
    priority_queue<pp> heap;
    void reset(int n) {
        this -> n = n;
        bef.clear();
        g.clear();
        e.clear();
        d.clear();
        bef.resize(n + 1);
        g.resize(n + 1);
        d.resize(n + 1);
    }

    void addEdge(int u, int v, int cap, int cost) {
        Edge ee = {u, v, cap, 0, cost};
        g[u].push_back(e.size());
        e.push_back(ee);
        ee = {v, u, 0, 0, -cost};
        g[v].push_back(e.size());
        e.push_back(ee);
    }

    long long getMinCost(int s, int t) {
        this -> s = s;
        this -> t = t;
        long long Cost = 0;
        while (true) {
            while (!heap.empty()) heap.pop();
            FOR(i, 0, n) d[i] = 1e9;
            d[s] = 0;
            heap.push(pp(0, s));
            while (!heap.empty()) {
                int u = heap.top().second;
                int dist = -heap.top().first;
                heap.pop();
                if (d[u] != dist) continue;
                if (u == t) break;
                for (int id : g[u]) if (e[id].flow < e[id].cap){
                    int v = e[id].v;
                    int c = e[id].cost;
                    if (d[v] > d[u] + c) {
                        d[v] = d[u] + c;
                        bef[v] = id;
                        heap.push(pp(-d[v], v));
                    }
                }
            }
            if (d[t] == 1e9) return Cost;
            Cost += d[t];
            int v = t;
            while (v != s) {
                int id = bef[v];
                e[id].flow++;
                e[id^1].flow--;
                v = e[id].u;
            }
        }
    }
}MCF;
int main() {
    IO;
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    read(n);
    long long sum = 0;
    FOR(i, 1, n) {
        read(a[i]);
        sum += a[i];
    }
    long long need = sum / n;
    long long ans = 0;
    FOR(i, 1, n) {
        while (!Thieu.empty() && a[i] != 0) {
            int u = Thieu.front();
            long long tmp = min(need - a[u], a[i]);
            a[u] += tmp;
            a[i] -= tmp;
            ans += 1ll * tmp * (i - u);
            if (a[u] == need) Thieu.pop();
        }
        if (a[i] < need) {
            while (!Thua.empty() && a[i] != need) {
                int u = Thua.front();
                int tmp = min(need - a[i], a[u] - need);
                a[u] -= tmp;
                a[i] += tmp;
                ans += 1ll * tmp * (i - u);
                if (a[u] == need) Thua.pop();
            }
            if (a[i] < need) Thieu.push(i);
        }
        else {
            if (a[i] > need + 1) Thua.push(i);
        }
    }
    FOR(i, 1, n) a[i] -= need;
    MCF.reset(n + 2);
    FOR(i, 1, n) {
        if (a[i] > 1) MCF.addEdge(0, i, a[i] - 1, 0);
        MCF.addEdge(i, n + 1, 1, 0);
        if (i > 1) MCF.addEdge(i - 1, i, 1e9, 1);
        if (i < n) MCF.addEdge(i, i + 1, 1e9, 1);
    }
    ans += MCF.getMinCost(0, n + 1);
    writeln(ans);
}
