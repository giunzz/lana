#include <bits/stdc++.h>
#define oo int(1e9 + 9)

using namespace std;

int N, NMAX, M50, M1, M2, kq = 0;

void backtrack(int i, int Sum50, int Sum1, int Sum2) {
    if(i > N) {
        kq++;
        return;
    }
    if(Sum50 + 1 <= NMAX)
        backtrack(i + 1, Sum50 + 1, Sum1, Sum2);
    if(Sum50 - 1 >= 0 && Sum1 + 1 <= NMAX)
        backtrack(i + 1, Sum50 - 1, Sum1 + 1, Sum2);
    if(Sum50 - 3 >= 0 && Sum2 + 1 <= NMAX)
        backtrack(i + 1, Sum50 - 3, Sum1, Sum2 + 1);
    if(Sum50 - 1 >= 0 && Sum1 - 1 >= 0 && Sum2 + 1 <= NMAX)
        backtrack(i + 1, Sum50 - 1, Sum1 - 1, Sum2 + 1);
}

int main() {
    freopen("ICECREAM.INP", "r", stdin);
    freopen("ICECREAM.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> NMAX;
    cin >> M50 >> M1 >> M2;
    backtrack(1, M50, M1, M2);
    cout << kq % oo;
}
