#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;

const string TASK = "liondance";
const string IN_FILE = TASK + ".inp";
const string OUT_FILE = TASK + ".out";
ifstream fin (IN_FILE);
ofstream fout (OUT_FILE);
#define cin fin
#define cout fout

using PI = pair<int, int>;
#define fi first
#define se second

signed main()
{
	int n, delta;
	cin >> n >> delta;
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

	vector< vector<int> > dp(n+2, vector<int>(n+2, 0));
//	vector< vector<bool> > imp(n+2, vector<bool>(n+2, 0));
	vector< vector< vector<PI> > > to(n+2, vector< vector<PI> >(n+2));
//	vector< vector< vector<PI> > > from(n+2, vector< vector<PI> >(n+2));

    for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i] != b[j]) continue;
            dp[i][j] = 1;
			for (int i1 = 1; i1 < i; ++i1) {
                for (int j1 = 1; j1 < j; ++j1) {
					if (a[i1] == b[j1] && abs(a[i1] - a[i]) <= delta)
						dp[i][j] = max(dp[i][j], dp[i1][j1] + 1);
                }
			}
		}
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) ans = max(ans, dp[i][j]);

    for (int i = n; i >= 1; --i) {
		for (int j = n; j >= 1; --j) if (dp[i][j] == ans || to[i][j].size()) {
			for (int i1 = 1; i1 < i; ++i1) {
                for (int j1 = 1; j1 < j; ++j1) {
					if (dp[i1][j1] && a[i1] == b[j1] && dp[i][j] == dp[i1][j1] + 1 && abs(a[i1] - a[i]) <= delta)
						to[i1][j1].push_back(PI(i, j));
                }
			}
		}
    }

    cout << ans << endl;

    vector<PI> idxs(n);
    for (int i = 1; i <= n; ++i) idxs[i] = PI(-a[i], i);
    sort(idxs.begin(), idxs.end());

    int i0, j0;
    bool found = 0;
    for (PI pi : idxs) {
		int i = pi.se;
        for (int j = 1; j <= n; ++j) {
			if (dp[i][j] == 1 && to[i][j].size()) {
                found = 1;
                i0 = i, j0 = j;
			}
			if (found) break;
        }
        if (found) break;
    }

    for (int _ = 0; _ < ans; ++_) {
//			cerr << i0 << ' ' << j0 << endl;
        cout << a[i0] << ' ';
        if (_ == ans-1) continue;
        int i1 = -1, j1 = -1;
        for (PI p : to[i0][j0]) {
            if (i1 < 0 || a[p.fi] >= a[i1]) i1 = p.fi, j1 = p.se;
        }
        i0 = i1, j0 = j1;
    }
}
