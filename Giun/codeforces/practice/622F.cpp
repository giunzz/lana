#include<bits/stdc++.h>
#define ll long long 
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define Fname "f"
using namespace std;

void Ofile(){
    freopen(Fname ".inp", "r",  stdin);
    freopen(Fname ".out", "w",  stdout);
}

cll maxk = 1e6 + 7, MOD = 1e9 + 7;
ll n, k, p[maxk] = {0};

ll Pow(ll x, ll n){
    if(!n) return 1;
    ll tmp = Pow(x, n / 2) % MOD;
    if(n & 1) return ((tmp * tmp) % MOD * x) % MOD;
    else return (tmp * tmp) % MOD; 
}

void init(){
    lp(i, 1, k + 1){
        p[i] = (p[i - 1] + Pow(i, k)) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Ofile();
    cin >> n >> k;
    init();
    if(n < k + 2) cout << p[n];
}