#include<bits/stdc++.h>
#define ioi         exit(0)
using namespace std;

void Read(int &val) {
    val = 0; char c;
    do { c = getchar(); } while (!isdigit(c));
    while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

typedef long long LL;
typedef pair<int, int> ii;

const int N = 1e6 + 4;
int n, k, a[N];
LL s[N];
ii b[N];

bool check(LL mid) {
    int len = 0;
    for (int i = k; i <= n; ++i) {
        LL val = s[i] - s[i-k];
        if (val >= mid) b[++len] = ii(i-k+1, i);
    }

    if (len == 0) return false;
    if (len == 1) return false;

    int L = b[1].second;
    for (int i = 1; i <= len; ++i) {
        int tmp = b[i].first - L + 1;
        if (tmp > k) return true;
    }

    return false;
}

void sol() {
    for (int i = 1; i <= n; ++i) s[i] = s[i-1] + 1LL * a[i];

    LL l = 1, r = s[n], res = 0;
    while (l <= r) {
        LL mid = (l + r) / 2;
        if (check(mid)) { l = mid + 1; res = mid; }
        else { r = mid - 1; }
    }

    cout << res;
}

int main() {
    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);

    Read(n); Read(k);
    for (int i = 1; i <= n; ++i) Read(a[i]);

        //cerr << n << " " << k << '\n';
        //for (int i = 1; i <= n; ++i) cerr << a[i] << ' ';

    sol();

    return 0;
}
