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

cll maxk = 55;
ll f[55][55], n, k, m, a[maxk];

ll sol(ll q, ll ma){
    if(q > k){
        f[q][ma] = 1;
        return 1;
    }
    if(f[q][ma] > -1) return f[q][ma];
    ll cnt = 0;
    lp(i, ma + 1, n){
        ll nma = i;
        if(k - q > n - ma) break;
        cnt += sol(q + 1, nma);
    }
    f[q][ma] = cnt;
    return cnt;
}

void get_tt(ll q, ll ma, ll down){
    if(q > k){
        // f[q][ma] = 1;
        return;
    }
    // if(f[q][ma] > -1) return f[q][ma];
    // ll cnt = 0;
    lp(i, ma + 1, n){
        ll nma = i;
        if(k - q > n - ma) break;
        // cnt += sol(q + 1, nma);
        ll tmp = f[q + 1][nma];
        if(m + 1 <= tmp + down){
            a[q] = i;
            get_tt(q + 1, nma, down);
            break;
        }
        down += tmp;
    }
    // f[q][ma] = cnt;
    // return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n >> k >> m;
    memset(f, -1, sizeof(f));
    // cerr << sol(1, 0);
    sol(1, 0);
    get_tt(1, 0, 0);
    lp(i, 1, k) cout << a[i] << ' ';
}