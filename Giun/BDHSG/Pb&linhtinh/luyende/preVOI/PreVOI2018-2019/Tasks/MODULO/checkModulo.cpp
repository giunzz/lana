#include "testlib_themis.h"

#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

int a, b, n;
unsigned long long k;

bool checkAnswer(InStream &stream) {
    string number = stream.readWord();
    if (number == "-1") return false;

    if (number.size() != n) stream.quitf(_wa, "The number has %d digits, but we need %d.", (int)number.size(), n);

    unsigned long long mod = 0;
    FORE(it, number) {
        if (*it != a + '0' && *it != b + '0')
            stream.quitf(_wa, "Digit should be either %d or %d, but '%c' found", a, b, *it);
        unsigned long long newMod = 0;
        REP(love, 10) newMod = (newMod + mod) % (1ULL << n);
        newMod = (newMod + *it - '0') % (1ULL << n);
        mod = newMod;
    }
    if (mod != k) stream.quitf(_wa, "Number modulo %lld, but we need %lld.", mod, k);
    return true;
}

int main(int argc, char* argv[]) {

#ifdef THEMIS
    registerTestlibThemis("modulo.inp", "modulo.out");
#else
    registerTestlibCmd(argc, argv);
#endif // THEMIS

    a = inf.readInt(1, 9, "a");
    b = inf.readInt(1, 9, "b");
    n = inf.readInt(1, 63, "n");
    k = inf.readLong(0ULL, (1ULL << n) - 1, "k");

    bool cont = checkAnswer(ouf);
    bool jury = checkAnswer(ans);

    if (jury) {
        if (cont) quitf(_ok, "Correct solution");
        else quitf(_wa, "Contestant thinks that solution does not exist, but it does!");
    } else {
        if (cont) quitf(_fail, "Jury thinks that solution does not exist, but it does!");
        else quitf(_ok, "No solution");
    }
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
