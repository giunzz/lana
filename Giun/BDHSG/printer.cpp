#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e6 + 7;
ll n, f[maxn][30], Nnode = 0, cntE = 0, cntFrLf[maxn] = {0};
string s;

inline ll asc(char c){
    return c - '0';
}

void push(){
    ll cur = 0, cntw = 0;
    lp(i, 0, s.size() - 1){
        if(f[cur][asc(s[i])] == -1){
            f[cur][asc(s[i])] = ++Nnode;
            ++cntE;
        }
        cur = f[cur][asc(s[i])];
        ++cntw;
    }
    cntFrLf[cur] = cntw;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n;
    memset(f, -1, sizeof(f));
    lp(i, 1, n){
        cin >> s;
        push();
    }
    ll ma = 0;
    lp(i, 0, Nnode){
        ma = max(ma, cntFrLf[i]);
    }
    cout << (cntE * 2 - ma + n);
}