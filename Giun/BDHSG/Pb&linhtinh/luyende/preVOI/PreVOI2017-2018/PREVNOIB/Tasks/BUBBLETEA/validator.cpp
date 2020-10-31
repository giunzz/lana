#include "testlib.h"

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

class DisjointSet {
private:
    vector<int> lab;

    int find(int x) {
        return lab[x] < 0 ? x : lab[x] = find(lab[x]);
    }

public:
    DisjointSet(int n = 0) {
        lab.assign(n + 7, -1);
    }

    bool join(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
};

const int MAX_N = (int)5e4;
const int MAX_C = (int)1e9;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, MAX_N, "n"); inf.readSpace();
    int k = inf.readInt(2, n, "k"); inf.readEoln(); ensure(k % 2 == 0);
    set<int> s;
    REP(love, k) {
        ensure(s.insert(inf.readInt(1, n, "node")).se);
        inf.readSpace();
    }
    inf.readEoln();

    DisjointSet dsu(n);
    REP(love, n - 1) {
        int u = inf.readInt(1, n, "u"); inf.readSpace();
        int v = inf.readInt(1, n, "v"); inf.readSpace();
        ensure(dsu.join(u, v));
        inf.readInt(1, MAX_C, "c"); inf.readEoln();

    }
    inf.readEof();
    printf("ok %d %d\n", n, k);
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
