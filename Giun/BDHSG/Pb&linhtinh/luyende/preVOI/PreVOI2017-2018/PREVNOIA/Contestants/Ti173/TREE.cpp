#include<bits/stdc++.h>
using namespace std;

const int N = 304, VAL = 5004, oo = 1e9;
int n, val[N];
vector<int> a[N];
int ver[4];
int F[N][VAL], Min[N], Max[N];

void DFS(int par, int u) {
    //int len = 0;
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (v == par) continue;
        DFS(u, v);
        //ver[++len] = v;
    }

    if (a[u].size() == 1 && u != 1) { F[u][val[u]] = 0; F[u][1-val[u]] = 1; Min[u] = 0; Max[u] = 1; }
    else if ((a[u].size() == 2 && u != 1) || (u == 1 && a[u].size() == 1)) {
        for (int i = 0; i < a[u].size(); ++i) {
            int v = a[u][i];
            if (v == par) continue;
            for (int w = Min[v]; w <= Max[v]; ++w)
                if (F[v][w] != oo) {
                    F[u][w] = min(F[u][w], abs(val[u] - w) + F[v][w]);
                    Min[u] = min(Min[u], w);
                    Max[u] = max(Max[u], w);
                }
        }
    }
    else if ((u != 1 && a[u].size() == 3) || (u == 1 && a[u].size() == 2)) {
        int len = 0;
        for (int i = 0; i < a[u].size(); ++i) {
            int v = a[u][i];
            if (v == par) continue;
            ver[++len] = v;
        }

        for (int w1 = Min[ver[1]]; w1 <= Max[ver[1]]; ++w1) if (F[ver[1]][w1] != oo) {
            for (int w2 = Min[ver[2]]; w2 <= Max[ver[2]]; ++w2) if (F[ver[2]][w2] != oo && w1 + w2 <= 5000) {
                F[u][w1+w2] = min(F[u][w1+w2], F[ver[1]][w1] + F[ver[2]][w2] + abs(w1 + w2 - val[u]));
                Min[u] = min(Min[u], w1 + w2);
                Max[u] = max(Max[u], w1 + w2);
            }
        }
    }
}

void sol() {
    for (int i = 1; i <= n; ++i) for (int w = 0; w <= 5000; ++w) F[i][w] = oo;
    for (int i = 1; i <= n; ++i) Min[i] = oo, Max[i] = 0;
    DFS(0, 1);

    int res = 1e9;
    for (int i = 0; i <= 5000; ++i) {
        if (F[1][i] != oo) res = min(res, F[1][i]);
    }

        //for (int i = 1; i <= n; ++i) cerr << Min[i] << " " << Max[i] << '\n';

    cout << res;
}

int main() {
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> val[i];
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }

    sol();

    return 0;
}
