#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string TASK = "modulo";
const string IN_FILE = TASK + ".inp";
const string OUT_FILE = TASK + ".out";
ifstream fin(IN_FILE);
ofstream fout(OUT_FILE);
#define cin fin
#define cout fout

typedef unsigned long long ULL;

ULL prep[2][70], D[2], K;
bool idxs[70];
int N;

void check()
{
	ULL cur = 0;
    for (int i = N - 1; i >= 0; --i) {
		cur = cur * 10 + D[idxs[i]];
    }
    assert(!((cur ^ K) & ((1ull << N) - 1ull)));
}

void bt(int curDigits, ULL curSum)
{
//	cerr << ((curSum ^ K) & ((1ull << curDigits) - 1ull)) << endl;
	if ((curSum ^ K) & ((1ull << curDigits) - 1ull)) return;
//	cerr << curDigits << ' ' << curSum << endl;

    if (curDigits == N) {
		for (int i = N - 1; i >= 0; --i) cout << D[idxs[i]];
//		check();
		exit(0);
    }

    idxs[curDigits] = 0;
    bt(curDigits + 1, curSum + prep[0][curDigits]);
    idxs[curDigits] = 1;
    bt(curDigits + 1, curSum + prep[1][curDigits]);
}

signed main()
{
    cin >> D[0] >> D[1] >> N >> K;

	prep[0][0] = D[0], prep[1][0] = D[1];
    for (int i = 1; i < 64; ++i) for (int j = 0; j < 2; ++j) {
		prep[j][i] = prep[j][i-1] << 1;
        prep[j][i] += prep[j][i] << 2;
    }

//    cerr << prep[0][18] << endl;

	bt(0, 0);
	cout << -1;
	return 0;
}
