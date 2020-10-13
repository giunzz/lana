#include<bits/stdc++.h>
#define ll long long 
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void Ofile(){
    freopen(Fname ".inp", "r",  stdin);
    freopen(Fname ".out", "w",  stdout);
}

cll maxk = 1e6 + 7, MOD = 1e9 + 7;
ll n, k, p[maxk] = {0};
pp(ll, ll) numerator[maxk], denominator[maxk];

inline ll Pow(ll x, ll n){
    if(!n) return 1;
    ll tmp = Pow(x, n / 2) % MOD;
    if(n & 1) return ((tmp * tmp) % MOD * x) % MOD;
    else return (tmp * tmp) % MOD; 
}

void init(){
    lp(i, 1, k + 2){
        p[i] = (p[i - 1] + Pow(i, k)) % MOD;
    }
}

#define f first
#define b second

ll lagrange(){
    ll res = 0, tmp, tmp1;
    numerator[0] = denominator[0] = numerator[k + 3] = {1, 1};
    lp(i, 1, k + 2) 
        numerator[i].f = (numerator[i - 1].f * (n - i)) % MOD,
        denominator[i].f = (denominator[i - 1].f * i) % MOD;
    lpd(i, k + 2, 1) 
        numerator[i].b = (numerator[i + 1].b * (n - i)) % MOD;  
    lp(i, 1, k + 2){
        tmp1 = denominator[(k + 2) - i].f;
        if((i - (k + 2)) & 1) tmp1 *= -1;
        tmp1 = ((tmp1 + MOD) % MOD * denominator[i - 1].f) % MOD;
        tmp = ((numerator[i - 1].f * numerator[i + 1].b) % MOD * p[i]) % MOD;
        res = (res + tmp * Pow(tmp1, MOD - 2)) % MOD;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Ofile();
    cin >> n >> k;
    init();
    if(n <= k + 2) cout << p[n];
    else cout << lagrange();
}