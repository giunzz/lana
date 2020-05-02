#include <bits/stdc++.h>

#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, l, r) for (int i = l; i >= r; i--)
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define fr front
#define mp make_pair
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;
const int N = 1e6 + 7;

using namespace std;

int query;
int n, m, ans = 0;
vii qr;
int f[N], cnt[N];
vi lastPos;

int main() {
    fileInput("sc3");
    fast;

    cin >> query;
    REP(qq, query) {
      cin >> n >> m;
      //cerr << "n, m: " << n << " " << m << endl;
      FOR(i, 1, n) {
        int l, r;
        cin >> l >> r;
        qr.pb(mp(l, r));
      }
      memset(f, 0, sizeof(f));
      memset(cnt, 0, sizeof(cnt));
      REV(i, qr.size() - 1, 0) {
        int l = qr[i].fi, r = qr[i].se;
        if (lastPos.size() > 0) r = min(r, lastPos[lastPos.size() - 1]);
        //cerr << "qr: " << qr[i].fi << " " << qr[i].se << endl;
        //cerr << "l, r: " << l << " " << r << endl;
        REV(j, r, l) {
          f[j] = i + 1;
        }
        lastPos.pb(l - 1);
      }
      ans = 0;
      FOR(i, 1, m) {
        cnt[f[i]]++;
      }
      FOR(i, 1, n) if (cnt[i]) ans++;
      cout << ans << endl;
      qr.clear();
      lastPos.clear();
    }

    return(0);
}
//  Problem's link:
//  Problem's solution:
//  GMCoder4811
//  Bà ch? v?a chanh with luv