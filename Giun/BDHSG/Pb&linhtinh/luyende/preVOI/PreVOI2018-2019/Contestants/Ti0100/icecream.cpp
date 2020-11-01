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

const string TASK = "icecream";
const string IN_FILE = TASK + ".inp";
const string OUT_FILE = TASK + ".out";
ifstream fin(IN_FILE);
ofstream fout(OUT_FILE);
#define cin fin
#define cout fout

const int MOD = 1000000009;

using VI = vector<int>;
using VII = vector<VI>;
using VIII = vector<VII>;

int add (int a, int b) { a += b; if (a >= MOD) a -= MOD; return a;}
int sub (int a, int b) { a -= b; if (a < 0) a += MOD; return a;}
int mul (int a, int b) { return 1ll * a * b % MOD; }

signed main()
{
    int n, MMAX;
    int M50, M1, M2;
    cin >> n >> MMAX >> M50 >> M1 >> M2;

    VIII dp(2, VII(4*n+10, VI(2*n+10, 0)));
    int padd50 = 3*n + 5, padd1 = n + 5;
    dp[0][padd50][padd1] = 1;

    #define i2 ((i&1)^1)
    for (int i = 0; i < n; ++i) {
		int start_j = padd50 - 3*i - 3, end_j = padd50 + i + 3;
        for (int j = start_j; j <= end_j; ++j) {
//        for (int j = 0; j < 4*n+10; ++j) {

			int start_k = padd1 - i - 3, end_k = padd1 + i + 3;
            for (int k = start_k; k <= end_k; ++k) {
//            for (int k = 0; k < 2*n+10; ++k) {

                if (dp[i&1][j][k] == 0) continue;
                int cur = dp[i&1][j][k];

                int d50 = j - padd50, d1 = k - padd1;
                int d2 = (i - d50 - (d1 * 2));
//                if (!(d2 % 4 == 0 && d2 >= 0)) {
//                    cerr << i << ' ' << d50 << ' ' << d1 << endl;
//                }
                assert(d2 % 4 == 0 && d2 >= 0);
                d2 >>= 2;

                int m50 = M50 + d50, m1 = M1 + d1, m2 = M2 + d2;

//                cerr << i << ", " << m50 << ' ' << m1 << ' ' << m2 << ": " << cur << endl;

                // put 50
                if (m50 < MMAX) {
                    dp[i2][j+1][k] = add(dp[i2][j+1][k], cur);
                }

                // put 1
                if (m50 > 0 && m1 < MMAX) {
                    dp[i2][j-1][k+1] = add(dp[i2][j-1][k+1], cur);
                }

                // put 2
                if (m2 < MMAX) {
                    if (m50 > 0 && m1 > 0) {
						dp[i2][j-1][k-1] = add(dp[i2][j-1][k-1], cur);
                    } else if (m50 > 2) {
						dp[i2][j-3][k] = add(dp[i2][j-3][k], cur);
                    }
                }
            }
        }

		for (int j = 0; j < 4*n+10; ++j) {
			for (int k = 0; k < 2*n+10; ++k) {
				dp[i&1][j][k] = 0;
			}
		}
    }

    int ans = 0;
    for (int j = 0; j < 4*n+10; ++j) {
        for (int k = 0; k < 2*n+10; ++k) {
			ans = add(ans, dp[n&1][j][k]);
        }
    }

    cout << ans;
    return 0;
}
