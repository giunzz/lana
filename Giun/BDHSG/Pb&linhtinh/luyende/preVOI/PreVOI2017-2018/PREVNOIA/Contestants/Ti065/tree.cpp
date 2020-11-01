#include <bits/stdc++.h>

using namespace std;

const int nmax = 5000 + 7;
int n;
int p[nmax];
vector <int> a[nmax];
int parent[nmax], sum[nmax];
bool fre[nmax];
int f[nmax];
int tp1[nmax], tp2[nmax];
int cnt = 0;
int res = 0;

void input() {
  cin >> n;
  for (int i = 1;i <= n;++ i) cin >> p[i];
  for (int i = 1;i <= n - 1;++ i) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
}

void dfs(int u) {
  ++ cnt;
  tp1[u] = cnt;
  sum[u] += p[u];
  int v1 = -1, v2 = -1;
  for (int i = 0;i < a[u].size();++ i) {
    int v = a[u][i];
    if (fre[v]) {
      fre[v] = false;
      parent[v] = u;
      if (v1 == -1) v1 = v;
      else v2 = v;
      dfs(v);
      sum[u] += sum[v];
    }
  }
  if (v1 == -1) return;
  if (a[v1].size() == 1) {
    if (p[v1] != 1) {
      res += abs(p[v1] - 1);
      f[v1] = 1;
    }
    else f[v1] = 1;
  }
  if (a[v2].size() == 1) {
    if (p[v2] != 1) {
      res += abs(p[v2] - 1);
      f[v2] = 1;
    }
    else f[v2] = 1;
  }
  int tmp = f[v1] + f[v2];
  res += abs(tmp - p[u]);
  f[u] = tmp;
  tp2[u] = cnt;
}

void solve() {
  memset(fre, true, sizeof(fre));
  fre[1] = false;
  dfs(1);
//  for (int i = 1;i <= n;++ i) {
//    cout << p[i] << " : " << sum[i] - p[i] << "\n";
//  }
  cout << res << "\n";
//  for (int i = 1;i <= n;++ i) cout << tp1[i] << " " << tp2[i] << "\n";
}

int main()  {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  freopen("tree.inp", "r", stdin);
  freopen("tree.out", "w", stdout);
  input();
  solve();
  return 0;
}
