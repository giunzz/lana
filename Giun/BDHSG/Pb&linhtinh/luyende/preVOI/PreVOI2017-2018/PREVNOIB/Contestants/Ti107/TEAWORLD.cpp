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

#define NAME            "TEAWORLD"

using namespace std;
const int N = 2123;

int n, m, k, a[N], p[N], r[N], e[N], Hanh;
bool dap[N][N], d[N];

void Enter() {
    cin >> m >> n >> k;
    int cac1, cac2, cac3;
    ff(i, 1, m) {
        cin >> p[i] >> cac1  >> cac2>> r[i];
    }
    ff(i, 1,n) {
        cin >> a[i] >> cac1  >> cac2>> e[i];
    }

    cin >> Hanh >> cac1 >> cac2;
}

bool Inside(int x, int t, int r) {
    return x >= t-r && x <= t+r;
}

void Process() {
    ff(u, 1, n) {
        ff(k, 1, m) {
            if (Inside(a[u], p[k], r[k]) && Inside(Hanh, p[k], r[k])) continue;
            if (Inside(a[u], p[k], r[k]) || Inside(Hanh, p[k], r[k])) {
                dap[u][k] = true;
                continue;
            }
            int L = a[u], R = Hanh;
            if (L > R) swap(L, R);
            if (L <= p[k]-r[k] && p[k]+r[k] <= R) dap[u][k] = true;
        }
    }

    int res = 0;
    REP(t, 1<< n) {
        REP(i, m+1) d[i] = 0;
        int sum = 0, cnt = 0;
        REP(i, n)
            if (BIT(i, t)) sum += e[i+1];

        if (sum < res) continue;

        REP(i, n) {
            if (BIT(i, t))
                ff(z, 1, m)
                    if (dap[i+1][z] && !d[z]) {
                        d[z] = true;
                        ++cnt;
                    }

            if (cnt > k) break;
        }

        if (cnt <= k) res = max(res, sum);
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);
    Enter();
    Process();
    return 0;
}
