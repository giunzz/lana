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
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
#endif
}

const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
const llint inf = 1e9 + 7;

int N;
int A, B;
int da[maxn], db[maxn];
vector<int> rem;
int d[maxn], all[maxn], sz = 0;
llint tot, ra, rb;

void enter() {
    read(A); read(B);
}

void backtrack(int i, llint a, llint b) {
    if (i == rem.size()) {
        if (tot > a + b) {
            tot = a + b;
            ra = a;
            rb = b;
        }
        return;
    }
    backtrack(i + 1, a * rem[i], b);
    backtrack(i + 1, a, b * rem[i]);
}

void eratos() {
    int _inf = trunc(sqrt(inf));
    for (int i = 2; i <= trunc(sqrt(_inf)); ++i) {
        for (int j = 2; j <= _inf / i; ++j) {
            d[i * j] = i;
        }
    }
    for (int i = 2; i <= _inf; ++i) {
        if (d[i] == 0) {
            all[++sz] = i;
            //cout << i << endl;
        }
    }
}

void solve() {
    tot = inf * inf;
    ra = rb = 0;
    rem.clear();

    int gcd = __gcd(A, B);
    A /= gcd;
    B /= gcd;
    for (int i = sz; i >= 1; --i) {
        //cout << all[i] << flush << endl;
        int sa = 0;
        int sb = 0;
        while (A % all[i] == 0) {
            A /= all[i];
            ++sa;
        }
        while (B % all[i] == 0) {
            B /= all[i];
            ++sb;
        }

        if (abs(sa - sb) % 2 == 1) {
            rem.push_back(all[i]);
        }
    }

    if (A != 1) {
        rem.push_back(A);
    }

    if (B != 1) {
        rem.push_back(B);
    }

    //sort(rem.begin(), rem.end());
    backtrack(0, 1, 1);

    write(ra); putchar(' '); write(rb);
    puts("");
}

int main() {
    openFile();
    int T;
    read(T);
    eratos();
    for (int i = 1; i <= T; ++i) {
        enter();
        solve();
    }
    return 0;
}
