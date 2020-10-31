#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int, ll> ii;
int n, k;
const int nmax = 50000 + 7;
const ll oo = 1000000000 + 7;
int p[nmax], h[nmax], id[nmax];
vector <ii> a[nmax];
ii parent[nmax + 7][20 + 7];
ll sum[nmax], res_max = 0, res = oo;
bool fre[nmax];

void input() {
  cin >> n >> k;
  for (int i = 1;i <= k;++ i) cin >> p[i];
  for (int i = 1;i <= n - 1;++ i) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    a[u].push_back(mp(v, c));
    a[v].push_back(mp(u, c));
  }
}

void dfs(int u) {
  for (int i = 0;i < a[u].size();++ i) {
    int v = a[u][i].F;
    ll wv = a[u][i].S;
    if (v != parent[u][0].F) {
      parent[v][0].F = u;
      h[v] = h[u] + 1;
      sum[v] = sum[u] + wv;
      for (int j = 1;j <= 20;++ j) {
        parent[v][j].F = parent[parent[v][j - 1].F][j - 1].F;
      }
      dfs(v);
    }
  }
}

ii lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  int D = h[u] - h[v];
  ii res;
  res.S = oo;
  for (int i = 0;i <= 20;++ i) {
    if ((D >> i) & 1) {
      u = parent[u][i].F;
    }
  }
  res.F = u;
  if (u == v) return res;
  for (int i = 20;i >= 0;-- i) {
    if (parent[u][i].F != parent[v][i].F) {
      u = parent[u][i].F;
      v = parent[u][i].F;
    }
  }
  res.F = parent[u][0].F;
  return res;
}

void print() {
  for (int i = 1;i <= k;++ i) {
    cout << id[i] << " ";
  }cout << "\n";
}

void sinh(int i) {
  if (i > k) {
    res_max = 0;
    for (int i = 1;i <= k;++ i) {
      int iii = id[i], jjj = id[i + 1];
      if (i % 2 == 1) {
        res_max = max(res_max, sum[p[iii]] + sum[p[jjj]] - 2 * sum[lca(p[iii], p[jjj]).F]);
        if (res_max > res) break;
      }
    }
    res = min(res, res_max);
  }
  else {
    for (int j = 1;j <= k;++ j) {
      if (fre[j]) {
        id[i] = j;
        fre[j] = false;
        sinh(i + 1);
        fre[j] = true;
      }
    }
  }
}

void sub1() {
  memset(fre, true, sizeof(fre));
  for (int i = 1;i <= k;++ i) id[i] = i;
  sinh(1);
  cout << res << "\n";
}

void sub2() {
  for (int i = 1;i <= k;++ i) {
    for (int j = 1;j <= k;++ j) {
      if (i == j) continue;
      res_max = max(res_max, sum[p[i]] + sum[p[j]] - 2 * sum[lca(p[i], p[j]).F]);
    }
  }
  cout << res_max;
}

void solve() {
  memset(parent, 0, sizeof(parent));
  for (int i = 1;i <= n;++ i) {
    for (int j = 0;j <= 20;++ j) {
      parent[i][j].S = oo;
    }
  }
  h[1] = 1;
  sum[1] = 0;
  dfs(1);
  if (k <= 10) sub1();
  else sub2();
}

int main()  {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  freopen("bubbletea.inp", "r", stdin);
  freopen("bubbletea.out", "w", stdout);
  input();
  solve();
  return 0;
}
