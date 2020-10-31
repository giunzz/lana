#include <bits/stdc++.h>

#define ff(i,a,b)       for(int i=(a), _b=(b); i<=_b; ++i)
#define gg(i,a,b)       for(int i=(a), _b=(b); i>=_b; --i)
#define REP(i,b)        for(int i=(0), _b=(b); i< _b; ++i)
#define endl            '\n'
#define long            long long
#define SX(a)           ((int)(a).size())
#define Love(a)         {cerr << #a << " = " << a << endl;}
#define _               << "," <<
#define BIT(i, x)       (((x)>>(i))&1)
#define X               first
#define Y               second

#define NAME            "GIFTS"

using namespace std;
const int N = 1e6 + 8;

int n, a[N], k;
long s[N], L[N], R[N];

inline void read(int &i) {
	i = 0;
	char c = 0;
	bool flag = false;
	for(; (c < '0' || c > '9') && c != '-'; c = getchar());
	while (c == '-') {
		flag = true;
		c = getchar();
	}
	for (; c >= '0' && c <= '9'; c = getchar()) i = 10 * i + c - '0';
	if (flag) i = -i;
}

inline void write(int n) {
	if (n < 0) {
		putchar('-');
		write(-n);
	}
	else if (n < 10) putchar(n + '0');
	else {
		write(n / 10);
		putchar(n % 10 + '0');
	}
}

inline void writeln(int n) {
	write(n);
	putchar('\n');
}

void Enter() {
    read(n);
    read(k);
    ff(i, 1, n) {
        read(a[i]);
        s[i] = s[i-1] + a[i];
    }
}

long get(int l, int r) {
    return s[r] - s[l-1];
}

void Process() {
    gg(i, n-k+1, 1) {
        long cost = get(i, i+k-1);
        R[i] = max(R[i+1], cost);
    }

    ff(i, k, n) {
        long cost = get(i-k+1, i);
        L[i] = max(L[i-1], cost);
    }

    long res = (long)1e18;
    ff(i, k, n) {
        long Tam = max(L[i-k], R[i+1]);
        res = min(Tam, res);
    }

    cout << res << endl;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);
    Enter();
    Process();
    return 0;
}
