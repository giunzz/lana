#include "testlib_themis.h"

#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define SQR(x) (1LL * (x) * (x))
bool is_square(long long x) {
    long long tmp = sqrt(x);
    FOR(i, -3, 3) if (SQR(tmp + i) == x) return true;
    return false;
}

bool valid(int a, int b, long long x, long long y) {
    if (x <= 0 || y <= 0) return false;
    long long c = 1LL * a * b;
    if (c % x != 0) return false; c /= x;
    if (c % y != 0) return false; c /= y;
    return is_square(c);
}

bool checkTest(int testID) {
    int a = inf.readInt();
    int b = inf.readInt();
    long long jx = ans.readLong();
    long long jy = ans.readLong();
    if (!valid(a, b, jx, jy))
        quitf(_fail, "Jury's answer on test #%d is invalid", testID);
    long long px = ouf.readLong();
    long long py = ouf.readLong();
    if (!valid(a, b, px, py)) return false;
    if (jx + jy == px + py) return true;
    if (jx + jy < px + py) return false;
    quitf(_fail, "Participant has better answer on test #%d", testID);
    assert(false);
}

int main(int argc, char* argv[]) {
#ifdef THEMIS
    registerTestlibThemis("minsum.inp", "minsum.out");
#else
    registerTestlibCmd(argc, argv);
#endif // THEMIS

    int numTest = inf.readInt();
    int numCorrect = 0;
    REP(love, numTest) if (checkTest(love + 1)) numCorrect++;
    quitp(1.0 * numCorrect / numTest, "correct %d of %d", numCorrect, numTest);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
