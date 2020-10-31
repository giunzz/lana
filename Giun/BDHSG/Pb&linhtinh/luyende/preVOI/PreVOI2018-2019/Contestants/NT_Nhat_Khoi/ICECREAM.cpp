#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair

#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << '\n'

#define task "ICECREAM"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 301, md = 1e9 + 9;

int n, lim, x1, x2, x3, res;
//vector<vector<vector<vector<int> > > > f;

bool check(int a, int b, int c, int d) {
    if (a + b + c + d > n) return 0;
    if (0 > x1 + a - b - c - 3 * d || x1 + a - b - c - 3 * d > lim) return 0;
    if (0 > x2 + b - c || x2 + b - c > lim) return 0;
    if (0 > x3 + c + d || x3 + c + d > lim) return 0;
    return 1;
}

void inc(int &x, int &y) {
    x = (x + y) % md;
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> lim;
    cin >> x1 >> x2 >> x3;
    int f[n+2][n+2][n+2][n+2];
    memset(f, 0, sizeof f);
    f[0][0][0][0] = 1;
    FOR(s, 0, n) {
        FOR(a, 0, s) {
            FOR(b, 0, s - a) {
                FOR(c, 0, s - a - b) {
                    int d = s - a - b - c;
                    //cerr << a << ' ' << b << ' ' << c << ' ' << d << '\n';
                    if (check(a + 1, b, c, d)) inc(f[a + 1][b][c][d], f[a][b][c][d]);
                    if (check(a, b + 1, c, d)) inc(f[a][b + 1][c][d], f[a][b][d][c]);
                    if (check(a, b, c + 1, d)) inc(f[a][b][c + 1][d], f[a][b][d][c]);
                    else if (check(a, b, c, d + 1)) inc(f[a][b][c][d + 1], f[a][b][d][c]);
                    if (a + b + c + d == n) {
                        res = (res + f[a][b][c][d]) % md;
                        //cerr << a << ' ' << b << ' ' << c << ' ' << f[a][b][c] << '\n';
                    }
                }
            }
        }
    }
    cout << res;
}
