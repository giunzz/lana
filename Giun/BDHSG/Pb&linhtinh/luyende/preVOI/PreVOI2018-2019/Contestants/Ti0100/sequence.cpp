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

const string TASK = "sequence";
const string IN_FILE = TASK + ".inp";
const string OUT_FILE = TASK + ".out";
ifstream fin (IN_FILE);
ofstream fout (OUT_FILE);
#define cin fin
#define cout fout
#define rank rnkdlfkajsldifjlkasd

typedef pair<int, int> PI;
#define fi first
#define se second

vector<int> firstOrder, rank[2], A[2];
vector< pair<int, int> > rankPref[2], vecPair;
vector< vector<int> > trace, ans[2], orderTemp;

const int INF = 1e9;

void debug(vector< vector<int> > &v)
{
    for (auto &a : v) {
        for (auto &b : a) {
            cerr << b << ' ';
        }
        cerr << endl;
    }
    cerr << endl;
}

void solve(int id)
{
	int sz = A[id].size();

	// initialize
    vecPair.resize(sz); firstOrder.resize(sz);
    rank[0].assign(sz, 0); rank[1].assign(sz, 0);
    rankPref[0].resize(sz); rankPref[1].resize(sz);
    trace.assign(sz + 1, vector<int>(sz));
    orderTemp.resize(sz);

    // firstOrder
    for (int i = 0; i < sz; ++i) vecPair[i] = pair<int, int> (A[id][i], i);
    sort(vecPair.begin(), vecPair.end());
    for (int i = 0; i < sz; ++i) firstOrder[i] = vecPair[i].second;

    // first time
    ans[id][1] = {vecPair[0].first};
//    int cur = -1;
    for (int i = 0; i < sz; ++i) {
//    	if (i > 0 && A[id][firstOrder[i-1]] == A[id][firstOrder[i]])
//			rank[1][ firstOrder[i] ] = ++cur;
//		else rank[1][ firstOrder[i] ] = cur;
		rank[1][firstOrder[i]] = i;
    }

    rankPref[1][0] = PI(rank[1][0], 0);
	for (int i = 1; i < sz; ++i) {
		PI cur (rank[1][i], i);
        rankPref[1][i] = min(rankPref[1][i-1], cur);
	}

//    for (auto i : rankPref[1]) cerr << '(' << i.fi << ", " << i.se << ')' << ' '; cerr << endl;
//    exit(0);

	// and beyond ...
	for (int i = 1; i < sz; ++i) {
//		cerr << "i: " << i << endl;

		for (int j = 0; j < sz; ++j) orderTemp[j].clear();
        for (int idx : firstOrder) {
        	if (idx == 0 || rankPref[i&1][idx - 1].se < 0) continue;
//        	cerr << idx << endl;
//        	cerr << rankPref[i&1][idx - 1].fi << endl;
            orderTemp[rankPref[i&1][idx - 1].fi].push_back(idx);
//            cerr << "S" << endl;
            trace[i+1][idx] = rankPref[i&1][idx - 1].se;
//            cerr << trace[i+1][idx] << ' ';
        }
//        cerr << endl;

        int cur = 0, best = -1;
//        cerr << endl;
        for (int idx = 0; idx < sz; ++idx) rank[((i&1)^1)][idx] = INF;
        for (int j = 0; j < sz; ++j) {
//			cerr << "j: " << j << ' ' << orderTemp[j].size() << endl;
            for (int idx : orderTemp[j]) {
				if (!cur) best = idx;
                rank[((i&1)^1)][idx] = cur++;
//                cerr << idx << ": " << cur << endl;
            }
        }
//        for (int j = 0; j < sz; ++j) cerr << rank[((i&1)^1)][j] << ' '; cerr << endl;

		vector<int> &curAns = ans[id][i+1]; curAns.resize(i+1);
		for (int k = i; k >= 0; --k) {
			curAns[k] = A[id][best];
            best = trace[k+1][best];
		}

		for (int idx = 0; idx < sz; ++idx) rankPref[((i&1)^1)][idx] = PI(INF, -1);
		rankPref[((i&1)^1)][0] = (rank[((i&1)^1)][0] < INF ? PI(rank[((i&1)^1)][0], 0) : PI(INF, -1));
		for (int j = 1; j < sz; ++j) {
			PI cur = (rank[((i&1)^1)][j] < INF ? PI(rank[((i&1)^1)][j], j) : PI(INF, -1));
			rankPref[((i&1)^1)][j] = min(rankPref[((i&1)^1)][j-1], cur);
		}

//		for (auto x : rankPref[((i&1)^1)]) cerr << '(' << x.fi << ", " << x.se << ')' << ' '; cerr << endl;
	}
}

