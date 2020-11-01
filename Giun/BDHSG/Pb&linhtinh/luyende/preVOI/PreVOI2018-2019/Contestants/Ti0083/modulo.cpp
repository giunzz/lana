#include <bits/stdc++.h>
#define ll long long
using namespace std;
int A, B, n;
ll k, N;

bool check(ll S){
    if (S % N == k)
    { cout << S; return 1; }
    return 0;
}

bool thu(int t, ll S){
    if (t > n) return check(S);
    bool fl=0;
    fl = thu(t+1, S*10 + A);
    if (fl == 1) return 1;
    fl = thu(t+1, S*10 + B);
    return fl;
}

bool ok(ll S){
    for (int i=1; i<=n; ++i)
    {
        if (S % 10 != A && S % 10 != B) return 0;
        S=S/10;
    }
    return 1;
}

int main(){
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    scanf("%d%d", &A, &B);
    scanf("%d%lld", &n, &k);

    N=1LL*(1LL << n);
    if (thu(1, 0) == 0) cout << -1;

    if (n > 20)
    {
        ll mx=0;
        for (int i=1; i<=n; ++i) mx=mx*10 + max(A, B);

        for (int t=0; k + N*t <= mx; ++t)
        if (ok(k + N*t)) {cout << k+N*t; return 0;}
        cout << -1;
    }

    return 0;
}
