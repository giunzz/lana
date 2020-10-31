#include <bits/stdc++.h>
#define FOR(i, a, b)    for (int i = a; i <= b; ++i)
#define FOD(i, a, b)    for (int i = a; i >= b; --i)
#define LL              long long
using namespace std;
void cass() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
}
const int N = 2e6 + 3;
int n, k, a[N];
LL  sum[N], L[N], R[N], ans;

void read(int& val) {
    char c;
    do { c = getchar(); } while (! isdigit(c));
    int res = c - '0';
    while (isdigit(c = getchar())) res = 10 * res + c - '0';
    val = res;
}

bool check(LL val) {
    FOR(i, 1, n - k + 1)
        if (max(L[i], R[i + k - 1]) <= val) return true;
    return false;
}

void sol() {
    read(n); read(k);
    FOR(i, 1, n) read(a[i]), sum[i] = sum[i - 1] + a[i];

    FOR(i, k + 1, n - k + 1) L[i] = max(L[i - 1], sum[i - 1] - sum[i - k - 1]);
    FOD(i, n - k, k) R[i] = max(R[i + 1], sum[i + k] - sum[i]);
    //FOR(i, 1, n) cerr << L[i] << ' ' << R[i] << '\n';

    LL lo = 1, hi = 1e12;
    while (lo <= hi) {
        LL mid = lo + hi >> 1;
        if (check(mid)) ans = mid, hi = mid - 1;  else lo = mid + 1;
    }

    cout << ans;
}

int main() {
    cass(); sol();
}

