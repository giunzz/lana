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
    freopen("bubbletea.inp", "r", stdin);
    freopen("bubbletea.out", "w", stdout);
#endif
}

const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
const llint inf = 1e9 + 7;

int N, K;
vector<pair<int, int> > vertex[maxn];
bool cross[maxn];

void enter() {
    read(N); read(K);
    for (int i = 1; i <= K; ++i) {
        int x;
        read(x);
        cross[x] = true;
    }
    for (int i = 1; i <= N - 1; ++i) {
        int u, v, w;
        read(u); read(v); read(w);
        vertex[u].push_back({v, w});
        vertex[v].push_back({u, w});
    }
}

llint MAX;
bool found;
llint dfs(int u, int p) {
    if (!found) return -1;
    vector<llint> all;
    vector<bool> del;
    if (cross[u]) {
        all.push_back(0);
        del.push_back(false);
    }
    for (int i = 0; i < vertex[u].size(); ++i) {
        int v = vertex[u][i].first;
        int w = vertex[u][i].second;
        if (v != p) {
            llint d = dfs(v, u);
            if (!found) return -1;
            if (d == -1) continue;

            all.push_back(d + w);
            del.push_back(false);
        }
    }
    sort(all.begin(), all.end());
    if (all.size() <= 1) return all.size() > 0 ? all[0] : -1;
    //cout << "u = " << u << endl;
    //for (int i = 0; i < all.size(); ++i) {
    //    cout << all[i] << " ";
    //}
    //cout << endl;

    int sz = all.size();

    int i = sz - 1;
    int j = i;

    while (i >= 0) {
        if (i >= j || del[i] || all[i] + all[j] > MAX) {
            --i;
        }
        else if (del[j]) {
            --j;
        }
        else {
            del[i] = del[j] = true;
        }
    }

    llint res = inf * inf;
    llint cur = -1;
    int sl = 0;
    for (int i = 0; i < all.size(); ++i) {
        if (!del[i]) {
            ++sl;
            cur = all[i];
        }
    }
    if (sl <= 1) {
        res = min(res, cur);
    }

    for (int i = 0; i < sz; ++i) {
        del[i] = false;
    }

    del[sz - 1] = true;
    i = sz - 2;
    j = i;
    while (i >= 0) {
        if (i >= j || del[i] || all[i] + all[j] > MAX) {
            --i;
        }
        else if (del[j]) {
            --j;
        }
        else {
            del[i] = del[j] = true;
        }
    }

    cur = all[sz - 1];
    sl = 0;
    for (int i = 0; i < sz; ++i) {
        if (!del[i]) {
            ++sl;
        }
    }
    if (sl == 0) {
        res = min(res, cur);
    }
    if (res == inf * inf) {
        res = -1;
        found = false;
    }

    return res;
}

bool check(llint h) {
    MAX = h;
    found = true;
    dfs(1, 0);
    return found;
}

void solve() {
    llint lo = 1, hi = inf * inf, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    write(lo);
}

int main() {
    openFile();
    enter();
    solve();
    return 0;
}
