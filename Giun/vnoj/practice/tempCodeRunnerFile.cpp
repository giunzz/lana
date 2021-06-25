#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e6 + 7, base = 31, MOD = 1e9 + 9;
string a, b;
ll a_hash[mxn] = {0}, b_hash = 0, pw[mxn];

inline ll c(char a){return (a - 'a' + 1);}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> a >> b;
    a = '.' + a, b = '.' + b, pw[1] = 1;
    lp(i, 2, 1e6 + 2) pw[i] = (pw[i - 1] * base) % MOD;
    lp(i, 1, a.size() - 1) a_hash[i] = (a_hash[i - 1] + c(a[i]) * pw[i]) % MOD;
    lp(i, 1, b.size() - 1) (b_hash += c(b[i]) * pw[i]) %= MOD;
    lp(i, b.size(), a.size()) 
        if((b_hash * pw[i - b.size() + 1]) % MOD == (((a_hash[i - 1] - a_hash[i - b.size()]) % MOD) + MOD) % MOD) 
            cout << i - b.size() + 1 << ' '; 
}