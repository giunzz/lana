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

vector<int> primeFact(int x) {
    map<int, int> cnt;

    for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) {
        int p = i;
        while (x % p == 0) {
            cnt[p]++;
            x /= p;
        }
    }
    if (x > 1) cnt[x] = 1;

    vector<int> res;
    FORE(it, cnt) if (it->se % 2 == 1) res.push_back(it->fi);
    return res;
}

void solve(int a, int b) {
    vector<int> va = primeFact(a); sort(ALL(va));
    vector<int> vb = primeFact(b); sort(ALL(vb));

    vector<int> s;
    FORE(it, va) if (!binary_search(ALL(vb), *it)) s.push_back(*it);
    FORE(it, vb) if (!binary_search(ALL(va), *it)) s.push_back(*it);

    long long bestA = a, bestB = b;
    REP(mask, MASK(s.size())) {
        long long pa = 1, pb = 1;
        REP(i, s.size()) if (BIT(mask, i)) pb *= s[i]; else pa *= s[i];
        if (pa + pb < bestA + bestB) {
            bestA = pa; bestB = pb;
        }
    }

    cout << bestA << " " << bestB << endl;
}

int main(void) {
#ifdef THEMIS
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
#endif // THEMIS

    int t; cin >> t;
    REP(love, t) {
        int a, b; cin >> a >> b;
        solve(a, b);
    }
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
