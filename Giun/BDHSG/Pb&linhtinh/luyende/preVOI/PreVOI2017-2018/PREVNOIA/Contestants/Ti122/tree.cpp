#include <bits/stdc++.h>
#define FOR(i, a, b)    for (int i = a; i <= (int)(b); ++i)
#define LL              long long
using namespace std;
void cass() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
}
const int N = 5000 + 3;
const LL  inf = 1e12;
int n, val[N], numC[N];
LL  F[N][N], res = inf;
vector <int> a[N], son[N];

void dfs(int u, int dad) {
    FOR(i, 0, a[u].size() - 1) {
        int v = a[u][i];
        if (v == dad) continue;
        son[u].push_back(v);
        dfs(v, u);
        numC[u] += numC[v] + 1;
    }

    if (son[u].size() == 0) { FOR(i, 0, 1) F[u][i] = abs(val[u] - i); return; }

    if (son[u].size() == 1) {
        int v = son[u][0];
        if (numC[v] == 0)
            FOR(i, 0, 1) F[u][i] = min(F[u][i], F[v][i] + abs(val[u] - i));
        else
            FOR(i, 0, numC[v]) F[u][i] = min(F[u][i], F[v][i] + abs(val[u] - i));
        return;
    }

    if (son[u].size() == 2) {
        int v1 = son[u][0], v2 = son[u][1];
        if (numC[v1] < numC[v2]) swap(v1, v2);

        if (numC[v1] == 0) {
            FOR(i, 0, 2)
                FOR(j, 0, min(1, i))
                    F[u][i] = min(F[u][i], F[v1][j] + F[v2][i - j] + abs(val[u] - i));
        }
        else {
            if (numC[v2] == 0) {
                FOR(i, 0, numC[u]) FOR(j, 0, 1) if (i >= j)
                    F[u][i] = min(F[u][i], F[v1][i - j] + F[v2][j] + abs(val[u] - i));
            }
            else {
                FOR(i, 0, numC[u]) FOR(j, 0, numC[v1]) if (i >= j)
                    F[u][i] = min(F[u][i], F[v1][j] + F[v2][i - j] + abs(val[u] - i));
            }
        }
    }
}

void sol() {
    cin >> n;
    FOR(i, 1, n) cin >> val[i];
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v), a[v].push_back(u);
    }

    FOR(i, 1, n) FOR(j, 0, n) F[i][j] = inf;
    dfs(1, -1);
    FOR(i, 0, n) res = min(res, F[1][i]);
    cout << res;
}

int main() {
    cass(); sol();
}
