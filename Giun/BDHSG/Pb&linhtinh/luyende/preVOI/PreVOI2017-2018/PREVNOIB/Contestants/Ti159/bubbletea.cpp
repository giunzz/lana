#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
typedef pair<int, int> ii;

int n, k;
int sum[N];
long long f[N];
bool flag[N];
bool ok;
vector<ii> G[N];

void dfs(int u, int p, long long x) {
    vector<long long> go;
    f[u] = -1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i].first, w = G[u][i].second;
        if (v == p) continue;
        dfs(v, u, x);
        if (f[v] != -1) go.push_back(f[v] + w);
    }
    if (flag[u]) go.push_back(0);
    sort(go.begin(), go.end());
    int sz = go.size();
//    cout << "at " << u << '\n';
//    for (int i = 0; i < sz; ++i) cout << go[i] << ' '; cout << '\n';
    if (sz % 2 == 0) {
        for (int i = 0; i < sz / 2; ++i) {
            if (go[i] + go[sz - 1 - i] > x) ok = 0;
        }
    }
    else {
        for (int i = 0; i < sz; ++i) sum[i] = 0;
        for (int i = 0; i <= sz / 2; ++i) {
            if (i < sz - i - 2 && sz - i - 2 < sz) {
//                cout << i << ' ' << sz - i - 2 << '\n';
                if (go[i] + go[sz - i - 2] > x) sum[sz - i - 1]++;
            }
            if (i < sz - i - 1 && sz - i - 1 < sz) {
//                cout << i << ' ' << sz - i - 1 << '\n';
                if (go[i] + go[sz - i - 1] > x) sum[i + 1]++, sum[sz - i - 1]--;
            }
            if (i < sz - i && sz - i < sz) {
//                cout << i << ' ' << sz - i << '\n';
                if (go[i] + go[sz - i] > x) sum[0]++, sum[i]--;
            }
        }
        for (int i = 1; i < sz; ++i) sum[i] += sum[i - 1];
//        for (int i = 0; i < sz; ++i) cout << sum[i] << '\n';
        for (int i = 0; i < sz; ++i) {
            if (!sum[i]) { f[u] = go[i]; break; }
        }
        if (f[u] == -1) ok = 0;
    }
}

int main() {
    freopen("bubbletea.inp", "r", stdin);
    freopen("bubbletea.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int x; cin >> x; flag[x] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(ii(v, w));
        G[v].push_back(ii(u, w));
    }
//    ok = 1, dfs(1, 1, 12);
//    cout << ok << '\n';
    long long l = 0, r = 1e15;
    while (l < r) {
        long long mid = (l + r) >> 1;
        ok = 1, dfs(1, 1, mid);
        if (ok) r = mid; else l = mid + 1;
    }
    cout << l;
}

/*
8 6
1 4 5 6 7 8
1 2 1
2 3 1
3 4 1
2 5 1
2 6 1
3 7 1
3 8 1
*/
