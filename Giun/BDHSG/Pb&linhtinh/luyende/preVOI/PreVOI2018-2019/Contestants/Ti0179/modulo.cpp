#include<bits/stdc++.h>
using namespace std;

int a, b, n, N, A, B;
unsigned long long k, K;
bool ck[100];

unsigned long long po(unsigned long long n, unsigned long long k){
    unsigned long long ans = 1;
    while (k){
        if (k&1) ans *= n;
        n *= n;
        k >>= 1;
    }
    return ans;
}

void out(){
    unsigned long long X = 0;
    for (int i = N-1; i >= 0; i--){
        X *= 10;
        if (ck[i] == 0){
            X += A;
            cout << A;
        }
        else{
            X += B;
            cout << B;
        }
    }
    X %= (1uLL << N);
}

int main(){
    srand(time(NULL));
    freopen("MODULO.inp", "r", stdin);
    freopen("MODULO.out", "w", stdout);
    cin >> a >> b >> n >> k;

    if (a > b) swap(a, b);
    N = n, A = a, B = b, K = k;

    unsigned long long cur = 0;
    for (int i = 0; i < n; i++) cur *= 10, cur += a;
    k -= cur; k %= (1uLL << n); b -= a;

    if (k == 0){
        out();
        return 0;
    }
    while (b % 2 == 0){
        if (k&1) return cout << "-1", 0;
        b >>= 1; k >>= 1;
        n--;
    }
    k *= po(b, (1uLL << (n-1)) - 1); k %= (1uLL << n);
    unsigned long long p = 1;
    for (int i = 0; i < N; i++){
        if ((k >> i)&1){
            ck[i] = 1;
            k -= p;
            k %= (1uLL << n);
        }
        p = p * 10 % (1uLL << n);
    }
    if (k != 0) return cout << "-1", 0;
    out();
}
