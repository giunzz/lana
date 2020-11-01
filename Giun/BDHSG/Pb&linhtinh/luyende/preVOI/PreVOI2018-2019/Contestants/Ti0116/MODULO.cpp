#include <bits/stdc++.h>

using namespace std;

int A, B, N;
long long K, cc = 1;

void backtrack(int i, long long Sum) {
    if(i > N) {
        if(Sum % cc == K)
            cout << Sum << '\n';
        return;
    }
    backtrack(i + 1, (long long)Sum * 10 + A);
    backtrack(i + 1, (long long)Sum * 10 + B);
}

int main() {
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> N >> K;
    for(int i = 1; i <= N; i++)
        cc *= 2;
    backtrack(1, 0);
}
