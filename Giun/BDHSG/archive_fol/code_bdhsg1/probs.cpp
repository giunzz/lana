/*
    lam y nhu sweets3
    them bien ok_i kiem tra doan dau x_i va x_i+1 co = nhau (0) hoac be hon (1)
    chay tu dau den cuoi
    tinh theo cot for i tu 1 den 2 ^ k -1 xong tach ra tung so
*/

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

cll maxDg = 32, MOD = 1e9 + 7;
ll n, k, f[maxDg + 1][100][100];
vec(ll) bn;

ll countbito(ll u){
    if(u == 0) return 0;
    return (u & 1) + countbito(u >> 1);
}

ll sol(ll q, ll car, ll stt){
    if(q == maxDg){
        cerr << q << ' ' << car << ' ' << stt <<'\n';
        return car == 0 && stt == (1 << (k - 1)) - 1;
    }
    if(f[q][car][stt] > -1) return f[q][car][stt];
    ll cnt = 0, num = (car << 1) | bn[q];
    lp(i, 0, (1 << k) - 1){
        ll tmp = countbito(i), nstt = stt;
        // if((tmp >> 1) != car || (tmp & 1) != bn[q]) continue;
        ll tcar = num - tmp;
        // cerr << tcar << ' ';
        bool ok = 1;
        if(tcar < 0) continue;
        lp(j, 0, k - 2){
            ll b1 = (i >> j) & 1, b2 = (i >> (j + 1)) & 1, tt = (stt >> j) & 1;
            if(!tt){
                if(b1 > b2) {ok = 0; break;}
                if(b1 < b2){
                    nstt = nstt | (1 << j);
                }
            }
        }  
        if(ok) cnt = (cnt + sol(q + 1, tcar, nstt)) % MOD;
    }
    f[q][car][stt] = cnt;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> k;
    memset(f, -1, sizeof(f));
    bn.push_back(0);
    while(n) bn.push_back(n & 1), n >>= 1;
    while(bn.size() <= maxDg) bn.push_back(0);
    reverse(bn.begin(), bn.end());
    // for(ll i : bn) cerr << i;
    cout << sol(0, 0, 0);
}