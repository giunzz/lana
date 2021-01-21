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

ll n;
string s;
vec(ll) b, tg;

ll sol(ll q, ll s){
    if(q > n){
        return s != tg.size();
    }
    // ll j = s - 1, next = j + 1;
    ll cnt = 0;
    lp(i, 0, 1){
        if(i == tg[s] && s != tg.size() - 1){
            cnt += sol(q + 1, s + 1);
        }
        else if(i != tg[s]){
            cnt += sol(q + 1, 0);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    while(cin >> n >> s){
        tg.clear();
        b.clear();
        b.resize(n);
        for(char c : s){
            tg.push_back(c - '0');
        }
        cout << sol(1, 0) << '\n';
    }
}