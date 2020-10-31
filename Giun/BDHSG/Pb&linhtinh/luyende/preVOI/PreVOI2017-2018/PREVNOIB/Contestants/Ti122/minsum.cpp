#include <bits/stdc++.h>
#define FOR(i, a, b)    for (int i = a; i <= b; ++i)
#define LL              long long
#define ii              pair <int, int>
#define x               first
#define y               second
using namespace std;
void cass() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
}
const int N1 = 3e3 + 3;
int T, n, A, B, vis[N1][N1];
queue <ii> Q;

void sub1() {
    memset(vis, 0, sizeof vis);
    int res = A + B, cs1 = A, cs2 = B;
    Q.push(ii(A, B)); vis[A][B] = 1;

    while (Q.size()) {
        int u = Q.front().x, v = Q.front().y;
        //cerr << u << ' ' << v << '\n';
        Q.pop();
        if (res > u + v) res = u + v, cs1 = u, cs2 = v;

        FOR(i, 2, min(u, v)) if (u % i == 0 && v % i == 0) {
            int nu = u / i, nv = v / i;
            if (! vis[nu][nv]) vis[nu][nv] = 1, Q.push(ii(nu, nv));
        }
        FOR(i, 2, u) if (u % i == 0) {
            int nu = u / i, nv = v * i;
            if (! vis[nu][nv]) vis[nu][nv] = 1, Q.push(ii(nu, nv));
        }
        FOR(j, 2, v) if (v % j == 0) {
            int nu = u * j, nv = v / j;
            if (! vis[nu][nv]) vis[nu][nv] = 1, Q.push(ii(nu, nv));
        }
    }

    cout << cs1 << ' ' << cs2 << '\n';
}

int Fact[1000007];
void sub2() {
    int ta = A, tb = B; int nta = 1, ntb = 1;
    while (ta > 1) {
        int dem = 0;
        int u = Fact[ta];
        while (ta % u == 0) ta /= u, dem = 1 - dem;
        nta *= ! dem ? 1 : u;
    }
    while (tb > 1) {
        int dem = 0;
        int u = Fact[tb];
        while (tb % u == 0) tb /= u, dem = 1 - dem;
        ntb *= ! dem ? 1 : u;
    }
    cout << nta << ' ' << ntb << '\n';
}

map <int, int> Map, D;
void full() {
    Map.clear(); D.clear(); int V[100];
    int ta = A, tb = B, nta = 1, ntb = 1;
    int dem = 0, stt = 0;
    while (ta > 1) {
        int u = Fact[ta];
        if (Map.count(u)) stt = Map[u]; else stt = ++dem, D[dem] = u;
        while (ta % u == 0) ta /= u, V[stt]++;
    }
    while (tb > 1) {
        int u = Fact[tb];
        if (Map.count(u)) stt = Map[u]; else stt = ++dem, D[dem] = u;
        while (tb % u == 0) tb /= u, V[stt]++;
    }
    FOR(i, 1, stt) nta *= (A % D[stt] == 0 && (V[stt] & 1)) ? D[stt] : 1, ntb *= (B % D[stt] == 0 && (V[stt] & 1)) ? D[stt] : 1;
    cout << nta << ' ' << ntb << '\n';
}

void sol() {
    int dm = 1e6;
    FOR(i, 2, dm)
        if (! Fact[i]) {
            Fact[i] = i;
            FOR(j, i, dm/i) if (! Fact[i * j]) Fact[i * j] = i;
        }
    cin >> T;
    while (T--) {
        cin >> A >> B;
        if (A <= 50 && B <= 50) sub1(); else full();
    }
}

int main() {
    cass(); sol();
}
