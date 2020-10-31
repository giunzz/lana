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

#define NAME            "ARRANGE"

using namespace std;
const int N = 1e5 + 7;

int n,  a[N];
long Sum;

void Enter() {
    cin >> n;
    ff(i, 1, n) cin >> a[i], Sum += a[i];
}

void Sub1() {
    priority_queue<int, vector<int>, greater<int> > heap;
    ff(i, 1, n)
        if (Sum/n < a[i]) heap.push(i);

    int low = Sum/n;
    long res = 0;
    ff(i, 1, n) {
        while (a[i] < low) {
            int z = heap.top();
            if (a[i] + a[z] - low <= low) {
                res += abs(z-i) * (a[z]-low);
                a[i] += a[z] - low;
                a[z] = low;

                heap.pop();
            }
            else {
                res += abs(z-i) * (low-a[i]);
                a[z] -= low - a[i];
                a[i] = low;
            }
        }
    }
    cout << res << endl;
}

void TienXuLi() {
    priority_queue<int, vector<int>, greater<int> > heap;
    ff(i, 1, n)
        if (Sum/n + 1 < a[i]) heap.push(i);

    int low = Sum/n+1;
    long res = 0;
    ff(i, 1, n) {
        while (a[i] < Sum/n) {
            int z = heap.top();
            int need = Sum/n - a[i];
            if (a[i] + a[z] - low <= Sum/n) {
                res += abs(z-i) * (a[z]-low);
                a[i] += a[z] - low;
                a[z] = low;
                heap.pop();
            }
            else {
                res += abs(z-i) * (low-a[i]);
                a[z] -= Sum/n - a[i];
                a[i] = Sum/n;
            }
        }
    }

    cout << res + 5;
}

void Process() {
    TienXuLi();

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);
    Enter();
    if (Sum % n == 0) Sub1(); else Process();
    return 0;
}
