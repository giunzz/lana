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

cll maxn = 20, maxk = 1e5;
ll n, tt, a[maxn], f[maxn][maxn][maxn][maxn] = {{0}}, stt = 0, ans[maxn];

ll sol(ll q, ll mi1, ll mi2, ll ma){
    if(q > n) return 1;
    if(f[q][mi1][mi2][ma] > -1) return f[q][mi1][mi2][ma];
    ll cnt = 0;
    lp(i, 1, n){
        ll nmi1 = mi1, nmi2 = mi2, nma = ma;
        if(i < nmi1) nmi2 = mi1, nmi1 = i;
        else if(i < nmi2) nmi2 = i;
        if(i > nma) nma = i;
        if(nmi1 + nmi2 > nma){
            cnt += sol(q + 1, nmi1, nmi2, nma);
        }
    }
    f[q][mi1][mi2][ma] = cnt;
    return cnt;
}

void gt(ll q, ll mi1, ll mi2, ll ma, ll down){
    // ll pre = 0;
    // ll cnt = 0;
    if(q > n) return;
    lp(i, 1, n){
        ll nmi1 = mi1, nmi2 = mi2, nma = ma;
        if(i < nmi1) nmi2 = mi1, nmi1 = i;
        else if(i < nmi2) nmi2 = i;
        if(i > nma) nma = i;
        if(nmi1 + nmi2 > nma){
            ll tmp = f[q + 1][nmi1][nmi2][nma];
            // ++cnt;
            // if(q == n) cerr << down << ' ';
            if(tt <= tmp + down){
                // cerr << q + 1 << ' ' << nmi1 << ' ' << nmi2 << ' ' << nma <<  ' ' << f[q + 1][nmi1][nmi2][nma] << '\n';
                ans[q] = i;
                // tt -= pre;
                gt(q + 1, nmi1, nmi2, nma, down);
                break;
            }
            down += tmp;
        }
    }
}

ll get_tt(ll q, ll mi1, ll mi2, ll ma){
    ll pre = 0, cnt = 0;
    if(q > n) return 0;
    lp(i, 1, n){
        ll nmi1 = mi1, nmi2 = mi2, nma = ma;
        if(i < nmi1) nmi2 = mi1, nmi1 = i;
        else if(i < nmi2) nmi2 = i;
        if(i > nma) nma = i;
        if(nmi1 + nmi2 > nma){
            ll tmp = f[q + 1][nmi1][nmi2][nma];
            ++cnt;
            if(q == n && i == a[q]) return cnt;
            if(i == a[q]){
                return pre + get_tt(q + 1, nmi1, nmi2, nma); 
            }
            pre += tmp;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    memset(f, -1, sizeof(f));
    cin >> n >> tt;
    lp(i, 1, n) cin >> a[i];
    cout << sol(1, n + 1, n + 1, 0) << '\n';
    lp(i, 1, n) lp(j, 1, n) lp(k, 1, n)
        f[n + 1][i][j][k] = 1;
    gt(1, n + 1, n + 1, 0, 0);
    lp(i, 1, n) cout << ans[i] << ' ';
    cout << '\n';
    cout << get_tt(1, n + 1, n + 1, 0);
}

/* 
    kiem tra bo 2 so nho nhat va so lon nhat
*/