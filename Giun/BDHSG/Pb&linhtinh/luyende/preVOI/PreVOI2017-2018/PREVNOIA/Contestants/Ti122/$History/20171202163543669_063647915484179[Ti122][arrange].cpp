#include <bits/stdc++.h>
#define FOR(i, a, b)    for (int i = a; i <= (int)(b); ++i)
#define LL              long long
using namespace std;
void cass() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
}
const int N = 1e5 + 3;
int n, a[N];
LL  sum, F[N][2], du[N][2];

void sub1() {
    LL hieu = 0, res = 0; int k = sum/n;
    FOR(i, 1, n) {
        hieu += a[i] - k;
        res += abs(hieu);
    }
    cout << res;
}

void greedy() {

}

void sol() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i], sum += a[i];
    if (sum % n == 0) sub1(); else greedy();
}

int main() {
    cass(); sol();
}
