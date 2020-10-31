#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll oo = 1000000000 + 7;
const int nmax = 1000000 + 7;
ll a[nmax], f[nmax], af[nmax];
int n, k;
ll res1 = 0, res2 = 0, tmp = 0;
ll tree[nmax * 8], ans1 = 0, ans2 = 0;

void input() {
  cin >> n >> k;
  f[0] = 0;
  for (int i = 1;i <= n;++ i) {
    cin >> a[i];
    f[i] += f[i - 1] + a[i];
    if (i >= k) af[i - k + 1] = f[i] - f[i - k];
  }
}

void print() {
  for (int i = 1;i <= n;++ i) cout << f[i] << " ";cout << "\n";
}

void sub2() {
//  print();
  res1 = oo;
  tmp = 0;
  for (int i = k;i <= n;++ i) {
    ll sumc = f[i] - f[i - k];
    tmp = 0;
//    cout << i << " : ";
    for (int j = k;j <= n;++ j) {
      if (j <= i - k || j >= i + k) {
//        cout << j << " ";
        tmp = max(tmp, f[j] - f[j - k]);
      }
    }
//    cout << "\n";
    if (tmp > sumc) continue;
    else {
      res1 = min(res1, sumc);
    }
  }
  cout << res1 << "\n";
}

int m = 0;

void build(int id, int l, int r) {
  if (l == r) {
    tree[id] = af[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v) {
  if (r < u || l > v) return 0;
  if (u <= l && r <= v) {
    return tree[id];
  }
  int mid = (l + r) / 2;
  return max(get(id * 2, l, mid, u, v),
             get(id * 2 + 1, mid + 1, r, u, v));
}

void sub3() {
  m = n - k + 1;
//  for (int i = 1;i <= m;++ i) cout << af[i] << " : " << i << " " << i + k - 1 << "\n"; //;cout << "\n";
  int l1 = 0, r1 = 0;
  build(1, 1, m);
  for (int i = 1;i <= m;++ i) {
    l1 = i - k;
    r1 = i + k;
    ans1 = 0, ans2 = 0;
    if (l1 >= k - 1) ans1 = get(1, 1, m, 1, l1);
    if (r1 <= m) ans2 = get(1, 1, m, r1, m);
    if (af[i] >= max(ans1, ans2)) {
      res1 = min(res1, af[i]);
    }
//    cout << af[i] << " : " << ans1 << " " << ans2 << "\n";
  }
  cout << res1 << "\n";
}

void solve() {
  if (n <= 5000) {
  sub2();
  exit(0);
  }
//  sub2();
  sub3();
}

int main()  {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  freopen("gifts.inp", "r", stdin);
  freopen("gifts.out", "w", stdout);
  input();
  solve();
  return 0;
}
