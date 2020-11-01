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
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);
#endif
}

const int maxn = 2e6 + 5;
const int maxm = 1e6 + 5;
const llint inf = 1e9 + 7;

int N, K;
int a[maxn];
llint sl[maxn], sr[maxn];

void enter() {
    read(N); read(K);
    for (int i = 1; i <= N; ++i) {
        read(a[i]);
    }
}

void solve() {
    llint tot = 0;
    for (int i = 1; i <= N; ++i) {
        tot = tot + a[i];
        if (i > K) tot = tot - a[i - K];
        sl[i] = max(sl[i - 1], tot);
    }
    tot = 0;
    for (int i = N; i >= 1; --i) {
        tot = tot + a[i];
        if (N - i + 1 > K) tot = tot - a[i + K];
        sr[i] = max(sr[i + 1], tot);
    }

    llint res = inf * inf;
    for (int i = 1; i <= N; ++i) {
        //try to pick i -> i + K - 1
        res = min(res, max(sl[i - 1], sr[i + K]));
    }

    write(res);
}

int main() {
    openFile();
    enter();
    solve();
    return 0;
}
