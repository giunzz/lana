#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int m, n, k;
const int nmax = 2000 + 7;
struct data {
  int x = 0, y = 0, z = 0;
  int r = 0, e;
};data f[nmax], a[nmax], gs;
struct fsd{
  int x = 0, val = 0;
  int type = 0;
};fsd tp[100000 + 7];;
int max_tp = 0;
int id = 0;
int tmm = 0;

void input() {
  memset(tp, -1, sizeof(tp));
  cin >> m >> n >> k;
  for (int i = 1;i <= m;++ i) {
    cin >> f[i].x >> f[i].y >> f[i].z >> f[i].r;
    ++ tmm;
    tp[tmm].x = f[i].x;
    tp[tmm].val = f[i].r;
    tp[tmm].type = 1;
    max_tp = max(max_tp, f[i].x);
  }
  for (int i = 1;i <= n;++ i) {
    cin >> a[i].x >> a[i].y >> a[i].z >> a[i].e;
    ++ tmm;
    tp[tmm].x = a[i].x;
    tp[tmm].val = a[i].e;
    tp[tmm].type = 0;
    max_tp = max(max_tp, a[i].e);
  }
  cin >> gs.x >> gs.y >> gs.z;
}

bool compare(fsd a, fsd b) {
  return a.x < b.x && a.val < b.val;
}

void solve() {
  sort(tp + 1, tp + tmm + 1, compare);
//  for (int i = 1;i <= tmm;++ i) cout << tp[i].type << " : " << tp[i].x << " " << tp[i].val << "\n";
  cout << max_tp << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  freopen("teaworld.inp", "r", stdin);
  freopen("teaworld.out", "w", stdout);
  input();
  solve();
  return 0;
}
