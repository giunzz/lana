#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 20;
ll n, m, k, a[maxn], c[maxn][maxn] = {{0}}, f[(1LL << 20)][20], ans = 0;

ll countbito(ll u){
    if(u == 0) return 0;
    return (u & 1) + countbito(u >> 1);
}

ll dp(ll mask, ll pos){
    if(countbito(mask) == 1) return a[pos];
    if(f[mask][pos] != -1) return f[mask][pos];
    ll tmp = 0;
    lp(i, 0, n - 1){
        if(i == pos) continue;
        if((1LL << i) & mask){
            tmp = max(tmp, dp((1LL << pos) ^ mask, i) + c[i][pos] + a[pos]);
        }
    }
    f[mask][pos] = tmp;
    return tmp;
}

void gene(ll pos, ll cnt, ll pd){
    if(pos >= n && cnt == m){
        lp(i, 0, n - 1){
            if(~(pd >> i) & 1) continue;
            // cerr << pd << ' ' << i << '\n';
            lp(j, 0, n - 1){
                if(i == j) continue;
                if((pd >> j) & 1) ans = max(dp((1LL << i) ^ pd, j) + c[j][i] + a[i], ans);
            }
        }
        return;
    }
    if(pos >= n) return;
    lp(i, 0, 1){
        ll ncnt = cnt, npd = pd;
        if(i == 1 && cnt < m){
            npd = pd ^ (1LL << pos);
            ++ncnt;
            gene(pos + 1, ncnt, npd);
        }
        else if(i == 0) 
            gene(pos + 1, ncnt, npd);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m >> k;
    lp(i, 0, n - 1) cin >> a[i];
    lp(i, 1, k){
        ll x, y, t;
        cin >> x >> y >> t;
        c[x - 1][y - 1] = t;
    }
    if(m == 1){
        lp(i, 0, n - 1) ans = max(a[i], ans);
        cout << ans;
        return 0;
    }
    ll stt = (1LL << n) - 1;
    memset(f, -1, sizeof(f));
    gene(0, 0, 0);
    cout << ans;
}