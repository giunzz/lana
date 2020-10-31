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

const string TASK = "table";
const string IN_FILE = TASK + ".inp";
const string OUT_FILE = TASK + ".out";
ifstream fin (IN_FILE);
ofstream fout (OUT_FILE);
#define cin fin
#define cout fout

typedef long long LL;
typedef vector<long long> VL;
typedef vector<VL> VVL;

const LL INFL = 1e17;

int R, C;
int si, sj, ei, ej;
VVL A, distStart, distEnd, distRow, distCol;

inline LL getDist(int i, int j) { return (i >= si && i <= ei && j >= sj && j <= ej) ? distStart[i][j] + distEnd[i][j] - A[i][j] : 0; }

void debug(VVL &v)
{
    for (auto &a : v) {
        for (auto &b : a) {
            cerr << b << ' ';
        }
        cerr << endl;
    }
    cerr << endl;
}

LL solve()
{
    distStart[si][sj] = A[si][sj];
    for (int i = si + 1; i <= ei; ++i) distStart[i][sj] = distStart[i-1][sj] + A[i][sj];
    for (int j = sj + 1; j <= ej; ++j) distStart[si][j] = distStart[si][j-1] + A[si][j];
    for (int i = si + 1; i <= ei; ++i) for (int j = sj + 1; j <= ej; ++j) {
        distStart[i][j] = max(distStart[i-1][j], distStart[i][j-1]) + A[i][j];
    }

    distEnd[ei][ej] = A[ei][ej];
    for (int i = ei - 1; i >= si; --i) distEnd[i][ej] = distEnd[i+1][ej] + A[i][ej];
    for (int j = ej - 1; j >= sj; --j) distEnd[ei][j] = distEnd[ei][j+1] + A[ei][j];
    for (int i = ei - 1; i >= si; --i) for (int j = ej - 1; j >= sj; --j) {
        distEnd[i][j] = max(distEnd[i+1][j], distEnd[i][j+1]) + A[i][j];
    }

    for (int i = si; i <= ei; ++i) {
        distRow[i][sj] = getDist(i, sj);
        for (int j = sj + 1; j <= ej; ++j) {
            distRow[i][j] = max(distRow[i][j-1], getDist(i, j));
        }
    }

//    debug(distStart);
//    debug(distEnd);

//    for (int i = si; i <= ei; ++i) {
//		for (int j = sj; j <= ej; ++j) {
//			cerr << getDist(si, sj) << ' ';
//		}
//		cerr << endl;
//    }
//    cerr << endl;

    for (int j = sj; j <= ej; ++j) {
        distCol[si][j] = getDist(si, j);
        for (int i = si + 1; i <= ei; ++i) {
            distCol[i][j] = max(distCol[i-1][j], getDist(i, j));
        }
    }

//    debug(distCol);

    LL ans = getDist(si, sj);

    for (int i = si; i <= ei; ++i) {
        for (int j = sj; j <= ej; ++j) {
            if (i == si && j == sj) continue;
            if (i == ei && j == ej) continue;

            LL cur1 = i < ei && j > sj ? distRow[i+1][j-1] : -INFL;
            LL cur2 = i > si && j < ej ? distCol[i-1][j+1] : -INFL;
			assert(cur1 >= 0 || cur2 >= 0);
			ans = min(ans, max(cur1, cur2));
        }
    }

    return ans;
}

signed main()
{
	int k;
	cin >> R >> C >> k;
	A.assign(R, VL(C));
	distStart.assign(R, VL(C));
	distEnd.assign(R, VL(C));
	distRow.assign(R, VL(C));
	distCol.assign(R, VL(C));

    for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> A[i][j];
		}
    }

    for (int i = 0; i < k; ++i) {
        int u, v, p, q;
        cin >> u >> v >> p >> q;
        --u, --v, --p, --q;
        si = u, sj = v, ei = p, ej = q;
        cout << solve() << '\n';
    }
}