void add(int i1, int i2, const vector<int> &v1, const vector<int> &v2, vector<int> &nxt1, vector<int> &nxt2, vector<int> &vec)
{
    if (i1 == (int)v1.size()) {
        for (int i = i2; i < (int)v2.size(); ++i) vec.push_back(v2[i]);
        return;
    }

    if (i2 == (int)v2.size()) {
        for (int i = i1; i < (int)v1.size(); ++i) vec.push_back(v1[i]);
        return;
    }

    bool add1 = 0, add2 = 0, add12 = 0;

    if (v1[i1] < v2[i2]) add1 = 1;
    else if (v1[i1] > v2[i2]) add2 = 1;
	else {
		int x1 = (nxt1[i1] == (int)v1.size() ? INF : v1[ nxt1[i1] ]);
		int x2 = (nxt2[i2] == (int)v2.size() ? INF : v2[ nxt2[i2] ]);

		if (min(x1, x2) >= v1[i1]) add12 = 1;

		else if (x1 < v1[i1] && v1[i1] < x2) add1 = 1;
		else if (x2 < v1[i1] && v1[i1] < x1) add2 = 1;

		else if (nxt1[i1] - i1 < nxt2[i2] - i2) add1 = 1;
		else if (nxt1[i1] - i1 > nxt2[i2] - i2) add2 = 1;

		else if (x1 < x2) add1 = 1;
		else if (x1 > x2) add2 = 1;
		else add12 = 1;
	}

	if (add12) {
		for (int i = i1; i < nxt1[i1]; ++i) vec.push_back(v1[i1]);
		for (int i = i2; i < nxt2[i2]; ++i) vec.push_back(v2[i2]);
		add(nxt1[i1], nxt2[i2], v1, v2, nxt1, nxt2, vec);
		return;
	} else if (add1) {
		for (int i = i1; i < nxt1[i1]; ++i) vec.push_back(v1[i1]);
		add(nxt1[i1], i2, v1, v2, nxt1, nxt2, vec);
		return;
	} else if (add2) {
		for (int i = i2; i < nxt2[i2]; ++i) vec.push_back(v2[i2]);
		add(i1, nxt2[i2], v1, v2, nxt1, nxt2, vec);
		return;
	} else assert(0);
}

signed main()
{
	int m, n, k;
    cin >> m >> n >> k;
    for (int id = 0; id < 2; ++id) {
        int sz = (id == 0 ? m : n);
        A[id].resize(sz);
        ans[id].resize(sz + 1);
        for (int i = 0; i < sz; ++i) cin >> A[id][i];
        solve(id);

//        debug(ans[id]);
    }

    vector<int> res = {INF};
    for (int k1 = 0; k1 <= m; ++k1) {
        int k2 = k - k1;
        if (k2 < 0 || k2 > n) continue;

        vector<int> &v1 = ans[0][k1], &v2 = ans[1][k2];
        vector<int> nxt1(k1), nxt2(k2);
        vector<int> cur; cur.reserve(k);
        nxt1[k1-1] = k1; for (int i = k1 - 2; i >= 0; --i) nxt1[i] = (v1[i] == v1[i+1] ? nxt1[i+1] : i+1);
        nxt2[k2-1] = k2; for (int i = k2 - 2; i >= 0; --i) nxt2[i] = (v2[i] == v2[i+1] ? nxt2[i+1] : i+1);
        add(0, 0, v1, v2, nxt1, nxt2, cur);

        res = min(res, cur);
    }

    for (int x : res) cout << x << ' ';
//    for (int x : res) cerr << x << ' ';
}
