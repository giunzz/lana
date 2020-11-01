#include<bits/stdc++.h>

using namespace std;

const int N = 3e3 + 5, inf = 1e9 + 123;
int n, m, K, a[N], b[N], ans[2][N << 1], rmqA[12][N], rmqB[12][N], cur, nxt = 1;

int read_int () {
    int ret = 0; char inp;
    do { inp = getchar(); } while (!isdigit(inp) ); ret = inp - '0';
    while (isdigit(inp = getchar() ) ) { ret = 10 * ret + inp - '0'; }
    return ret;
}

int getA (int l, int r) {
    int LOG2 = log2(r - l + 1);
    return (a[ rmqA[LOG2][l] ] <= a[ rmqA[LOG2][r - (1 << LOG2) + 1] ] ? rmqA[LOG2][l] : rmqA[LOG2][r - (1 << LOG2) + 1]);
}

int getB (int l, int r) {
    int LOG2 = log2(r - l + 1);
    return (b[ rmqB[LOG2][l] ] <= b[ rmqB[LOG2][r - (1 << LOG2) + 1] ] ? rmqB[LOG2][l] : rmqB[LOG2][r - (1 << LOG2) + 1]);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);

    n = read_int();
    m = read_int();
    K = read_int();
    for (int i = 1; i <= n; ++i) {
        a[i] = read_int();
        rmqA[0][i] = i;
    }
    for (int i = 1; i < 12; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j + (1 << i) - 1 <= n) rmqA[i][j] = (a[ rmqA[i - 1][j] ] <= a[ rmqA[i - 1][j + (1 << (i - 1) ) ] ] ? rmqA[i - 1][j] : rmqA[i - 1][j + (1 << (i - 1) ) ]);
        }
    }

    for (int i = 1; i <= m; ++i) {
        b[i] = read_int();
        rmqB[0][i] = i;
    }
    for (int i = 1; i < 12; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j + (1 << i) - 1 <= m) rmqB[i][j] = (b[ rmqB[i - 1][j] ] <= b[ rmqB[i - 1][j + (1 << (i - 1) ) ] ] ? rmqB[i - 1][j] : rmqB[i - 1][j + (1 << (i - 1) ) ]);
        }
    }

    ans[cur][1] = inf;
    for (int i = 0; i <= n; ++i) {
        int j = K - i;
        if (j < 0 || j > m) continue ;
        int remI = i, remJ = j, curI = 1, curJ = 1, iAns = 0;
        while (remI || remJ) {
            if (!remJ) {
                curI = getA(curI, n - remI + 1);
                ans[nxt][++iAns] = a[curI];
                curI ++; remI --;
            }
            else if (!remI) {
                curJ = getB(curJ, m - remJ + 1);
                ans[nxt][++iAns] = b[curJ];
                curJ ++; remJ --;
            }
            else {
                curI = getA(curI, n - remI + 1);
                curJ = getB(curJ, m - remJ + 1);
                if (a[curI] <= b[curJ]) {
                    ans[nxt][++iAns] = a[curI];
                    curI ++; remI --;
                }
                else {
                    ans[nxt][++iAns] = b[curJ];
                    curJ ++; remJ --;
                }
            }
        }
        for (int k = 1; k <= K; ++k) {
            if (ans[cur][k] < ans[nxt][k]) break ;
            else if (ans[cur][k] > ans[nxt][k]) {
                cur ^= 1; nxt ^= 1;
                break ;
            }
        }
    }

    for (int i = 1; i <= K; ++i) cout << ans[cur][i] << ' ';

    return 0;
}
