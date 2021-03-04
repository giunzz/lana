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

cll MOD = 1e9 + 7, mxn = 5e3 + 2;
ll n, a[mxn] = {0}, numNode[mxn] = {0}, p[mxn];
int down[mxn][mxn] = {{0}}, up[mxn][2] = {{0}};

ll Pow(ll u, ll v){
    if(!v) return 1;
    ll tmp = Pow(u, v >> 1);
    (tmp *= tmp) %= MOD;
    if(v & 1) return (tmp * u) % MOD;
    return tmp;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    numNode[1] = 1;
    lp(i, 1, n - 1){
        cin >> a[i];
        numNode[i + 1] = (numNode[i] * a[i]) % MOD;
        p[i] = Pow(a[i], MOD - 2);
    }
    lp(i, 1, n) down[i][1] = a[i], up[i][1] = 1;
    up[1][1] = 0;
    lpd(i, n - 1, 1) lp(j, 2, n - i) down[i][j] = (a[i] * down[i + 1][j - 1]) % MOD; 
    ll p2 = Pow(2, MOD - 2);
    lp(j, 1, n * 2 - 2){ 
        ll cnt_up = 0, cnt_down = 0;
        if(j != 1) lp(i, 2, n){
            if(j > n + i - 2) continue;
            //nhanh i len 1 mat i - 1 canh va tu 1 di xuong la mat n - 1 canh => max canh = n + i - 2   
            (up[i][j & 1] += up[i - 1][~j & 1]) %= MOD;
            if(j <= n && down[i - 1][j - 1]) 
                (up[i][j & 1] += (down[i - 1][j - 1] * (((a[i - 1] - 1) * p[i - 1]) % MOD)) % MOD) %= MOD; 
        }
        lp(i, 1, n){
            up[i][~j & 1] = 0;
            if(j > n + i - 2) continue;
            (cnt_up += (numNode[i] * up[i][j & 1]) % MOD) %= MOD;
            if(j < n) (cnt_down += (numNode[i] * down[i][j]) % MOD) %= MOD;
        }
        cout << (((cnt_up + cnt_down) % MOD) * p2) % MOD << ' ';
    }
}