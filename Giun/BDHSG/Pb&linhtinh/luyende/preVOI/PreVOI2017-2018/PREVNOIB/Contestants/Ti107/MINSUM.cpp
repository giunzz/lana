#include <bits/stdc++.h>

#define ff(i,a,b)       for(int i=(a), _b=(b); i<=_b; ++i)
#define gg(i,a,b)       for(int i=(a), _b=(b); i>=_b; --i)
#define REP(i,b)        for(int i=(0), _b=(b); i< _b; ++i)
#define endl            '\n'
#define long            long long
#define SX(a)           ((int)(a).size())
#define Love(a)         {cerr << #a << " = " << a << endl;}
#define _               << "," <<
#define BIT(i, x)       (((x)>>(i))&1)
#define X               first
#define Y               second

#define NAME            "MINSUM"

using namespace std;
const int N = 100;
const int INF = 2e9 + 7;

int test, A, B, a[N], n;
map <int, int> MAP;

void Enter() {
    cin >> A >> B;
}

void Ptach(int x) {
    ff(i, 2, trunc(sqrt(x)))
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                MAP[i]++;
            }
        }
    if (x > 1) ++MAP[x];
}

void Process() {
    MAP.clear();
    Ptach(A);
    Ptach(B);

    n = -1;
    for (auto it = MAP.begin(); it != MAP.end(); ++it) {
      //  cout << it->X << ' ' << it->Y << endl;
        if ((it->Y)&1) {
            a[++n] = (it->X);
        }
    }

    if (n == -1) {
        cout << 1 << ' ' << 1 << endl;
        return;
    }

    //REP(i, n+1) Love(a[i])

    long res = INF, save[2];
    REP(t, 1<<(n+1)) {
        long s[2] = {1, 1};
        REP(i, n+1) {
            int v = BIT(i, t);
            s[v] *= a[i];
            if (s[v] > INF) break;
        }

        if (res > s[0] + s[1]) {
            res = s[0] + s[1];
            REP(i, 2) save[i] = s[i];
        }
    }

    cout << save[0] << ' ' << save[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);
    cin >> test;
    while (test--) {
        Enter();
        Process();
    }
    return 0;
}
