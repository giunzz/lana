#include<bits/stdc++.h>
#define ioi     exit(0)
using namespace std;

void Read(int &val) {
    val = 0; char c;
    do { c = getchar(); } while (!isdigit(c));
    while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

typedef long long LL;
typedef pair<LL, int> ii;

const int N = 1e5 + 4;
int n, len;
LL a[N], sum = 0, remain = 0, res = 0;
ii lis[N];

void speSol(LL val) {
    for (int i = 1; i <= n; ++i) {
        if (a[i] > val) { lis[++len] = ii(a[i] - val, i); a[i] = val; }
    }

    int pos = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == val || pos > len) continue;
        while (a[i] < val) {
            LL tmp = min(lis[pos].first, val - a[i]);
            a[i] += tmp;
            lis[pos].first -= tmp;
            res += tmp * 1LL * abs(lis[pos].second - i);

            if (lis[pos].first == 0) pos++;
        }
    }

    cout << res;
}

void norSol(LL val) {
    for (int i = 1; i <= n; ++i) {
        if (a[i] > val+1) { lis[++len] = ii(a[i] - val, i); a[i] = val; }
    }

    int pos = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == val || pos > len) continue;
        while (a[i] < val) {
            LL tmp = min(lis[pos].first, val - a[i]);
            a[i] += tmp;
            lis[pos].first -= tmp;
            res += tmp * 1LL * abs(lis[pos].second - i);

            if (lis[pos].first == 0) pos++;
        }
    }

    for (int i = 1; i <= n; ++i) res += lis[pos].first;

    cout << res;
}

void sol() {
    for (int i = 1; i <= n; ++i) sum += 1LL * a[i];

    if (sum % n == 0) speSol(sum/(LL)n); else norSol(sum/(LL) n);
}

int main() {
    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);

    Read(n);
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
        Read(tmp);
        a[i] = 1LL * tmp;
    }

    sol();

    return 0;
}
