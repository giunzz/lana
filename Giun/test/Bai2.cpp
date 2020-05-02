
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define SZ(a) (int((a).size()))
#define ALL(a) (a).begin(), a.end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
const int MOD = 1e9;
using namespace std;
string S[20];
string P;
int lim;

typedef vector<int> big;

big operator + (big a, big b) {
    big c; int carry = 0;
    FOR(i, 0, max(SZ(a), SZ(b))) {
        if (i < SZ(a)) carry += a[i];
        if (i < SZ(b)) carry += b[i];
        c.PB(carry % MOD);
        carry /= MOD;
    }
    if (carry) c.PB(carry);
    return c;
}

void PRINT(big a) {
    cout << a[SZ(a) - 1];
    REPD(i, SZ(a) - 2, 0)
        printf("%09d", a[i]);
    cout << endl;
}

int Occ(string S, string P) {
    int cnt = 0;
    REP(i, 0, SZ(S) - SZ(P))
        cnt += S.substr(i, SZ(P)) == P;
    return cnt;
}

const int N = 1010;
big F[N]; int M[20][20];
int n;

int main() {
    cin >> n; cin >> S[1]; cin >> S[2]; cin >> P;
    FOR(i, 3, 20) {
        S[i] = S[i - 1] + S[i - 2];
        if (SZ(S[i - 1]) >= 100) {
            lim = i; break;
        }
    }
    FOR(i, lim + 1, 20) S[i] = S[i - 1] + S[i - 2];
    if (n < 20) cout << Occ(S[n], P);
    else {
        REP(i, 1, lim + 4) F[i].PB(Occ(S[i], P));
        REP(i, lim - 1, lim) REP(j, lim - 1, lim) {
            M[i][j] = Occ(S[i] + S[j], P) - F[i][0] - F[j][0];
        }
        REP(i, lim + 5, n) {
            big tmp; tmp.PB(M[lim - (i & 1)][lim]);
            F[i] = F[i - 1] + F[i - 2] + tmp;
        }
        PRINT(F[n]);
    }
    return 0;
}
