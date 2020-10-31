#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int nmax = 100000 + 7;
ll a[nmax], sum = 0;
struct fuckyou{
  ll rock, id;
};fuckyou f[nmax];
int n;
ll res = 0;

void input() {
  cin >> n;
  for (int i = 1;i <= n;++ i) {
    cin >> a[i];
    f[i].id = i;
    f[i].rock = a[i];
    sum += a[i];
  }
}

bool compare(fuckyou a, fuckyou b) {
  return a.rock < b.rock || a.rock == b.rock && a.id < b.id;
}

void sub1() {
  int iden = n;
  ll tmp = sum / n;
  sort(f + 1, f + n + 1, compare);
  for (int i = 1;i <= n;++ i) {
    if (f[i].rock < tmp) {
      if (f[iden].rock > tmp) {
        int tx = f[iden].rock - tmp;
        int tx2 = f[i].rock;
//        cout << tx << "\n";
        f[i].rock = min(tmp, f[i].rock + tx);
        res += (f[i].rock - tx2) * abs(f[i].id - f[iden].id);
        f[iden].rock = f[iden].rock - (f[i].rock - tx2);

      }
      else iden --;
    }
  }
//  for (int i = 1;i <= n;++ i) cout << f[i].rock << " ";cout << "\n";
  cout << res << "\n";
}

void solve() {
//  if (sum % n == 0) {
    sub1();
//  }
//  else cout << 1;
}

int main()  {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  freopen("arrange.inp", "r", stdin);
  freopen("arrange.out", "w", stdout);
  input();
  solve();
  return 0;
}
