#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("Fibonacci.INP", "r", stdin);
    freopen("Fibonacci.OUT", "w", stdout);
    long long int n, fib[5];
    cin >> n;
    if (n == 0 || n == 1) cout << "1";
    else {
        fib[0] = 1, fib[1] = 1;
        for (int i = 2; i < n; i++){
            fib[2] = fib[0] + fib[1];
            fib[1] = fib[0];
            fib[0] = fib[2];
        }
        cout << fib[2];
    }
    return 0;
}
