#include <bits/stdc++.h>
#define llint long long
#define fi first
#define se second
#define db(x) cout << #x << " = " << x << endl;
using namespace std;
inline void read(int &ret){
	register char c = getchar();
	bool neg = false;
	ret = 0;
	while (c < '0' || c > '9'){
		if (c == '-') neg = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		ret = (ret << 1) + (ret << 3) + c - '0';
		c = getchar();
	}
	if (neg) ret = -ret;
}

void write(int x){
	if (x < 0){
		putchar('-');
		x = -x;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

inline void read(llint &ret){
	register char c = getchar();
	bool neg = false;
	ret = 0;
	while (c < '0' || c > '9'){
		if (c == '-') neg = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		ret = (ret << 1) + (ret << 3) + c - '0';
		c = getchar();
	}
	if (neg) ret = -ret;
}

void write(llint x){
	if (x < 0){
		putchar('-');
		x = -x;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

void openFile() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
#ifdef Tr___
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);
#endif
}

const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
const llint inf = 1e9 + 7;

int N, S, T, D;
llint tot = 0, lower, upper;
int a[maxn];

void enter() {
    read(N);
    for (int i = 1; i <= N; ++i) {
        read(a[i]);
        tot = tot + a[i];
    }
}

struct edge {
    int u, v, f, c;
    edge() {}
    edge(int u, int v, int f, int c): u(u), v(v), f(f), c(c) {}
};
vector<edge> E;
vector<int> vertex[maxn];

void addEdge(int u, int v, int f, int c) {
    //cout << u << " " << v << " " << f << " " << c << endl;
    vertex[u].push_back(E.size());
    E.push_back(edge(u, v, f, c));
    vertex[v].push_back(E.size());
    E.push_back(edge(v, u, 0, -c));
}

#define fi first
#define se second

priority_queue<pair<llint, int>, vector<pair<llint, int> >, greater<pair<llint, int> > > q;
bool inQ[maxn];
int trace[maxn];
llint dst[maxn];
int flow[maxn];

llint minCost() {
    llint res = 0;
    for (;;) {
        while (!q.empty()) {
            q.pop();
        }
        for (int i = 0; i <= T; ++i) {
            dst[i] = inf * inf;
            flow[i] = 0;
        }
        
        flow[S] = inf;
        dst[S] = 0;
        q.push({0, S});
        while (!q.empty()) {
            llint du = q.top().fi;
            int u = q.top().se; 
            q.pop();
            if (du > dst[u]) continue;

            for (int id : vertex[u]) {
                int v = E[id].v;
                int c = E[id].c;

                if (E[id].f) {
                    if (dst[v] > dst[u] + c) {
                        dst[v] = dst[u] + c;
                        flow[v] = min(flow[u], E[id].f);
                        trace[v] = id;

                        q.push({dst[v], v});
                    }
                }
            }
        }

        if (!flow[T]) break;
        res = res + dst[T] * flow[T];
        int u = T;
        while (u != S) {
            int id = trace[u];
            E[id].f -= flow[T];
            E[id^1].f += flow[T];

            u = E[id].u;
        }
    }
    return res;
}

void solve() {
    D = N + 1, S = N + 2; T = N + 3;
    lower = tot / N;
    upper = tot / N + (tot % N ? 1 : 0);
    //cout << lower << " " << upper << endl;

    for (int i = 1; i <= N; ++i) {
        if (a[i] >= upper) {
            addEdge(S, i, a[i] - lower, 0);
            //addEdge(i, D, 1, 0);
        }
        else if (a[i] < lower) {
            //addEdge(S, i, 1, 0);
            addEdge(i, T, lower - a[i], 0);
            //cout << i << " T " << lower - a[i] + 1 << endl;
        }
        addEdge(i, D, 1, 0);
    }
    addEdge(D, T, tot % N, 0);
    for (int i = 1; i < N; ++i) {
        addEdge(i, i + 1, inf, 1);
        addEdge(i + 1, i, inf, 1);
    }

    write(minCost());
}

int main() {
    openFile();
    enter();
    solve();
    return 0;
}
